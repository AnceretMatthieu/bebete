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

    /* Peuplement des TreeView */
    model_tvQuestion = new QStandardItemModel(0, 0);
    model_tvReponse = new QStandardItemModel;
    model_tvMediaQuestion = new QStandardItemModel;

    ui->setupUi(this);

    ui->treeViewQuestion->setModel(model_tvQuestion);
    ui->treeViewReponse->setModel(model_tvReponse);
    ui->treeViewMediasQuestion->setModel(model_tvMediaQuestion);

    /* Mise en place du style CSS et application sur le widget QTreeView des questions */
    QFile styleFile("style_qtreeview.css");
    styleFile.open(QFile::ReadOnly);

    QString style(styleFile.readAll());
    ui->treeViewQuestion->setStyleSheet(style);

    /* Cr�ation des actions */
    createAction();

    maListeQuestions = new ListeQuestion();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::peuplerListeQuestionsXML(ListeQuestion * uneListeQuestions, QStandardItem * pere, int nbPere, QString coordPere)
{
    for(int i = 0; i < uneListeQuestions->size(); i++)
    {
        Question * q = uneListeQuestions->at(i);
        QStandardItem * elem;
        QString s = q->getQuestion();
        // Permet de d�terminer la couleur
        if(q->getListeMedia()->size() < 1)
        {

            elem = new QStandardItem(redIcon, s);
        }
        else
        {
            if(q->getListeMedia()->size() < 2)
            {
                elem = new QStandardItem(yellowIcon, s);
            }
            else
            {
                elem = new QStandardItem(greenIcon, s);
            }
        }

        QString coordonnees;
        if(pere == NULL) // pour le cas ou les questions n'ont pas de p�re
        {
            model_tvQuestion->appendRow(elem);
            nbPere = 0;
            coordonnees = QString::number(elem->index().row());
        }
        else
        {
            pere->appendRow(elem);
            nbPere++;
            coordonnees = coordPere + QString::number(elem->index().row());
        }

        // On ajoute les "coordonn�es" de la question dans le TreeView dans une map
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
                peuplerListeQuestionsXML(lq, elem, nbPere, coordonnees);
            }
        }
    }
}

void MainWindow::createAction()
{
    /* Affectation des actions sur les boutons du menu */
    connect(ui->actionExporter_XML, SIGNAL(triggered()), this, SLOT(actionExporter_XML_triggered()));
    connect(ui->actionImporter_XML, SIGNAL(triggered()), this, SLOT(actionImporter_XML_triggered()));
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(actionQuitter_triggered()));
    connect(ui->actionA_propos_de, SIGNAL(triggered()), this, SLOT(actionApropos()));

    /* Gestion du clic sur les items */
    connect(ui->treeViewQuestion, SIGNAL(clicked(QModelIndex)), this, SLOT(clickTreeViewQuestions(QModelIndex)));
    connect(ui->treeViewReponse, SIGNAL(clicked(QModelIndex)), this, SLOT(clickTreeViewReponse(QModelIndex)));
    connect(ui->treeViewMediasQuestion, SIGNAL(clicked(QModelIndex)), this, SLOT(clickTreeViewMediasQuestions(QModelIndex)));

    /* Affectation des actions aux boutons des questions */
    connect(ui->button_addQuestionFils, SIGNAL(clicked()), this, SLOT(newQuestionFils()));
    connect(ui->button_addQuestionFrere, SIGNAL(clicked()), this, SLOT(newQuestionFrere()));
    connect(ui->button_modifierQuestion, SIGNAL(clicked()), this, SLOT(modifierQuestion()));
    connect(ui->button_supprimerQuestion, SIGNAL(clicked()), this, SLOT(supprimerQuestion()));

    /* Affectation des actions aux boutons des m�dias des questions */
    connect(ui->button_ajouterComQuestion, SIGNAL(clicked()), this, SLOT(newCommentaire()));
    connect(ui->button_ajouterMediaQuestion, SIGNAL(clicked()), this, SLOT(newMedia()));
    connect(ui->button_modifierMediaQuestion, SIGNAL(clicked()), this, SLOT(modifierMedia()));
    connect(ui->button_supprimerMediaQuestion, SIGNAL(clicked()), this, SLOT(supprimerMedia()));

    /* Affectation des actions aux boutons des r�ponses */
    connect(ui->button_ajouterReponse, SIGNAL(clicked()), this, SLOT(newReponse()));
    connect(ui->button_modifierReponse, SIGNAL(clicked()), this, SLOT(modifierReponse()));
    connect(ui->button_supprimerReponse, SIGNAL(clicked()), this, SLOT(supprimerReponse()));

    /* Affectation des actions aux boutons des m�dias des r�ponses */
    connect(ui->button_ajouterComMediaReponse, SIGNAL(clicked()), this, SLOT(newComMediaReponse()));
    connect(ui->button_ajouterMediaReponse, SIGNAL(clicked()), this, SLOT(newMediaReponse()));
    connect(ui->button_modifierMediaReponse, SIGNAL(clicked()), this, SLOT(modifierMediaReponse()));
    connect(ui->button_supprimerMediaReponse, SIGNAL(clicked()), this, SLOT(supprimerMediaReponse()));
}

