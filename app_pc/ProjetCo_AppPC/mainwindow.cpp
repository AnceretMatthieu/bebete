#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /* Initialisation des icones */
    greenIcon = QIcon("images/icon_green.png");
    yellowIcon = QIcon("images/icon_yellow.png");
    redIcon = QIcon("images/icon_red.png");

    // TODO : penser � v�rifier que la structure des dossiers de m�dias est correctement cr��
    // Si ce n'est pas le cas, le faire.

    // TODO : � supprimer ; se trouve d�sormais dans la fonction du menu "Importer XML"
    maListeQuestions = CategorieBDD::CreerArbre(QDir::currentPath() + "/accueil.xml");

    /* Peuplement des TreeView */
    // TODO : il faudrait que le TreeView des r�ponses et celui des m�diasQuestions soient compos�s de 2 colonnes : une pour le type et l'autre pour le contenu
    model_tvQuestion = new QStandardItemModel(0, 0);
    model_tvReponse = new QStandardItemModel;
    model_tvMediaQuestion = new QStandardItemModel;

    // TODO : � supprimer ; se trouve d�sormais dans la fonction du menu "Importer XML"
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

    /* Cr�ation des actions */
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

        // Permet de d�terminer la couleur
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

        if(pere == NULL) // pour le cas ou les questions n'ont pas de p�re
        {
            model_tvQuestion->appendRow(elem);
            nbPere = 0;
        }
        else
        {
            pere->appendRow(elem);
            nbPere++;
        }

        // On ajoute les "coordonn�es" de la question dans le TreeView dans une map
        QString coordonnees = QString::number(nbPere) + "-" + QString::number(elem->index().row());
        //qDebug() << "Coordon�es question " << q->getQuestion() << " : " << coordonnees;
        if(mapTreeQuestions.contains(coordonnees) == false)
        {
            mapTreeQuestions.insert(coordonnees, q);
        }

        // pour chaque r�ponse de la question courante
        ListeReponse * lr = q->getListeReponse();
        for(int j = 0; j < lr->size(); j++)
        {
            if(lr->at(j)->getTypeSuiv() == TYPE_CATEGORIE) // c'est une cat�gorie
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
    addQuestionFils = new QAction(tr("Ajouter une question fils"), this);
    connect(addQuestionFils, SIGNAL(triggered()), this, SLOT(newQuestionFils()));

    addQuestionFrere = new QAction(tr("Ajouter une question fr�re"), this);
    connect(addQuestionFrere, SIGNAL(triggered()), this, SLOT(newQuestionFrere()));

    modifQuestion = new QAction(tr("Modifier"), this);
    connect(modifQuestion, SIGNAL(triggered()), this, SLOT(modifierQuestion()));

    delQuestion = new QAction(tr("Supprimer"), this);
    connect(delQuestion, SIGNAL(triggered()), this, SLOT(supprimerQuestion()));

    addReponse = new QAction(tr("Ajouter une r�ponse"), this);
    connect(addReponse, SIGNAL(triggered()), this, SLOT(newReponse()));

    modifReponse = new QAction(tr("Modifier"), this);
    connect(modifReponse, SIGNAL(triggered()), this, SLOT(modifierReponse()));

    delReponse = new QAction(tr("Supprimer"), this);
    connect(delReponse, SIGNAL(triggered()), this, SLOT(supprimerReponse()));

    /* Affectation des actions sur les boutons du menu */
    connect(ui->actionExporter_XML, SIGNAL(triggered()), this, SLOT(on_actionExporter_XML_triggered()));
    connect(ui->actionImporter_XML, SIGNAL(triggered()), this, SLOT(on_actionImporter_XML_triggered()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(on_actionQuitter_triggered()));
    connect(ui->actionA_propos_de, SIGNAL(triggered()), this, SLOT(on_actionApropos()));

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

    /* Affectation des actions aux boutons des r�ponses */
    connect(ui->button_ajouterReponse, SIGNAL(clicked()), this, SLOT(newReponse()));
    connect(ui->button_modifierReponse, SIGNAL(clicked()), this, SLOT(modifierReponse()));
    connect(ui->button_supprimerReponse, SIGNAL(clicked()), this, SLOT(supprimerReponse()));

    /* Affectation des actions aux boutons des m�dias des questions */
    connect(ui->button_ajouterComQuestion, SIGNAL(clicked()), this, SLOT(newCommentaire()));
    connect(ui->button_ajouterMediaQuestion, SIGNAL(clicked()), this, SLOT(newMedia()));
    connect(ui->button_modifierMediaQuestion, SIGNAL(clicked()), this, SLOT(modifierMedia()));
    connect(ui->button_supprimerMediaQuestion, SIGNAL(clicked()), this, SLOT(supprimerMedia()));

    /* Affectation des actions aux boutons des m�dias des r�ponses */
    // ..
}

void MainWindow::on_actionImporter_XML_triggered()
{
    // TODO : peut-�tre penser � vider tous les TreeView & Co avant d'importer un nouvel arbre ;
    // peut-�tre proposer aussi d'enregistrer le travail courant

    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir le fichier de base de donn�es"), QDir::currentPath(), tr("Fichier XML (*.xml)"));

    // Parsage de l'arbre
    maListeQuestions = CategorieBDD::CreerArbre(fileName);

    // Remplissage des TreeView
    peuplerListeQuestionsXML(maListeQuestions, NULL, 0);
}

void MainWindow::on_actionExporter_XML_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer le fichier de base de donn�es"), QDir::currentPath(), tr("Fichier XML (*.xml)"));

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
    // On vide la QMap des r�ponses
    mapTreeReponses.clear();

    // On calcul la profondeur de l'item cliqu�
    int profondeur = 0;
    QModelIndex currentIndex = index.parent();
    while(currentIndex != QModelIndex())
    {
        currentIndex = currentIndex.parent();
        profondeur++;
    }

    /*
        index.row() ==> correspond au 2�me chiffre dans la map
        profondeur ==> correspond au 1er chiffre dans la map
    */

    // On peut donc construire les coordon�es de l'item selectionn�
    QString coordonnees = QString::number(profondeur) + "-" + QString::number(index.row());
    qDebug() << "Coordonn�es : " << coordonnees;

    // On affiche le texte de la question
    QString texte = model_tvQuestion->itemFromIndex(index)->text();
    ui->labelQuestion->setText(texte);

    // On r�cup�re, via la QMap, la question correpondant � l'item cliqu�
    Question * currentQuestion = mapTreeQuestions.value(coordonnees);
    ListeReponse * lr = currentQuestion->getListeReponse();

    // On remplit le TreeView des r�ponses
    for(int i = 0; i < lr->size(); i++)
    {
        Reponse * r = lr->at(i);
        QStandardItem * elemRep = new QStandardItem(r->getReponse());

        // Pour chaque r�ponse, on ajoute ses m�dias associ�s
        ListeMedia * lm = r->getListeIllustration();
        for(int j = 0; j < lm->size(); j++)
        {
            elemRep->appendRow(new QStandardItem(QString::number(lm->at(j)->getType()) + "-" + lm->at(j)->getPath()));
        }

        model_tvReponse->appendRow(elemRep);
        mapTreeReponses.insert(QString::number(i), r);
    }

    // Gestion de l'attribut "visible" de la balise "Question" ==> on coche/d�coche les checkbox
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

    // On r�cup�re les m�dias associ�s � la question
    ListeMedia * lm = currentQuestion->getListeMedia();

    // TODO : am�liorer la fa�on d'afficher les m�dias
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
    ui->labelImage1->clear();
    ui->labelImage2->clear();
    ui->labelImage3->clear();
    ui->labelImage4->clear();

    if(index.parent() == QModelIndex()) // l'�l�ment courant n'a pas de parent ; on affiche ses 4 premi�res images
    {
        Reponse * r = mapTreeReponses.value(QString::number(index.row()));
        if(r != NULL)
        {
            ListeMedia * lm = r->getListeIllustration();
            int nbImage = 0;
            if(!lm->isEmpty())
            {
                for(int i = 0; i < lm->size(); i++)
                {
                    if(lm->at(i)->getType() == MEDIA_TYPE_IMAGE) // si le m�dia est une image
                    {
                        QString fileName = lm->at(i)->getPath();
                        QImage * myImg = new QImage(fileName);

                        if(myImg->isNull() != true)
                        {
                            QImage myScaledImg = myImg->scaled(QSize(250, 250), Qt::KeepAspectRatio);

                            QPixmap * img = new QPixmap();
                            img->convertFromImage(myScaledImg, Qt::AutoColor);

                            if(nbImage == 0) {
                                ui->labelImage1->setPixmap(*img);
                            }
                            else if(nbImage == 1) {
                                ui->labelImage2->setPixmap(*img);
                            }
                            else if(nbImage == 2) {
                                ui->labelImage3->setPixmap(*img);
                            }
                            else if(nbImage == 3) {
                                ui->labelImage4->setPixmap(*img);
                            }
                            nbImage++;
                        }
                    }
                }
            }

            // On affiche le nom de la question qui suit la r�ponse selectionn�e
            ListeQuestion * lq = ((Categorie *)r->getSuiv())->getListeQuestion();

            if(lq->getEstVide() == 0)
            {
                if(lq->size() != 0)
                {
                    ui->labelReponse2->setText("Question suivante : " + lq->at(0)->getQuestion());
                }
                else
                {
                    ui->labelReponse2->setText("Pas de question suivante...");
                }
            }
            else
        {
            ui->labelReponse2->setText("Pas de question suivante...");
        }
        }
    }
    else
    {
        QString txtCurIdx = model_tvReponse->itemFromIndex(index)->text();
        openMedia(txtCurIdx, 0);
    }
}

