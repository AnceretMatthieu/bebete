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
    model_tvQuestion = new QStandardItemModel(0, 0);
    model_tvReponse = new QStandardItemModel;
    model_tvMediaQuestion = new QStandardItemModel;

    peuplerListeQuestionsXML(maListeQuestions, NULL, 0);

    /* Création des actions */
    createAction();

    ui->setupUi(this);

    ui->treeViewQuestion->header()->hide();
    ui->treeViewQuestion->setModel(model_tvQuestion);
    ui->treeViewQuestion->setEditTriggers(QAbstractItemView::NoEditTriggers); // on empeche la modification

    ui->treeViewReponse->header()->hide();
    ui->treeViewReponse->setModel(model_tvReponse);

    ui->treeViewMediasQuestion->header()->hide();
    ui->treeViewMediasQuestion->setModel(model_tvMediaQuestion);

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

void MainWindow::peuplerListeQuestionsXML(ListeQuestion * uneListeQuestions, QStandardItem * pere, int nbPere)
{
    for(int i = 0; i < uneListeQuestions->size(); i++)
    {
        Question * q = uneListeQuestions->at(i);
        QStandardItem * elem = new QStandardItem(greenIcon, q->getQuestion());

        if(pere == NULL) // pour le cas ou les questions n'ont pas de père
        {
            model_tvQuestion->appendRow(elem);
            nbPere = 0;
        }
        else
        {
            pere->appendRow(elem);
            nbPere++;
        }

        // On ajoute les "coordonnées" de la question dans le TreeView dans une map
        QString coordonnees = QString::number(nbPere) + "-" + QString::number(elem->index().row());
        //qDebug() << "Coordonées question " << q->getQuestion() << " : " << coordonnees;
        mapTreeQuestions.insert(coordonnees, q);

        // pour chaque réponse de la question courante
        ListeReponse * lr = q->getListeReponse();
        for(int j = 0; j < lr->size(); j++)
        {
            if(lr->at(j)->getTypeSuiv() == TYPE_CATEGORIE) // c'est une catégorie
            {
                ListeQuestion * lq = ((Categorie *)(lr->at(j)->getSuiv()))->getListeQuestion();
                peuplerListeQuestionsXML(lq, elem, nbPere);
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
    // On commence par vider le contenu des TreeView
    model_tvReponse->clear();
    model_tvMediaQuestion->clear();

    // On calcul la profondeur de l'item cliqué
    int profondeur = 0;
    QModelIndex currentIndex = index.parent();
    while(currentIndex != QModelIndex())
    {
        currentIndex = currentIndex.parent();
        profondeur++;
    }

    /*
        index.row() ==> correspond au 2ème chiffre dans la map
        profondeur ==> correspond au 1er chiffre dans la map
    */

    // On peut donc construire les coordonées de l'item selectionné
    QString coordonnees = QString::number(profondeur) + "-" + QString::number(index.row());
    //qDebug() << "Coordonnées : " << coordonnees;

    // On affiche le texte de la question
    QString texte = model_tvQuestion->itemFromIndex(index)->text();
    ui->labelQuestion->setText(texte);

    // On récupère, via la QMap, la question correpondant à l'item cliqué
    Question * currentQuestion = mapTreeQuestions.value(coordonnees);
    ListeReponse * lr = currentQuestion->getListeReponse();

    for(int i = 0; i < lr->size(); i++)
    {
        Reponse * r = lr->at(i);
        QStandardItem * elemRep = new QStandardItem(r->getReponse());
        model_tvReponse->appendRow(elemRep);
    }

    // On coche les cases "visible"
    if(currentQuestion->getVisible() == "true")
    {
        ui->checkBoxVisibleOeil->setChecked(true);
        ui->checkBoxVisibleLoupe->setChecked(false);
    }
    else if(currentQuestion->getVisible() == "false")
    {
        ui->checkBoxVisibleOeil->setChecked(false);
        ui->checkBoxVisibleLoupe->setChecked(true);
    }
    else if(currentQuestion->getVisible() == "both")
    {
        ui->checkBoxVisibleOeil->setChecked(true);
        ui->checkBoxVisibleLoupe->setChecked(true);
    }
    else
    {
        qDebug() << "Erreur : l'élément \"visible\" ne possède pas une valeur correcte.";
    }

    // On récupère les médias associés à la question
    ListeMedia * lm = currentQuestion->getListeMedia();

    // TODO : améliorer la façon d'afficher les médias
    for(int i = 0; i < lm->size(); i++)
    {
        Media * m = lm->at(i);
        QStandardItem * elemMed = new QStandardItem(m->getPath());
        model_tvMediaQuestion->appendRow(elemMed);
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
    // Ouvrir une fenêtre qui demande le nom de la question à insérer

    QModelIndex index = ui->treeViewQuestion->currentIndex(); // on récupère l'index de la selection
    QStandardItem * parentSelection = model_tvQuestion->itemFromIndex(index); // on récupère le parent de la selection

    QStandardItem * elem = new QStandardItem(greenIcon, "Question i");

    if (parentSelection->parent() != 0)
    {
        parentSelection->insertRow(index.row() + 1, elem);
        //parentSelection->appendRow(elem);
    }
    else
    {
        model_tvQuestion->insertRow(index.row() + 1 , elem);
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
    model_tvQuestion->removeRow(index.row(), index.parent());
}