void MainWindow::actionImporter_XML_triggered()
{
    // TODO : si une session de travail est en cours, proposer d'enregistrer le travail courant (export)

    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir le fichier de base de donn�es"), QDir::currentPath(), tr("Fichier XML (*.xml)"));

    if(fileName != "")
    {
        model_tvQuestion->clear();
        mapTreeQuestions.clear();

        // Parsage de l'arbre
        maListeQuestions = BDD::CreerArbre(fileName);

        // Remplissage des TreeView
        peuplerListeQuestionsXML(maListeQuestions, NULL, 0, "");
    }

}

void MainWindow::actionExporter_XML_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer le fichier de base de donn�es"), QDir::currentPath(), tr("Fichier XML (*.xml)"));

    if(fileName != "")
    {
        Categorie categorie(1);
        if(maListeQuestions->size() != 0)
        {
            categorie.ajouterQuestion(maListeQuestions->at(0));
            BDD::enregistrerArbre(&categorie, fileName);
        }
        else
        {
            qDebug() << "Erreur dans l'enregistrement.";
        }
    }
}

void MainWindow::actionQuitter_triggered()
{
    close();
}

void MainWindow::actionApropos()
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

void MainWindow::clickTreeViewQuestions(const QModelIndex &index)
{
    // On commence par vider le contenu des TreeView
    model_tvReponse->clear();
    model_tvMediaQuestion->clear();
    // On vide la QMap des r�ponses
    mapTreeReponses.clear();

    QString coord = calculerCoordonnees(index);

    // On affiche le texte de la question
    QString texte = model_tvQuestion->itemFromIndex(index)->text();
    ui->labelQuestion->setText(texte);

    // On r�cup�re, via la QMap, la question correpondant � l'item cliqu�
    Question * currentQuestion = mapTreeQuestions.value(coord);

    // On remplit le TreeView des r�ponses
    ListeReponse * lr = currentQuestion->getListeReponse();
    for(int i = 0; i < lr->size(); i++)
    {
        Reponse * r = lr->at(i);
        QString s = r->getReponse();
        QStandardItem * elemRep = new QStandardItem(s);

        // Pour chaque r�ponse, on ajoute ses m�dias associ�s
        ListeMedia * lm = r->getListeIllustration();
        for(int j = 0; j < lm->size(); j++)
        {
            s = QString::number(lm->at(j)->getType()) + "-" + lm->at(j)->getPath();
            elemRep->appendRow(new QStandardItem(s));
        }

        model_tvReponse->appendRow(elemRep);
        mapTreeReponses.insert(QString::number(elemRep->index().row()), r);
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
        QString s = QString::number(m->getType()) + "-" + m->getPath();
        QStandardItem * elemMed = new QStandardItem(s);
        model_tvMediaQuestion->appendRow(elemMed);
    }
}

void MainWindow::clickTreeViewMediasQuestions(const QModelIndex &index)
{
    QString txtCurIdx = model_tvMediaQuestion->itemFromIndex(index)->text();
    openMedia(txtCurIdx, 0);
}