void MainWindow::newQuestionFils()
{
    Question * newQuestion = new Question(0);

    myWindowQues = new ModifQuestionWindow(newQuestion, this);
    myWindowQues->setModal(true);
    myWindowQues->exec();

    QModelIndex index = ui->treeViewQuestion->currentIndex();
    QStandardItem * currentSelection = model_tvQuestion->itemFromIndex(index);

    QStandardItem * elem = new QStandardItem(greenIcon, newQuestion->getQuestion());

    // On calcul les coordonn�es du noeud courant
    int profondeur = 0;
    QModelIndex currentIndex = index.parent();
    while(currentIndex != QModelIndex())
    {
        currentIndex = currentIndex.parent();
        profondeur++;
    }
    QString coordonnees = QString::number(profondeur) + "-" + QString::number(index.row());
    Question * currentQuestion = mapTreeQuestions.value(coordonnees);

    // On r�cup�re le nombre de fr�re de la question
    int nbFils = currentQuestion->getListeReponse()->size();

    // On ajoute l'�l�ment en tant que fils de l'�l�ment courant
    currentSelection->appendRow(elem);

    profondeur++;
    // TODO : probl�me au niveau du 2�me param�tre
    QString coordonnees2 = QString::number(profondeur) + "-" + QString::number(nbFils);
    qDebug() << "PAS RACINE coordonnees2 : " << coordonnees2;

    // TODO : attention, lors de l'insertion d'une nouvelle question en m�moire, j'ai l'impression qu'elle n'ai pas prise en compte au prochain passage...
    currentQuestion->getCat()->ajouterQuestion(newQuestion);

    mapTreeQuestions.insert(coordonnees2, newQuestion);
}

