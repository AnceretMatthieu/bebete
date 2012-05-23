#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /* Initialisation des icones */
    greenIcon = QIcon("images/icon_green.png");
    yellowIcon = QIcon("images/icon_yellow.png");
    redIcon = QIcon("images/icon_red.png");

    // TODO : à supprimer ; se trouve désormais dans la fonction du menu "Importer XML"
    maListeQuestions = CategorieBDD::CreerArbre(QDir::currentPath() + "/accueil.xml");

    /* Peuplement des TreeView */
    model_tvQuestion = new QStandardItemModel(0, 0);
    model_tvReponse = new QStandardItemModel;
    model_tvMediaQuestion = new QStandardItemModel;

    // TODO : à supprimer ; se trouve désormais dans la fonction du menu "Importer XML"
    peuplerListeQuestionsXML(maListeQuestions, NULL, 0);

    ui->setupUi(this);

    ui->treeViewQuestion->header()->hide();
    ui->treeViewQuestion->setModel(model_tvQuestion);
    ui->treeViewQuestion->setEditTriggers(QAbstractItemView::NoEditTriggers); // on empeche la modification

    ui->treeViewReponse->header()->hide();
    ui->treeViewReponse->setModel(model_tvReponse);
    ui->treeViewReponse->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->treeViewMediasQuestion->header()->hide();
    ui->treeViewMediasQuestion->setModel(model_tvMediaQuestion);
    ui->treeViewMediasQuestion->setEditTriggers(QAbstractItemView::NoEditTriggers);

    /* Mise en place du style CSS et application sur le widget QTreeView des questions */
    QFile styleFile("style_qtreeview.css");
    styleFile.open(QFile::ReadOnly);

    QString style(styleFile.readAll());
    ui->treeViewQuestion->setStyleSheet(style);

    /* Création des actions */
    createAction();
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
        QStandardItem * elem;

        // Permet de déterminer la couleur
        if(q->getListeMedia()->size() < 1)
        {
            elem = new QStandardItem(redIcon, q->getQuestion());
        }
        else
        {
            if(q->getListeMedia()->size() < 2)
            {
                elem = new QStandardItem(yellowIcon, q->getQuestion());
            }
            else
            {
                elem = new QStandardItem(greenIcon, q->getQuestion());
            }
        }

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

    addReponse = new QAction(tr("Ajouter une réponse"), this);
    connect(addReponse, SIGNAL(triggered()), this, SLOT(newReponse()));

    modifReponse = new QAction(tr("Modifier"), this);
    connect(modifReponse, SIGNAL(triggered()), this, SLOT(modifierReponse()));

    delReponse = new QAction(tr("Supprimer"), this);
    connect(delReponse, SIGNAL(triggered()), this, SLOT(supprimerReponse()));

    /* Affectation des actions aux boutons du menu */
    connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(on_actionApropos()));

    /* On gère le click sur le TreeView des questions */
    connect(ui->treeViewQuestion, SIGNAL(clicked(QModelIndex)), this, SLOT(on_clickTreeViewQuestions(QModelIndex)));

    /* Clic droit sur le TreeView des questions */
    connect(ui->treeViewQuestion, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(treeQuestionsContextMenu(const QPoint&)));

    /* Clic droit sur le TreeView des réponses */
    connect(ui->treeViewReponse, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(treeReponsesContextMenu(const QPoint&)));

    /* Clic sur le TreeView des médias d'une question */
    connect(ui->treeViewMediasQuestion, SIGNAL(clicked(QModelIndex)), this, SLOT(on_clickTreeViewMediasQuestions(QModelIndex)));
}

void MainWindow::on_actionImporter_XML_triggered()
{
    // TODO : peut-être penser à vider tous les TreeView & Co avant d'importer un nouvel arbre ;
    // peut-être proposer aussi d'enregistrer le travail courant

    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir le fichier de base de données"), QDir::currentPath(), tr("Fichier XML (*.xml)"));

    // Parsage de l'arbre
    maListeQuestions = CategorieBDD::CreerArbre(fileName);

    // Remplissage des TreeView
    peuplerListeQuestionsXML(maListeQuestions, NULL, 0);
}

void MainWindow::on_actionExporter_XML_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir le fichier de base de donnees"), QDir::currentPath(), tr("Fichier XML (*.xml)"));

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
    qDebug() << "Coordonnées : " << coordonnees;

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

    // Gestion de l'attribut "visible" de la balise "Question" ==> on coche/décoche les checkbox
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
        ui->checkBoxVisibleOeil->setChecked(false);
        ui->checkBoxVisibleLoupe->setChecked(false);
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