void MainWindow::clickTreeViewReponse(const QModelIndex &index)
{
    ui->labelImage1->clear();
    ui->labelImage2->clear();
    ui->labelImage3->clear();
    ui->labelImage4->clear();
    ui->labelImage5->clear();

    if(index.parent() == QModelIndex()) // l'�l�ment courant n'a pas de parent ; on affiche ses 4 premi�res images
    {
        Reponse * r = mapTreeReponses.value(QString::number(index.row()));
        if(r != NULL)
        {
            if(r->getTypeSuiv() != TYPE_EMPTY)
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
                            QImage * myImg = new QImage("images/" + fileName);

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

                if(r->getTypeSuiv() == TYPE_CATEGORIE)
                {
                    ListeQuestion * lq = ((Categorie *)(r->getSuiv()))->getListeQuestion();
                    if(lq->size() != 0)
                    {
                        QString s = "Question suivante : " + lq->at(0)->getQuestion();
                        ui->labelReponse2->setText(s);
                    }
                    else
                    {
                        ui->labelReponse2->setText("Pas de question suivante...");
                    }
                }
                else // c'est une esp�ce
                {
                    Espece * currentResult = ((Espece *)r->getSuiv());

                    QString result = "R�sultat";
                    QString nom = currentResult->getNom();
                    QString type = currentResult->getType();
                    QString regime = currentResult->getRegimeAlimentaire();
                    QString info = currentResult->getInformation();
                    ui->labelReponse2->setText(result);
                    ui->labelImage1->setText("Nom : " + nom);
                    ui->labelImage2->setText("Type : " + type);
                    ui->labelImage3->setText("R�gime alimentaire : " + regime);
                    ui->labelImage4->setText("Informations : " + info);

                    ListeMedia * lm = currentResult->getListeMedia();
                    if(lm->size() != 0) {
                        for(int i = 0; i < lm->size(); i++) {
                            if(lm->at(i)->getType() == MEDIA_TYPE_IMAGE) // si le m�dia est une image
                            {
                                QString fileName = lm->at(i)->getPath();
                                QImage * myImg = new QImage("images/" + fileName);

                                if(myImg->isNull() != true)
                                {
                                    QImage myScaledImg = myImg->scaled(QSize(250, 250), Qt::KeepAspectRatio);

                                    QPixmap * img = new QPixmap();
                                    img->convertFromImage(myScaledImg, Qt::AutoColor);

                                    ui->labelImage5->setPixmap(*img);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            else {
                ui->labelReponse2->setText("Cette r�ponse n'a pas de question associ�e");
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
    // Permet d'ajouter une question en tant que fils de la question courante

    Question * newQuestion = new Question(0);

    myWindowQues = new ModifQuestionWindow(newQuestion, this);
    myWindowQues->setModal(true);
    myWindowQues->exec();

    if(newQuestion->getQuestion() != "") // si la question poss�de un contenu texte, on consid�re que l'utilisateur a cliqu� sur "Annuler"
    {
        QModelIndex index = ui->treeViewQuestion->currentIndex();
        if(index.column() != -1)    {
            QStandardItem * currentSelection = model_tvQuestion->itemFromIndex(index);

            QString s = newQuestion->getQuestion();
            QStandardItem * elem = new QStandardItem(greenIcon, s);

            // On calcul les coordonn�es du noeud courant
            QString coordonnees = calculerCoordonnees(index);
            Question * currentQuestion = mapTreeQuestions.value(coordonnees);

            // On ajoute l'�l�ment en tant que fils de l'�l�ment courant
            currentSelection->appendRow(elem);

            // On calcul les coordonn�es du nouveau noeud
            QString coordonnees2 = calculerCoordonnees(elem->index());

            // On r�cup�re la r�ponse selectionn�e
            QModelIndex indexRep = ui->treeViewReponse->currentIndex();
            Reponse * currentReponse = mapTreeReponses.value(QString::number(indexRep.row()));

            // On cr�e une nouvelle cat�gorie apr�s la r�ponse s�lectionn�e
            Categorie * c = new Categorie(0);
            // On ajoute la nouvelle question apr�s cette nouvelle cat�gorie
            c->ajouterQuestion(newQuestion);
            // On ajoute la cat�gorie � la r�ponse courante
            currentReponse->setSuiv(c);
            currentReponse->setTypeSuiv(TYPE_CATEGORIE);
            mapTreeQuestions.insert(coordonnees2, newQuestion);
        }
        else    {
            QString s = newQuestion->getQuestion();
            QStandardItem * elem = new QStandardItem(greenIcon, s);
            model_tvQuestion->appendRow(elem);
            maListeQuestions->append(newQuestion);
            mapTreeQuestions.insert(calculerCoordonnees(elem->index()), newQuestion);
        }
    }
}

void MainWindow::newQuestionFrere()
{
    // Permet d'ajouter une question au m�me niveau que la question courante � la fin

    Question * newQuestion = new Question(0);

    myWindowQues = new ModifQuestionWindow(newQuestion, this);
    myWindowQues->setModal(true);
    myWindowQues->exec();

    if(newQuestion->getQuestion() != "")
    {
        QModelIndex index = ui->treeViewQuestion->currentIndex(); // on r�cup�re l'index de la selection
        QStandardItem * currentSelection = model_tvQuestion->itemFromIndex(index); // on r�cup�re l'item de la selection

        QString s  = newQuestion->getQuestion();
        QStandardItem * elem = new QStandardItem(greenIcon, s);

        // On calcul les coordonn�es du noeud courant
        QString coordonnees = calculerCoordonnees(index);
        Question * currentQuestion = mapTreeQuestions.value(coordonnees);

        if (currentSelection->parent() != 0) // l'�l�ment selectionn� n'est pas un �l�ment racine
        {
            currentSelection->parent()->appendRow(elem);

            // On calcul les coordonn�es du noeud courant
            QString coordonnees = calculerCoordonnees(elem->index());
            // On ajoute la question en m�moire
            currentQuestion->getCat()->ajouterQuestion(newQuestion);
            // On ajoute la question � la map des questions
            mapTreeQuestions.insert(coordonnees, newQuestion);
        }
        else // l'�l�ment selectionn� est � la racine
        {
            model_tvQuestion->appendRow(elem);

            QString coordonnees2 = calculerCoordonnees(elem->index());
            currentQuestion->getCat()->ajouterQuestion(newQuestion);
            mapTreeQuestions.insert(coordonnees2, newQuestion);
        }
    }
}

void MainWindow::modifierQuestion()
{
    QModelIndex index = ui->treeViewQuestion->currentIndex();

    // On calcul les coordonn�es du noeud courant
    QString coordonnees = calculerCoordonnees(index);
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
    // TODO : demander confirmation avant de supprimer une question ? seulement si elle a des fils ?

    QModelIndex index = ui->treeViewQuestion->currentIndex();

    // On calcul les coordonn�es du noeud courant
    QString coordonnees = calculerCoordonnees(index);
    Question * currentQuestion = mapTreeQuestions.value(coordonnees);

    // On supprime la question du mod�le
    model_tvQuestion->removeRow(index.row(), index.parent());

    // On supprime la question de la m�moire
    // TODO : il faut penser � supprimer tous les fils de la question, les r�ponses et les m�dias associ�s
    ListeQuestion * tmp = currentQuestion->getCat()->getListeQuestion();
    tmp->remove(tmp->indexOf(currentQuestion));
}

void MainWindow::newCommentaire()
{
    QString leTxt("Nouveau commentaire");

    // TODO : ouvrir une fenetre demandant le contenu du commentaire

    // Cr�ation de l'item avec le texte re�u
    QStandardItem * elem = new QStandardItem(leTxt);
    model_tvMediaQuestion->appendRow(elem);

    // Cr�ation de l'objet m�dia en m�moire
    Media * newMedia = new Media(0);
    newMedia->setPath(leTxt);
    newMedia->setType(MEDIA_TYPE_TEXT);

    // On r�cup�re l'index de la question selectionn�e dans le TreeView des questions
    QModelIndex index = ui->treeViewQuestion->currentIndex();
    // On calcul les coordonn�es du noeud courant
    QString coordonnees = calculerCoordonnees(index);
    // On r�cup�re la question courante
    Question * currentQuestion = mapTreeQuestions.value(coordonnees);

    // On ajoute le m�dia � la question courante
    currentQuestion->getListeMedia()->append(newMedia);
}

void MainWindow::newMedia()
{
    QString fileName = QFileInfo(QFileDialog::getOpenFileName(this, tr("Selectionner un m�dia � ajouter"), QDir::currentPath(), tr("Tous les fichiers(*.*)"))).fileName();

    model_tvMediaQuestion->appendRow(new QStandardItem(fileName));

    // TODO : il faudra penser � tester si le m�dia est pr�sent ou non dans le dossier des m�dias
    //      SI oui, pas de probl�me
    //      SI non, il faut le copier dans le dossier
}

void MainWindow::modifierMedia()
{
    QString fileName = QFileInfo(QFileDialog::getOpenFileName(this, tr("Selectionner un m�dia � ajouter"), QDir::currentPath(), tr("Tous les fichiers(*.*)"))).fileName();

    QModelIndex currentIndex = ui->treeViewMediasQuestion->currentIndex();

    // On modifie l'item correspondant dans le mod�le du TreeView
    QStandardItem * tmp = model_tvMediaQuestion->itemFromIndex(currentIndex);
    tmp->setText(fileName);
    model_tvMediaQuestion->setItem(currentIndex.row(), tmp);

    // TODO : il faudra penser � tester si le m�dia est pr�sent ou non dans le dossier des m�dias
    //      SI oui, pas de probl�me
    //      SI non, il faut le copier dans le dossier
}

void MainWindow::supprimerMedia()
{
    QModelIndex currentIndex = ui->treeViewMediasQuestion->currentIndex();
    model_tvMediaQuestion->removeRow(currentIndex.row());

    // TODO : il faut aussi supprimer le m�dia de la question associ�e

    // TODO : il faut aussi (�ventuellement) supprimer le fichier associ�
    //QFile::remove("images/" + model_tvMediaQuestion->itemFromIndex(currentIndex)->text());
}

void MainWindow::newReponse()
{
    // Permet d'ajouter une question au m�me niveau que la question courante � la fin

    Reponse * newReponse = new Reponse(0);

    myWindowRep = new ModifReponseWindow(newReponse, this);
    myWindowRep->setModal(true);
    myWindowRep->exec();

    if(newReponse->getReponse() != "")
    {
        QString s = newReponse->getReponse();

        QStandardItem * elemRep = new QStandardItem(s);
        model_tvReponse->appendRow(elemRep);

        // On r�cup�re la question courante (celle s�lectionn�e dans le treeview)
        QModelIndex index = ui->treeViewQuestion->currentIndex();
        QString coordonnees = calculerCoordonnees(index);
        Question * currentQuestion = mapTreeQuestions.value(coordonnees);

        // On ajoute la r�ponse � la liste des r�ponses de la question courante
        currentQuestion->ajouterReponse(newReponse);

        // On ajoute la r�ponse � la QMap
        mapTreeReponses.insert(QString::number(elemRep->index().row()), newReponse);
    }
}

void MainWindow::modifierReponse()
{
    QModelIndex index = ui->treeViewReponse->currentIndex();
    Reponse * currentReponse = mapTreeReponses.value(QString::number(index.row()));

    myWindowRep = new ModifReponseWindow(currentReponse, this);
    myWindowRep->setModal(true);
    myWindowRep->exec();

    // On modifie l'item correspondant dans le mod�le du TreeView
    QStandardItem * tmp = model_tvReponse->itemFromIndex(index);
    QString s = currentReponse->getReponse();
    tmp->setText(s);
    model_tvReponse->setItem(index.row(), tmp);    
}

void MainWindow::supprimerReponse()
{
    // On supprimer la r�ponse du mod�le du treeview
    QModelIndex currentIndex = ui->treeViewReponse->currentIndex();
    model_tvReponse->removeRow(currentIndex.row());

    // On r�cup�re la question courante (celle s�lectionn�e dans le treeview)
    QModelIndex index = ui->treeViewQuestion->currentIndex();
    QString coordonnees = calculerCoordonnees(index);
    Question * currentQuestion = mapTreeQuestions.value(coordonnees);

    // On supprime la r�ponse de la m�moire
    Reponse * r = mapTreeReponses.value(QString::number(currentIndex.row()));
    currentQuestion->supprimerReponse(r);

    // On supprime la r�ponse de la QMap
    mapTreeReponses.remove(QString::number(currentIndex.row()));
}

void MainWindow::newComMediaReponse()
{
    QString leTxt("Nouveau commentaire");

    // TODO : ouvrir une fenetre demandant le contenu du commentaire

    // Cr�ation de l'item avec le texte re�u
    QStandardItem * elem = new QStandardItem(leTxt);
    (model_tvMediaQuestion->itemFromIndex(ui->treeViewMediasQuestion->currentIndex()))->appendRow(elem);

    // TODO : il faut associer le m�dia � la question
    // ...
}

void MainWindow::newMediaReponse()
{

}

void MainWindow::modifierMediaReponse()
{

}

void MainWindow::supprimerMediaReponse()
{

}

void MainWindow::playAudio(QString fileName)
{
    myAudioPlayer = new AudioPlayer("images/" + fileName);
    myAudioPlayer->setModal(true);
    myAudioPlayer->exec();
}

void MainWindow::playVideo(QString fileName)
{
    myVideoPlayer = new VideoPlayer("images/" + fileName);
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

        QImage * myImg = new QImage("images/" + txtCurIdx);
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

QString MainWindow::calculerCoordonnees(QModelIndex index)
{
    QString coord;
    coord = QString::number(index.row());
    QModelIndex currentIndex = index.parent();
    while(currentIndex != QModelIndex())
    {
        coord = QString::number(currentIndex.row()) + coord;
        currentIndex = currentIndex.parent();
    }

    return coord;
}