void MainWindow::newQuestionFrere()
{
    // Permet d'ajouter une question au m�me niveau que la question courante � la fin

    // TODO : Ouvrir une fen�tre qui demande le nom de la question � ins�rer

    QModelIndex index = ui->treeViewQuestion->currentIndex(); // on r�cup�re l'index de la selection
    QStandardItem * currentSelection = model_tvQuestion->itemFromIndex(index); // on r�cup�re l'item de la selection

    QStandardItem * elem = new QStandardItem(greenIcon, "Ceci est une nouvelle question"); // question bidon pour les tests

    // On calcul les coordonn�es du noeud courant
    int profondeur = 0;
    QModelIndex currentIndex = index.parent();
    while(currentIndex != QModelIndex())
    {
        currentIndex = currentIndex.parent();
        profondeur++;
    }
    QString coordonnees = QString::number(profondeur) + "-" + QString::number(index.row());
    Question * currentQuestion = mapTreeQuestions.value(coordonnees);

    // On r�cup�re le nombre de fr�re de la question
    int nbFrere = currentQuestion->getCat()->getListeQuestion()->size();

    if (currentSelection->parent() != 0) // si l'�l�ment selectionn� n'est pas un �l�ment racine
    {
        currentSelection->parent()->appendRow(elem);

        // TODO : probl�me au niveau du 2�me param�tre
        QString coordonnees2 = QString::number(profondeur) + "-" + QString::number(nbFrere + 1);
        qDebug() << "PAS RACINE coordonnees2 : " << coordonnees2;

        Question * q = new Question(1);
        q->setQuestion("Ceci est une nouvelle question");
        q->setVisible("true");
        currentQuestion->getCat()->ajouterQuestion(q);
        mapTreeQuestions.insert(coordonnees2, q);
    }
    else // l'�l�ment selectionn� est � la racine du TreeView
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
    // Il faut envoyer les param�tres de l'item courant � la fen�tre pour pouvoir afficher les infos (texte de la question, ...)

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

    myWindowQues = new ModifQuestionWindow(currentQuestion, this);

    myWindowQues->setModal(true);
    myWindowQues->exec();

    // On modifie l'item correspondant dans le mod�le du TreeView
    QStandardItem * tmp = model_tvQuestion->itemFromIndex(index);
    tmp->setText(currentQuestion->getQuestion());
    model_tvQuestion->setItem(index.row(), tmp);
}

