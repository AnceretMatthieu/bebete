#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /* Initialisation des icones */
    greenIcon = QIcon("images/icon_green.png");
    yellowIcon = QIcon("images/icon_yellow.png");
    redIcon = QIcon("images/icon_red.png");

    // parsage de l'arbre
    maListeQuestions = CategorieBDD::CreerArbre();

    /* Peuplement des TreeView */
    model = new QStandardItemModel(0, 0);
    model2 = new QStandardItemModel;

    peuplerListeQuestionsXML(maListeQuestions, NULL);

    /* Cr�ation des actions */
    createAction();

    ui->setupUi(this);

    ui->treeViewQuestion->header()->hide();
    ui->treeViewQuestion->setModel(model);
    ui->treeViewQuestion->setEditTriggers(QAbstractItemView::NoEditTriggers); // on empeche la modification

    ui->treeViewReponse->header()->hide();
    ui->treeViewReponse->setModel(model2);

    /* Mise en place du style CSS et application sur le widget QTreeView des questions */
    QFile styleFile("style_qtreeview.css");
    styleFile.open(QFile::ReadOnly);

    QString style(styleFile.readAll());
    ui->treeViewQuestion->setStyleSheet(style);

    /* Affectation des actions aux boutons du menu */
    connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(on_actionApropos()));

    /* On g�re le click sur le TreeView des questions */
    connect(ui->treeViewQuestion, SIGNAL(clicked(QModelIndex)), this, SLOT(on_clickTreeViewQuestions(QModelIndex)));

    /* Clic droit sur le TreeView des questions */
    connect(ui->treeViewQuestion, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(treeQuestionsContextMenu(const QPoint&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::peuplerListeQuestionsXML(ListeQuestion * uneListeQuestions, QStandardItem * pere)
{
    for(int i = 0; i < uneListeQuestions->size(); i++)
    {
        Question * q = uneListeQuestions->at(i);
        QStandardItem * elem = new QStandardItem(greenIcon, q->getQuestion());

        if(pere == NULL) // pour le cas ou les questions n'ont pas de p�re (c'est les premi�res)
        {
            model->appendRow(elem);
        }
        else
        {
            pere->appendRow(elem);
        }

        // Calcul du nombre de p�re
        int nbPere = 0;
        while(q->getCat()->getReponse() != NULL)
        {
             nbPere++;
             qDebug() << nbPere;
             q = (Question*)q->getCat()->getReponse()->getPrec();
        }

        QString coordonnees = nbPere + "-" + QString::number(i);
        qDebug() << coordonnees;
        mapTreeQuestions.insert(coordonnees, q);

        // pour chaque r�ponse de la question courante
        ListeReponse * lr = q->getListeReponse();
        for(int j = 0; j < lr->size(); j++)
        {
            if(lr->at(j)->getTypeSuiv() == TYPE_CATEGORIE) // c'est une cat�gorie
            {
                ListeQuestion * lq = ((Categorie *)(lr->at(j)->getSuiv()))->getListeQuestion();
                peuplerListeQuestionsXML(lq, elem);
            }
        }
    }
}

void MainWindow::createAction()
{
    addQuestion = new QAction(tr("Ajouter une question"), this);
    connect(addQuestion, SIGNAL(triggered()), this, SLOT(newQuestion()));

    modifQuestion = new QAction(tr("Modifier"), this);
    connect(modifQuestion, SIGNAL(triggered()), this, SLOT(modifierQuestion()));

    delQuestion = new QAction(tr("Supprimer"), this);
    connect(delQuestion, SIGNAL(triggered()), this, SLOT(supprimerQuestion()));
}

void MainWindow::on_actionImporter_XML_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir le fichier de base de donnees"), QDir::currentPath(), tr("Fichier XML (*.xml)"));
    std::cout << "Nom du fichier selectionne : " << qPrintable(fileName) << std::endl;

    // il faut ensuite appeler la fonction pour parser (lire) le fichier XML
}

void MainWindow::on_actionExporter_XML_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir le fichier de base de donnees"), QDir::currentPath(), tr("Fichier XML (*.xml)"));
    std::cout << "Nom du fichier selectionne : " << qPrintable(fileName) << std::endl;

    // il faut ensuite appeler la fonction pour ecrire le fichier XML
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionApropos()
{
    AboutWindow aboutWin;
    aboutWin.exec();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int reponse = QMessageBox::question(this, "Quitter", "Etes-vous sur(e) de vouloir quitter ?", QMessageBox::Yes | QMessageBox::No);

    if(reponse == QMessageBox::Yes) {
        event->accept();
    }
    else if (reponse == QMessageBox::No) {
        event->ignore();
    }
}

void MainWindow::on_clickTreeViewQuestions(const QModelIndex &index)
{
    model2->clear();

    QString texte = model->itemFromIndex(index)->text();
    ui->labelQuestion->setText(texte);

    // au clic sur une question du TreeView des questions, il faut aussi afficher les m�dias associ�s � cette question ainsi que
    // les r�ponses

    Question * q = maListeQuestions->at(index.row());
    ListeReponse * uneListeReponse = q->getListeReponse();

    for(int j = 0; j < uneListeReponse->size(); j++)
    {
        Reponse * r = uneListeReponse->at(j);
        QStandardItem * elem = new QStandardItem(r->getReponse());
        model2->appendRow(elem);
    }
}

void MainWindow::treeQuestionsContextMenu(const QPoint &pos)
{
    QMenu menu(this);
    menu.addAction(addQuestion);
    menu.addAction(modifQuestion);
    menu.addAction(delQuestion);
    menu.exec(pos);
}

void MainWindow::newQuestion()
{
    // Ouvrir une fen�tre qui demande le nom de la question � ins�rer

    QModelIndex index = ui->treeViewQuestion->currentIndex(); // on r�cup�re l'index de la selection
    QStandardItem * parentSelection = model->itemFromIndex(index); // on r�cup�re le parent de la selection

    QStandardItem * elem = new QStandardItem(greenIcon, "Question i");

    if (parentSelection->parent() != 0)
    {
        parentSelection->insertRow(index.row() + 1, elem);
        //parentSelection->appendRow(elem);
    }
    else
    {
        model->insertRow(index.row() + 1 , elem);
        //model->appendRow(elem);
    }
}

void MainWindow::modifierQuestion()
{
    // Il faut envoyer les param�tres de l'item courant � la fen�tre pour pouvoir afficher les infos (texte de la question, ...)

    QModelIndex index = ui->treeViewQuestion->currentIndex();

    ModifQuestionWindow * myWindow = new ModifQuestionWindow(index, this);
    myWindow->setModal(true);
    myWindow->show();
}

void MainWindow::supprimerQuestion()
{
    // Peut-�tre demander confirmation avant de supprimer une question ? (surtout dans le cas ou la question poss�de des fils)

    QModelIndex index = ui->treeViewQuestion->currentIndex();
    model->removeRow(index.row(), index.parent());
}