void MainWindow::on_clickTreeViewMediasQuestions(const QModelIndex &index)
{
    // Il faudrait tester le type du média qui a été selectionné

    QString pathImg = model_tvMediaQuestion->itemFromIndex(index)->text();

    QImage * myImg = new QImage(pathImg);
    if(myImg->isNull() != true)
    {
        // Il faudrait réfléchir à la méthode de redimensionnement de l'image
        // TODO : en cliquant sur l'image, il serait bien qu'elle puisse s'ouvrir en plein écran dans une nouvelle fenêtre
        QImage myScaledImg = myImg->scaled(QSize(250, 250), Qt::KeepAspectRatio);

        QPixmap * img = new QPixmap();
        img->convertFromImage(myScaledImg, Qt::AutoColor);

        ui->labelImage->setPixmap(*img);
    }
    else
    {
        ui->labelImage->setText("Ce média n'est pas une image.");
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

void MainWindow::treeReponsesContextMenu(const QPoint &pos)
{
    QMenu menu(this);
    menu.addAction(addReponse);
    menu.addAction(modifReponse);
    menu.addAction(delReponse);
    menu.exec(pos);
}

void MainWindow::newQuestionFils()
{
    // TODO : Ouvrir une fenêtre qui demande le nom de la question à insérer

    QModelIndex index = ui->treeViewQuestion->currentIndex(); // on récupère l'index de la selection
    QStandardItem * parentSelection = model_tvQuestion->itemFromIndex(index); // on récupère le parent de la selection

    QStandardItem * elem = new QStandardItem(greenIcon, "Ceci est une nouvelle question"); // on crée un élém bidon à insérer

    // on calcul les coordonnées du noeud courant
    int profondeur = 0;
    QModelIndex currentIndex = index.parent();
    while(currentIndex != QModelIndex())
    {
        currentIndex = currentIndex.parent();
        profondeur++;
    }
    QString coordonnees = QString::number(profondeur) + "-" + QString::number(index.row());
    Question * currentQuestion = mapTreeQuestions.value(coordonnees); // on récupère la question courante

    // On récupère le nombre de frère de la question
    int nbFrere = currentQuestion->getCat()->getListeQuestion()->size();

    if (parentSelection->parent() != 0) // si l'élément selectionné n'est pas un élément racine
    {
        parentSelection->insertRow(nbFrere, elem);
        //parentSelection->appendRow(elem);

        profondeur++;
        // TODO : problème au niveau du 2ème paramètre
        QString coordonnees2 = QString::number(profondeur) + "-" + QString::number(0);
        qDebug() << "coordonnees2 : " + coordonnees2;

        Question * q = new Question(1);
        q->setQuestion("Ceci est une nouvelle question");
        q->setVisible("true");
        currentQuestion->getCat()->ajouterQuestion(q);

        mapTreeQuestions.insert(coordonnees2, q);
    }
    else
    {
        model_tvQuestion->insertRow(index.row() + 1 , elem);
        //model->appendRow(elem);

        Question * q = new Question(1);
        q->setQuestion("Ceci est une nouvelle question");
        q->setVisible("true");
        currentQuestion->getCat()->ajouterQuestion(q);
    }
}

void MainWindow::newQuestionFrere()
{
    // TODO : Ouvrir une fenêtre qui demande le nom de la question à insérer

    QModelIndex index = ui->treeViewQuestion->currentIndex(); // on récupère l'index de la selection
    QStandardItem * parentSelection = model_tvQuestion->itemFromIndex(index); // on récupère le parent de la selection

    QStandardItem * elem = new QStandardItem(greenIcon, "Ceci est une nouvelle question"); // on crée un élém bidon à insérer

    // on calcul les coordonnées du noeud courant
    int profondeur = 0;
    QModelIndex currentIndex = index.parent();
    while(currentIndex != QModelIndex())
    {
        currentIndex = currentIndex.parent();
        profondeur++;
    }
    QString coordonnees = QString::number(profondeur) + "-" + QString::number(index.row());
    Question * currentQuestion = mapTreeQuestions.value(coordonnees); // on récupère la question courante

    // On récupère le nombre de frère de la question
    int nbFrere = currentQuestion->getCat()->getListeQuestion()->size();

    if (parentSelection->parent() != 0) // si l'élément selectionné n'est pas un élément racine
    {
        parentSelection->insertRow(nbFrere, elem); // ou insertRow()

        profondeur++;
        // TODO : problème au niveau du 2ème paramètre
        QString coordonnees2 = QString::number(profondeur) + "-" + QString::number(nbFrere);
        qDebug() << "coordonnees2 : " + coordonnees2;

        Question * q = new Question(1);
        q->setQuestion("Ceci est une nouvelle question");
        q->setVisible("true");
        currentQuestion->getCat()->ajouterQuestion(q);

        mapTreeQuestions.insert(coordonnees2, q);
    }
    else
    {
        model_tvQuestion->insertRow(index.row() + 1, elem);

        Question * q = new Question(1);
        q->setQuestion("Ceci est une nouvelle question");
        q->setVisible("true");
        currentQuestion->getCat()->ajouterQuestion(q);
    }
}

void MainWindow::modifierQuestion()
{
    // Il faut envoyer les paramètres de l'item courant à la fenêtre pour pouvoir afficher les infos (texte de la question, ...)

    QModelIndex index = ui->treeViewQuestion->currentIndex();
    int profondeur = 0;
    QModelIndex currentIndex = index.parent();
    while(currentIndex != QModelIndex())
    {
        currentIndex = currentIndex.parent();
        profondeur++;
    }

    QString coordonnees = QString::number(profondeur) + "-" + QString::number(index.row());
    Question * currentQuestion = mapTreeQuestions.value(coordonnees);

    myWindow = new ModifQuestionWindow(currentQuestion, this);

    myWindow->setModal(true);
    myWindow->exec();
}

void MainWindow::supprimerQuestion()
{
    // Peut-être demander confirmation avant de supprimer une question ? (surtout dans le cas ou la question possède des fils)

    QModelIndex index = ui->treeViewQuestion->currentIndex();
    model_tvQuestion->removeRow(index.row(), index.parent());
}

void MainWindow::newReponse()
{

}

void MainWindow::modifierReponse()
{

}

void MainWindow::supprimerReponse()
{

}
