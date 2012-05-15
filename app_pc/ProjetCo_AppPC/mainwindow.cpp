#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /* Initialisation des icones */
    greenIcon = QIcon("images/icon_green.png");
    yellowIcon = QIcon("images/icon_yellow.png");
    redIcon = QIcon("images/icon_red.png");

    /* Peuplement des TreeView */
    peuplerListeQuestions();
    peuplerListeReponses();

    /* Création des actions */
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

    /* On gère le click sur le TreeView des questions */
    connect(ui->treeViewQuestion, SIGNAL(clicked(QModelIndex)), this, SLOT(on_clickTreeViewQuestions(QModelIndex)));

    /* Clic droit sur le TreeView des questions */
    connect(ui->treeViewQuestion, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(treeQuestionsContextMenu(const QPoint&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::peuplerListeQuestions()
{
    // Pour le TreeView des questions, il faut voir si l'on affiche toutes les questions ou si l'on affiche les questions au fur et à mesure

    /* Remplissage TreeView des questions */
    model = new QStandardItemModel(0, 0);

    QStandardItem * elem1 = new QStandardItem(greenIcon, "Question 1");
    elem1->appendRow(new QStandardItem(greenIcon, "Question 1.1"));
    elem1->appendRow(new QStandardItem(yellowIcon, "Question 1.2"));
    model->appendRow(elem1);

    QStandardItem * elem2 = new QStandardItem(redIcon, "Question 2");
    elem2->appendRow(new QStandardItem(greenIcon, "Question 2.1"));
    QStandardItem * elem22 = new QStandardItem(greenIcon, "Question 2.2");
    elem22->appendRow(new QStandardItem(greenIcon, "Question 2.2.1"));
    elem22->appendRow(new QStandardItem(greenIcon, "Question 2.2.2"));
    elem2->appendRow(elem22);
    elem2->appendRow(new QStandardItem(yellowIcon, "Question 2.3"));
    model->appendRow(elem2);

    QStandardItem * elem3 = new QStandardItem(yellowIcon, "Question 3");
    elem3->appendRow(new QStandardItem(redIcon, "Question 3.1"));
    elem3->appendRow(new QStandardItem(redIcon, "Question 3.2"));
    elem3->appendRow(new QStandardItem(greenIcon, "Question 3.3"));
    model->appendRow(elem3);

    /*QStandardItem * root = new QStandardItem("Racine de l'arbre");
    root->appendRow(elem1);
    root->appendRow(elem2);
    root->appendRow(elem3);
    model->appendRow(root);*/
}

void MainWindow::peuplerListeReponses()
{
    /* Remplissage TreeView des reponses */
    model2 = new QStandardItemModel;

    QStandardItem * elem4 = new QStandardItem("Reponse 1");
    model2->appendRow(elem4);

    QStandardItem * elem5 = new QStandardItem("Reponse 2");
    model2->appendRow(elem5);

    QStandardItem * elem6 = new QStandardItem("Reponse 3");
    model2->appendRow(elem6);
    elem6->appendRow(new QStandardItem("aide reponse 3"));
    elem6->appendRow(new QStandardItem("media 1"));
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
    QString texte = model->itemFromIndex(index)->text();
    ui->labelQuestion->setText(texte);

    // au clic sur une question du TreeView des questions, il faut aussi afficher les médias associés à cette question ainsi que
    // les réponses
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
    // Ouvrir une fenêtre qui demande le nom de la question à insérer

    QModelIndex index = ui->treeViewQuestion->currentIndex(); // on récupère l'index de la selection
    QStandardItem * parentSelection = model->itemFromIndex(index); // on récupère le parent de la selection

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
    // Il faut envoyer les paramètres de l'item courant à la fenêtre pour pouvoir afficher les infos (texte de la question, ...)

    QModelIndex index = ui->treeViewQuestion->currentIndex();

    ModifQuestionWindow * myWindow = new ModifQuestionWindow(index, this);
    myWindow->setModal(true);
    myWindow->show();
}

void MainWindow::supprimerQuestion()
{
    // Peut-être demander confirmation avant de supprimer une question ? (surtout dans le cas ou la question possède des fils)

    QModelIndex index = ui->treeViewQuestion->currentIndex();
    model->removeRow(index.row(), index.parent());
}
