#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /* Initialisation des icones */
    greenIcon = QIcon("images/icon_green.png");
    yellowIcon = QIcon("images/icon_yellow.png");
    redIcon = QIcon("images/icon_red.png");

    // TODO : penser à vérifier que la structure des dossiers de médias est correctement créé
    // Si ce n'est pas le cas, le faire.

    // TODO : à supprimer ; se trouve désormais dans la fonction du menu "Importer XML"
    maListeQuestions = CategorieBDD::CreerArbre(QDir::currentPath() + "/accueil.xml");

    /* Peuplement des TreeView */
    // TODO : il faudrait que le TreeView des réponses et celui des médiasQuestions soient composés de 2 colonnes : une pour le type et l'autre pour le contenu
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
    /* Affectation des actions sur les menus contextuels */
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

    /* Affectation de l'action au bouton "A propos" du menu */
    connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(on_actionApropos()));

    /* Gestion du clic sur les items */
    connect(ui->treeViewQuestion, SIGNAL(clicked(QModelIndex)), this, SLOT(on_clickTreeViewQuestions(QModelIndex)));
    connect(ui->treeViewReponse, SIGNAL(clicked(QModelIndex)), this, SLOT(on_clickTreeViewReponse(QModelIndex)));
    connect(ui->treeViewMediasQuestion, SIGNAL(clicked(QModelIndex)), this, SLOT(on_clickTreeViewMediasQuestions(QModelIndex)));

    /* Gestion du clic droit */
    connect(ui->treeViewQuestion, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(treeQuestionsContextMenu(const QPoint&)));
    connect(ui->treeViewReponse, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(treeReponsesContextMenu(const QPoint&)));

    /* Affectation des actions aux boutons des questions */
    connect(ui->button_addQuestionFils, SIGNAL(clicked()), this, SLOT(newQuestionFils()));
    connect(ui->button_addQuestionFrere, SIGNAL(clicked()), this, SLOT(newQuestionFrere()));
    connect(ui->button_modifierQuestion, SIGNAL(clicked()), this, SLOT(modifierQuestion()));
    connect(ui->button_supprimerQuestion, SIGNAL(clicked()), this, SLOT(supprimerQuestion()));

    /* Affectation des actions aux boutons des réponses */
    connect(ui->button_ajouterReponse, SIGNAL(clicked()), this, SLOT(newReponse()));
    connect(ui->button_modifierReponse, SIGNAL(clicked()), this, SLOT(modifierReponse()));
    connect(ui->button_supprimerReponse, SIGNAL(clicked()), this, SLOT(supprimerReponse()));

    /* Affectation des actions aux boutons des médias des questions */
    // ..

    /* Affectation des actions aux boutons des médias des réponses */
    // ..
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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Enregistrer le fichier de base de donnees"), QDir::currentPath(), tr("Fichier XML (*.xml)"));

    Categorie * categorie = new Categorie(1);
    if(maListeQuestions->size() != 0)
    {
        categorie->ajouterQuestion(maListeQuestions->at(0));
        CategorieBDD::enregistrerArbre(categorie, fileName);
    }
    else
    {
        qDebug() << "Erreur dans l'enregistrement.";
    }
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

    // On remplit le TreeView des réponses
    for(int i = 0; i < lr->size(); i++)
    {
        Reponse * r = lr->at(i);
        QStandardItem * elemRep = new QStandardItem(r->getReponse());

        // Pour chaque réponse, on ajoute ses médias associés
        ListeMedia * lm = r->getListeIllustration();
        for(int j = 0; j < lm->size(); j++)
        {
            elemRep->appendRow(new QStandardItem(QString::number(lm->at(j)->getType()) + "-" + lm->at(j)->getPath()));
        }

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
        QStandardItem * elemMed = new QStandardItem(QString::number(m->getType()) + "-" + m->getPath());
        model_tvMediaQuestion->appendRow(elemMed);
    }
}

void MainWindow::on_clickTreeViewMediasQuestions(const QModelIndex &index)
{
    QString txtCurIdx = model_tvMediaQuestion->itemFromIndex(index)->text();
    openMedia(txtCurIdx, 0);
}