void MainWindow::supprimerQuestion()
{
    // TODO : demander confirmation avant de supprimer une question ?
    // (surtout dans le cas ou la question poss�de des fils)

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

    // On supprime la question du mod�le
    model_tvQuestion->removeRow(index.row(), index.parent());

    // On supprime la question de la m�moire
    ListeQuestion * tmp = currentQuestion->getCat()->getListeQuestion();
    tmp->remove(tmp->indexOf(currentQuestion));
}

void MainWindow::newReponse()
{
    QStandardItem * elemRep = new QStandardItem("Nouvelle r�ponse");
    model_tvReponse->appendRow(elemRep);
}

void MainWindow::modifierReponse()
{
    // Il faut envoyer les param�tres de l'item courant � la fen�tre pour pouvoir afficher les infos (texte de la question, ...)

    QModelIndex index = ui->treeViewReponse->currentIndex();
    int profondeur = 0;
    Reponse * currentReponse = mapTreeReponses.value(QString::number(index.row()));

    myWindowRep = new ModifReponseWindow(currentReponse, this);
    myWindowRep->setModal(true);
    myWindowRep->exec();

    // On modifie l'item correspondant dans le mod�le du TreeView
    QStandardItem * tmp = model_tvReponse->itemFromIndex(index);
    tmp->setText(currentReponse->getReponse());
    model_tvReponse->setItem(index.row(), tmp);
}

void MainWindow::supprimerReponse()
{
    QModelIndex currentIndex = ui->treeViewReponse->currentIndex();
    model_tvReponse->removeRow(currentIndex.row());
}

void MainWindow::newCommentaire()
{
    QString leTxt;

    myTxtWindow = new AjouterTexte(&leTxt, this);

    myTxtWindow->setModal(true);
    myTxtWindow->exec();

    // Cr�ation de l'item avec le texte re�u
    QStandardItem * elem = new QStandardItem(leTxt);
    model_tvMediaQuestion->appendRow(elem);

    // TODO : il faut associer le m�dia � la question
    // ...
}

void MainWindow::newMedia()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Selectionner un m�dia � ajouter"), QDir::currentPath(), tr("Tous les fichiers(*.*)"));

    model_tvMediaQuestion->appendRow(new QStandardItem(fileName));
}

void MainWindow::modifierMedia()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Selectionner un m�dia � ajouter"), QDir::currentPath(), tr("Tous les fichiers(*.*)"));

    QModelIndex currentIndex = ui->treeViewMediasQuestion->currentIndex();

    // On modifie l'item correspondant dans le mod�le du TreeView
    QStandardItem * tmp = model_tvMediaQuestion->itemFromIndex(currentIndex);
    tmp->setText(fileName);
    model_tvMediaQuestion->setItem(currentIndex.row(), tmp);
}

void MainWindow::supprimerMedia()
{
    QModelIndex currentIndex = ui->treeViewMediasQuestion->currentIndex();
    model_tvMediaQuestion->removeRow(currentIndex.row());

    // TODO : il faut aussi supprimer le m�dia de la question associ�e
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
        txtCurIdx.remove(0, 2); // on supprime le chiffre et le tiret repr�sentant le type du media
        playVideo(txtCurIdx);
    }
    else if(txtCurIdx.startsWith("1")) // Media de type MEDIA_TYPE_IMAGE
    {
        txtCurIdx.remove(0, 2);

        QImage * myImg = new QImage(txtCurIdx);
        if(myImg->isNull() != true)
        {
            // TODO : R�fl�chir � comment redimensionner l'image correctement
            // TODO : en cliquant sur l'image, il serait bien qu'elle puisse s'ouvrir en plein �cran dans une nouvelle fen�tre par exemple
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