void MainWindow::on_clickTreeViewReponse(const QModelIndex &index)
{
    // TODO : refléchir à une meilleur méthode pour déterminer le type de media :
    //      - TreeView avec 2 colonnes (1 pour le type et l'autre pour le contenu)
    //      - ...

    qDebug() << "row : " << index.row() << "; column : " << index.column();

    if(index.parent() == QModelIndex()) // l'élément courant n'a pas de parent ; on affiche ses 4 premières images
    {
        // Il faut parcourir les médias (ses fils) et afficher les 4 premières images
        // On ne tient pas compte des autres médias ni des 5ème, 6ème... images
        int nbImage = 0;
        int column = 0;
        while(nbImage < 4) // tant que l'on a pas affiché 4 images
        {
            QModelIndex curChild = index.child(0, column);
            if(curChild.isValid() == true) // on test si l'item est valide pour savoir s'il existe encore un fils
            {
                if(model_tvReponse->itemFromIndex(curChild)->text().startsWith("1")) // si l'élément courant est une image
                {
                    // on affiche l'image dans le label i (= nbImage)
                    QLabel * myLabel = new QLabel();

                    QString fileName = model_tvReponse->itemFromIndex(curChild)->text();
                    fileName.remove(0, 2);

                    QImage * myImg = new QImage(fileName);
                    if(myImg->isNull() != true)
                    {
                        QImage myScaledImg = myImg->scaled(QSize(250, 250), Qt::KeepAspectRatio);

                        QPixmap * img = new QPixmap();
                        img->convertFromImage(myScaledImg, Qt::AutoColor);

                        myLabel->setPixmap(*img);
                    }

                    // On ajoute l'image au conteneur
                    ui->verticalLayout_3->addWidget(myLabel);

                    nbImage++;
                }
                // on passe au fils suivant
                column++;
            }
        }
    }
    else
    {
        QString txtCurIdx = model_tvReponse->itemFromIndex(index)->text();
        openMedia(txtCurIdx, 0);
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
    // Permet d'ajouter une question en tant que fils de la question courante (est-ce pertinent ? cette question ne sera pas reliée par une réponse)

    // TODO : Ouvrir une fenêtre qui demande le nom de la question à insérer
    Question * newQuestion = new Question(0);

    myWindow = new ModifQuestionWindow(newQuestion, this);
    myWindow->setModal(true);
    myWindow->exec();

    QModelIndex index = ui->treeViewQuestion->currentIndex();
    QStandardItem * currentSelection = model_tvQuestion->itemFromIndex(index);

    //QStandardItem * elem = new QStandardItem(greenIcon, "Ceci est une nouvelle question");
    QStandardItem * elem = new QStandardItem(greenIcon, newQuestion->getQuestion());

    // On calcul les coordonnées du noeud courant
    int profondeur = 0;
    QModelIndex currentIndex = index.parent();
    while(currentIndex != QModelIndex())
    {
        currentIndex = currentIndex.parent();
        profondeur++;
    }
    QString coordonnees = QString::number(profondeur) + "-" + QString::number(index.row());
    Question * currentQuestion = mapTreeQuestions.value(coordonnees);

    // On récupère le nombre de frère de la question
    int nbFils = currentQuestion->getListeReponse()->size();

    // On ajoute l'élément en tant que fils de l'élément courant
    currentSelection->appendRow(elem);

    profondeur++;
    // TODO : problème au niveau du 2ème paramètre
    QString coordonnees2 = QString::number(profondeur) + "-" + QString::number(nbFils);
    qDebug() << "PAS RACINE coordonnees2 : " << coordonnees2;

    // TODO : attention, lors de l'insertion d'une nouvelle question en mémoire, j'ai l'impression qu'elle n'ai pas prise en compte au prochain passage...
    currentQuestion->getCat()->ajouterQuestion(newQuestion);
<<<<<<< HEAD

    mapTreeQuestions.insert(coordonnees2, newQuestion);

=======

    mapTreeQuestions.insert(coordonnees2, newQuestion);

>>>>>>> 84d0423
    // On rafraichit le TreeView
    //model_tvQuestion->
}

void MainWindow::newQuestionFrere()
{
    // Permet d'ajouter une question au même niveau que la question courante à la fin

    // TODO : Ouvrir une fenêtre qui demande le nom de la question à insérer

    QModelIndex index = ui->treeViewQuestion->currentIndex(); // on récupère l'index de la selection
    QStandardItem * currentSelection = model_tvQuestion->itemFromIndex(index); // on récupère l'item de la selection

    QStandardItem * elem = new QStandardItem(greenIcon, "Ceci est une nouvelle question"); // question bidon pour les tests

    // On calcul les coordonnées du noeud courant
    int profondeur = 0;
    QModelIndex currentIndex = index.parent();
    while(currentIndex != QModelIndex())
    {
        currentIndex = currentIndex.parent();
        profondeur++;
    }
    QString coordonnees = QString::number(profondeur) + "-" + QString::number(index.row());
    Question * currentQuestion = mapTreeQuestions.value(coordonnees);

    // On récupère le nombre de frère de la question
    int nbFrere = currentQuestion->getCat()->getListeQuestion()->size();

    if (currentSelection->parent() != 0) // si l'élément selectionné n'est pas un élément racine
    {
        currentSelection->parent()->appendRow(elem);

        // TODO : problème au niveau du 2ème paramètre
        QString coordonnees2 = QString::number(profondeur) + "-" + QString::number(nbFrere + 1);
        qDebug() << "PAS RACINE coordonnees2 : " << coordonnees2;

        Question * q = new Question(1);
        q->setQuestion("Ceci est une nouvelle question");
        q->setVisible("true");
        currentQuestion->getCat()->ajouterQuestion(q);
        mapTreeQuestions.insert(coordonnees2, q);
    }
    else // l'élément selectionné est à la racine du TreeView
    {
        model_tvQuestion->insertRow(nbFrere, elem);

        QString coordonnees2 = "0-" + QString::number(nbFrere);
        qDebug() << "RACINE coordonnees2 : " << coordonnees2;

        Question * q = new Question(1);
        q->setQuestion("Ceci est une nouvelle question");
        q->setVisible("true");
        currentQuestion->getCat()->ajouterQuestion(q);
        mapTreeQuestions.insert(coordonnees2, q);
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

    int profondeur = 0;
    QModelIndex currentIndex = index.parent();
    while(currentIndex != QModelIndex())
    {
        currentIndex = currentIndex.parent();
        profondeur++;
    }
    QString coordonnees = QString::number(profondeur) + "-" + QString::number(index.row());
    Question * currentQuestion = mapTreeQuestions.value(coordonnees);

    model_tvQuestion->removeRow(index.row(), index.parent());
}

void MainWindow::newReponse()
{
    QStandardItem * elemRep = new QStandardItem("Nouvelle réponse");
    model_tvReponse->appendRow(elemRep);
}

void MainWindow::modifierReponse()
{

}

void MainWindow::supprimerReponse()
{
    QModelIndex currentIndex = ui->treeViewReponse->currentIndex();
    model_tvReponse->removeRow(currentIndex.row());
}

void MainWindow::newMedia()
{

}

void MainWindow::modifierMedia()
{

}

void MainWindow::supprimerMedia()
{

}

void MainWindow::playAudio(QString fileName)
{
    myAudioPlayer = new AudioPlayer("images/test_audio.wav");

    myAudioPlayer->setModal(true);
    myAudioPlayer->exec();
}

void MainWindow::playVideo(QString fileName)
{
    myVideoPlayer = new VideoPlayer("images/test_video.avi");

    myVideoPlayer->setModal(true);
    myVideoPlayer->exec();
}

void MainWindow::openMedia(QString fileName, int typeMedia)
{
    QString txtCurIdx = fileName;

    if(txtCurIdx.startsWith("0")) // Media de type MEDIA_TYPE_VIDEO
    {
        txtCurIdx.remove(0, 2); // on supprime le chiffre et le tiret représentant le type du media
        playVideo(txtCurIdx);
    }
    else if(txtCurIdx.startsWith("1")) // Media de type MEDIA_TYPE_IMAGE
    {
        txtCurIdx.remove(0, 2);

        QImage * myImg = new QImage(txtCurIdx);
        if(myImg->isNull() != true)
        {
            // TODO : Réfléchir à comment redimensionner l'image correctement
            // TODO : en cliquant sur l'image, il serait bien qu'elle puisse s'ouvrir en plein écran dans une nouvelle fenêtre par exemple
            QImage myScaledImg = myImg->scaled(QSize(250, 250), Qt::KeepAspectRatio);

            QPixmap * img = new QPixmap();
            img->convertFromImage(myScaledImg, Qt::AutoColor);

            ui->labelImage1->setPixmap(*img);
        }
    }
    else if(txtCurIdx.startsWith("2")) // Media de type MEDIA_TYPE_TEXT
    {
        txtCurIdx.remove(0, 2);

        ui->labelImage1->setText(txtCurIdx);
    }
    else if(txtCurIdx.startsWith("3")) // Media de type MEDIA_TYPE_AUDIO
    {
        txtCurIdx.remove(0, 2);

        playAudio(txtCurIdx);
    }
    else
    {
        ui->labelImage1->setText("Media inconnu...");
    }
}
