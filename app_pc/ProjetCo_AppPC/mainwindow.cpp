#include "mainwindow.h"
#include "ui_mainwindow.h"

/* Erreurs/bugs à corriger...
        - le clic sur le bouton "Annuler" des fenêtres modales (ajout d'un commentaire nottamment)
        - gérer l'ajout de média sur les résultats
*/

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /* Initialisation des icones */
    greenIcon = QIcon("images/icon_green.png");
    yellowIcon = QIcon("images/icon_yellow.png");
    redIcon = QIcon("images/icon_red.png");

    /* Initialisation des formats de fichier reconnu par l'application */
    formatImage << "jpg" << "png" << "jpeg";
    formatAudio << "mp3" << "wav" << "wma";
    formatVideo << "avi" << "wmv";

    // TODO : penser à vérifier que la structure des dossiers de médias est correctement créé
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

    /* Création des actions */
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
        // Permet de déterminer la couleur
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
        if(pere == NULL) // pour le cas ou les questions n'ont pas de père
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

        // On ajoute les "coordonnées" de la question dans le TreeView dans une map
        if(mapTreeQuestions.contains(coordonnees) == false)
        {
            mapTreeQuestions.insert(coordonnees, q);
        }

        // pour chaque réponse de la question courante
        ListeReponse * lr = q->getListeReponse();
        for(int j = 0; j < lr->size(); j++)
        {
            if(lr->at(j)->getTypeSuiv() == TYPE_CATEGORIE) // c'est une catégorie
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
    connect(ui->button_addQuestion, SIGNAL(clicked()), this, SLOT(newQuestion()));
    connect(ui->button_modifierQuestion, SIGNAL(clicked()), this, SLOT(modifierQuestion()));
    connect(ui->button_supprimerQuestion, SIGNAL(clicked()), this, SLOT(supprimerQuestion()));

    /* Affectation des actions aux boutons des médias des questions */
    connect(ui->button_ajouterComQuestion, SIGNAL(clicked()), this, SLOT(newCommentaire()));
    connect(ui->button_ajouterMediaQuestion, SIGNAL(clicked()), this, SLOT(newMedia()));
    connect(ui->button_modifierMediaQuestion, SIGNAL(clicked()), this, SLOT(modifierMedia()));
    connect(ui->button_supprimerMediaQuestion, SIGNAL(clicked()), this, SLOT(supprimerMedia()));

    /* Affectation des actions aux boutons des réponses */
    connect(ui->button_ajouterReponse, SIGNAL(clicked()), this, SLOT(newReponse()));
    connect(ui->button_modifierReponse, SIGNAL(clicked()), this, SLOT(modifierReponse()));
    connect(ui->button_supprimerReponse, SIGNAL(clicked()), this, SLOT(supprimerReponse()));

    /* Affectation des actions aux boutons des médias des réponses */
    connect(ui->button_ajouterComMediaReponse, SIGNAL(clicked()), this, SLOT(newComMediaReponse()));
    connect(ui->button_ajouterMediaReponse, SIGNAL(clicked()), this, SLOT(newMediaReponse()));
    connect(ui->button_modifierMediaReponse, SIGNAL(clicked()), this, SLOT(modifierMediaReponse()));
    connect(ui->button_supprimerMediaReponse, SIGNAL(clicked()), this, SLOT(supprimerMediaReponse()));
    connect(ui->button_ajouterResult, SIGNAL(clicked()), this, SLOT(newResultat()));
    connect(ui->button_modifierResult, SIGNAL(clicked()), this, SLOT(modifierResultat()));
    connect(ui->button_supprimerResult, SIGNAL(clicked()), this, SLOT(supprimerResultat()));
}

void MainWindow::receiveContents(QString str)
{
    returnText = str;
}

void MainWindow::actionImporter_XML_triggered()
{
    // TODO : si une session de travail est en cours, proposer d'enregistrer le travail courant (export)
    //      Tester si le treeview des questions est vide ou non
    //          SI vide
    //              ALORS on continu l'ouverture du nouveau fichier
    //          SINON (pas vide)
    //              ALORS on affiche une boite de dialogue demandant à l'utilisateur s'il veut enregistrer ou pas son travail

    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir le fichier de base de données"), QDir::currentPath(), tr("Fichier XML (*.xml)"));

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
    if(maListeQuestions->size() != 0)
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer le fichier de base de données"), QDir::currentPath(), tr("Fichier XML (*.xml)"));
        if(fileName != "")
        {
            Categorie categorie(++(BDD::lastId));
            categorie.ajouterQuestion(maListeQuestions->at(0));
            if(BDD::enregistrerArbre(&categorie, fileName) == 0) // enregistrement OK
            {
                QMessageBox::information(this, "Confirmation d'enregistrement du fichier", "Le fichier " + fileName + " a bien été enregistré.");

            }
            else // erreur dans l'enregistrement
            {
                QMessageBox::warning(this, "Erreur dans l'enregistrement du fichier", "L'application a rencontrée un problème dans l'enregistrement du fichier " + fileName + ".");
            }
        }
    }
    else
    {
        // S'il n'y a rien a enregistrer, on affiche un message d'erreur
        QMessageBox::warning(this, "Erreur, pas de données à enregistrer", "Vous n'avez aucune données à enregistrer.");
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
    // On vide la QMap des réponses
    mapTreeReponses.clear();

    QString coord = calculerCoordonnees(index);

    // On affiche le texte de la question
    QString texte = model_tvQuestion->itemFromIndex(index)->text();
    ui->labelQuestion->setText(texte);

    // On récupère, via la QMap, la question correpondant à l'item cliqué
    Question * currentQuestion = mapTreeQuestions.value(coord);

    // On remplit le TreeView des réponses
    ListeReponse * lr = currentQuestion->getListeReponse();
    for(int i = 0; i < lr->size(); i++)
    {
        Reponse * r = lr->at(i);
        QString s = r->getReponse();
        QStandardItem * elemRep = new QStandardItem(s);

        // Pour chaque réponse, on ajoute ses médias associés
        ListeMedia * lm = r->getListeIllustration();
        for(int j = 0; j < lm->size(); j++)
        {
            s = QString::number(lm->at(j)->getType()) + "-" + lm->at(j)->getPath();
            elemRep->appendRow(new QStandardItem(s));
        }

        model_tvReponse->appendRow(elemRep);
        mapTreeReponses.insert(QString::number(elemRep->index().row()), r);
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

    if(index.parent() == QModelIndex()) // l'élément courant n'a pas de parent ; on affiche ses 4 premières images
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
                        if(lm->at(i)->getType() == MEDIA_TYPE_IMAGE) // si le média est une image
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

                // On affiche le nom de la question qui suit la réponse selectionnée

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
                else // c'est une espèce
                {
                    Espece * currentResult = ((Espece *)r->getSuiv());

                    ui->labelReponse2->setText("Résultat");
                    ui->labelImage1->setText("Nom : " + currentResult->getNom());
                    ui->labelImage2->setText("Type : " + currentResult->getType());
                    ui->labelImage3->setText("Régime alimentaire : " + currentResult->getRegimeAlimentaire());
                    ui->labelImage4->setText("Informations : " + currentResult->getInformation());

                    ListeMedia * lm = currentResult->getListeMedia();
                    if(lm->size() != 0) {
                        for(int i = 0; i < lm->size(); i++) {
                            if(lm->at(i)->getType() == MEDIA_TYPE_IMAGE) // si le média est une image
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
                ui->labelReponse2->setText("Cette réponse n'a pas de question associée");
            }
        }
    }
    else
    {
        QString txtCurIdx = model_tvReponse->itemFromIndex(index)->text();
        openMedia(txtCurIdx, 0);
    }
}

void MainWindow::newQuestion()
{
    // Permet d'ajouter une question en tant que fils de la question courante
    Question * newQuestion = new Question(++(BDD::lastId));

    myWindowQues = new ModifQuestionWindow(newQuestion, this);
    myWindowQues->setModal(true);
    int value = myWindowQues->exec();

    if(value == QDialog::Accepted)
    {
        if(newQuestion->getQuestion() != "") // si la question possède un contenu texte, on considère que l'utilisateur a cliqué sur "Annuler"
        {
            QModelIndex index = ui->treeViewQuestion->currentIndex();
            if(index.column() != -1)    {
                QStandardItem * currentSelection = model_tvQuestion->itemFromIndex(index);

                QString s = newQuestion->getQuestion();
                QStandardItem * elem = new QStandardItem(greenIcon, s);

                // On ajoute l'élément en tant que fils de l'élément courant
                currentSelection->appendRow(elem);

                // On calcul les coordonnées du nouveau noeud
                QString coordonnees2 = calculerCoordonnees(elem->index());

                // On récupère la réponse selectionnée
                QModelIndex indexRep = ui->treeViewReponse->currentIndex();
                Reponse * currentReponse = mapTreeReponses.value(QString::number(indexRep.row()));

                // On crée une nouvelle catégorie après la réponse sélectionnée
                Categorie * c = new Categorie(++(BDD::lastId));
                // On ajoute la nouvelle question après cette nouvelle catégorie
                c->ajouterQuestion(newQuestion);
                // On ajoute la catégorie à la réponse courante
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
}

void MainWindow::modifierQuestion()
{
    QModelIndex index = ui->treeViewQuestion->currentIndex();

    // On calcul les coordonnées du noeud courant
    QString coordonnees = calculerCoordonnees(index);
    Question * currentQuestion = mapTreeQuestions.value(coordonnees);

    myWindowQues = new ModifQuestionWindow(currentQuestion, this);
    myWindowQues->setModal(true);
    myWindowQues->exec();

    // On modifie l'item correspondant dans le modèle du TreeView
    QStandardItem * tmp = model_tvQuestion->itemFromIndex(index);
    tmp->setText(currentQuestion->getQuestion());
    model_tvQuestion->setItem(index.row(), tmp);
}

void MainWindow::supprimerQuestion()
{
    int reponse = QMessageBox::question(this, "Supprimer une question", "Etes-vous sur(e) de vouloir supprimer la question \"" + model_tvQuestion->itemFromIndex(ui->treeViewQuestion->currentIndex())->text() + "\" ?", QMessageBox::Yes | QMessageBox::No);

    if(reponse == QMessageBox::Yes)
    {
        QModelIndex index = ui->treeViewQuestion->currentIndex();

        // On calcul les coordonnées du noeud courant
        QString coordonnees = calculerCoordonnees(index);
        Question * currentQuestion = mapTreeQuestions.value(coordonnees);

        // On supprime la question du modèle
        model_tvQuestion->removeRow(index.row(), index.parent());

        // On supprime la question de la mémoire
        // TODO : il faut penser à supprimer tous les fils de la question, les réponses et les médias associés
        ListeQuestion * tmp = currentQuestion->getCat()->getListeQuestion();
        tmp->remove(tmp->indexOf(currentQuestion));
    }
}

void MainWindow::newCommentaire()
{
    myWindowTxt = new TexteWindow("");

    /* Permet de recevoir les QString émit par la QDialog TexteWindow */
    connect(myWindowTxt, SIGNAL(sendContents(QString)), this, SLOT(receiveContents(QString)));

    myWindowTxt->setModal(true);
    int value = myWindowTxt->exec();

    if(value == QDialog::Accepted)
    {
        // Création de l'item avec le texte reçu
        QStandardItem * elem = new QStandardItem("2-" + returnText);
        // On "vide" la variable contenant le texte retourné par la fenêtre
        returnText = "";
        model_tvMediaQuestion->appendRow(elem);

        // Création de l'objet média en mémoire
        Media * newMedia = new Media(++(BDD::lastId));
        newMedia->setPath(returnText);
        newMedia->setType(MEDIA_TYPE_TEXT);

        // On récupère l'index de la question selectionnée dans le TreeView des questions
        QModelIndex index = ui->treeViewQuestion->currentIndex();
        // On calcul les coordonnées du noeud courant
        QString coordonnees = calculerCoordonnees(index);
        // On récupère la question courante
        Question * currentQuestion = mapTreeQuestions.value(coordonnees);

        // On ajoute le média à la question courante
        currentQuestion->getListeMedia()->append(newMedia);
    }
}

void MainWindow::newMedia()
{
    QFileInfo fi = QFileDialog::getOpenFileName(this, tr("Selectionner un média à ajouter"), QDir::currentPath(), tr("Tous les fichiers(*.*)"));
    QString fileName = fi.fileName();

    // Pour connaitre le type de média sélectionné, on regarde son extension
    if(formatImage.contains(fi.suffix()))
    {
        model_tvMediaQuestion->appendRow(new QStandardItem("1-" + fileName));

        QModelIndex index = ui->treeViewQuestion->currentIndex();
        QString coordonnees = calculerCoordonnees(index);
        Question * currentQuestion = mapTreeQuestions.value(coordonnees);

        Media * mImg = new Media(++(BDD::lastId));
        mImg->setPath(fileName);
        mImg->setType(MEDIA_TYPE_IMAGE);
        currentQuestion->ajouterMedia(mImg);
    }
    else if(formatVideo.contains(fi.suffix()))
    {
        model_tvMediaQuestion->appendRow(new QStandardItem("0-" + fileName));

        QModelIndex index = ui->treeViewQuestion->currentIndex();
        QString coordonnees = calculerCoordonnees(index);
        Question * currentQuestion = mapTreeQuestions.value(coordonnees);

        Media * mVid = new Media(++(BDD::lastId));
        mVid->setPath(fileName);
        mVid->setType(MEDIA_TYPE_VIDEO);
        currentQuestion->ajouterMedia(mVid);
    }
    else if(formatAudio.contains(fi.suffix()))
    {
        model_tvMediaQuestion->appendRow(new QStandardItem("3-" + fileName));

        QModelIndex index = ui->treeViewQuestion->currentIndex();
        QString coordonnees = calculerCoordonnees(index);
        Question * currentQuestion = mapTreeQuestions.value(coordonnees);

        Media * mAud = new Media(++(BDD::lastId));
        mAud->setPath(fileName);
        mAud->setType(MEDIA_TYPE_AUDIO);
        currentQuestion->ajouterMedia(mAud);
    }
    else
    {
        QMessageBox::warning(this, "Problème de format de fichier", "Le format du fichier " + fileName + " n'est pas compatible avec l'application.");
    }

    // TODO : tester si le média est présent ou non dans le dossier des médias
    //      SI non, il faut le copier dans le dossier
}

void MainWindow::modifierMedia()
{
    // On modifie l'item correspondant dans le modèle du TreeView
    QModelIndex currentIndex = ui->treeViewMediasQuestion->currentIndex();
    QStandardItem * tmp = model_tvMediaQuestion->itemFromIndex(currentIndex);

    if(tmp->text().startsWith("2")) // si le média sélectionné est un texte
    {
        myWindowTxt = new TexteWindow(tmp->text().split("-")[1]);

        /* Permet de recevoir les QString émit par la QDialog TexteWindow */
        connect(myWindowTxt, SIGNAL(sendContents(QString)), this, SLOT(receiveContents(QString)));

        myWindowTxt->setModal(true);
        myWindowTxt->exec();

        tmp->setText("2-" + returnText);
        model_tvMediaQuestion->setItem(currentIndex.row(), tmp);
    }
    else // si c'est un média "classique"
    {
        QFileInfo fi = QFileDialog::getOpenFileName(this, tr("Selectionner un média à ajouter"), QDir::currentPath(), tr("Tous les fichiers(*.*)"));
        QString fileName = fi.fileName();

        if(formatImage.contains(fi.suffix()))
        {
            tmp->setText("1-" + fileName);
            model_tvMediaQuestion->setItem(currentIndex.row(), tmp);
        }
        else if(formatVideo.contains(fi.suffix()))
        {
            tmp->setText("0-" + fileName);
            model_tvMediaQuestion->setItem(currentIndex.row(), tmp);
        }
        else if(formatAudio.contains(fi.suffix()))
        {
            tmp->setText("3-" + fileName);
            model_tvMediaQuestion->setItem(currentIndex.row(), tmp);
        }
        else
        {
            QMessageBox::warning(this, "Problème de format de fichier", "Le format du fichier " + fileName + " n'est pas compatible avec l'application.");
        }
    }

    // TODO : il faut changer le chemin du média en mémoire

    // TODO : il faudra penser à tester si le média est présent ou non dans le dossier des médias
    //      SI oui, pas de problème
    //      SI non, il faut le copier dans le dossier
}

void MainWindow::supprimerMedia()
{
    int reponse = QMessageBox::question(this, "Supprimer un média", "Etes-vous sur(e) de vouloir supprimer le média \"" + model_tvMediaQuestion->itemFromIndex(ui->treeViewMediasQuestion->currentIndex())->text() + "\" ?", QMessageBox::Yes | QMessageBox::No);

    if(reponse == QMessageBox::Yes)
    {
        QModelIndex currentIndex = ui->treeViewMediasQuestion->currentIndex();
        QStandardItem * tmp = model_tvMediaQuestion->itemFromIndex(currentIndex);
        QString fileName = (tmp->text().split("-"))[1];

        QModelIndex index = ui->treeViewQuestion->currentIndex();
        QString coordonnees = calculerCoordonnees(index);
        Question * currentQuestion = mapTreeQuestions.value(coordonnees);
        ListeMedia * lm = currentQuestion->getListeMedia();

        for(int i = 0; i < lm->size(); i++)
        {
            Media * m = lm->at(i);
            if(m->getPath() == fileName) // On se base sur le nom du fichier pour le supprimer de la liste des médias
            {
                lm->remove(i);
            }
        }

        // On supprime la question du modèle du TreeView
        model_tvMediaQuestion->removeRow(currentIndex.row());

        // TODO : il faut aussi (éventuellement) supprimer le fichier associé
        //QFile::remove("images/" + model_tvMediaQuestion->itemFromIndex(currentIndex)->text());
    }
}

void MainWindow::newReponse()
{
    // Permet d'ajouter une question au même niveau que la question courante à la fin

    Reponse * newReponse = new Reponse(++(BDD::lastId));

    myWindowRep = new ModifReponseWindow(newReponse, this);
    myWindowRep->setModal(true);
    int value = myWindowRep->exec();

    if(value == QDialog::Accepted)
    {
        if(newReponse->getReponse() != "")
        {
            QString s = newReponse->getReponse();

            QStandardItem * elemRep = new QStandardItem(s);
            model_tvReponse->appendRow(elemRep);

            // On récupère la question courante (celle sélectionnée dans le treeview)
            QModelIndex index = ui->treeViewQuestion->currentIndex();
            QString coordonnees = calculerCoordonnees(index);
            Question * currentQuestion = mapTreeQuestions.value(coordonnees);

            // On ajoute la réponse à la liste des réponses de la question courante
            currentQuestion->ajouterReponse(newReponse);

            // On ajoute la réponse à la QMap
            mapTreeReponses.insert(QString::number(elemRep->index().row()), newReponse);
        }
    }
}

void MainWindow::modifierReponse()
{
    QModelIndex index = ui->treeViewReponse->currentIndex();
    Reponse * currentReponse = mapTreeReponses.value(QString::number(index.row()));

    myWindowRep = new ModifReponseWindow(currentReponse, this);
    myWindowRep->setModal(true);
    myWindowRep->exec();

    // On modifie l'item correspondant dans le modèle du TreeView
    QStandardItem * tmp = model_tvReponse->itemFromIndex(index);
    QString s = currentReponse->getReponse();
    tmp->setText(s);
    model_tvReponse->setItem(index.row(), tmp);    
}

void MainWindow::supprimerReponse()
{
    int reponse = QMessageBox::question(this, "Supprimer une réponse", "Etes-vous sur(e) de vouloir supprimer la réponse \"" + model_tvReponse->itemFromIndex(ui->treeViewReponse->currentIndex())->text() + "\" ?", QMessageBox::Yes | QMessageBox::No);

    if(reponse == QMessageBox::Yes)
    {
        // On supprimer la réponse du modèle du treeview
        QModelIndex currentIndex = ui->treeViewReponse->currentIndex();
        model_tvReponse->removeRow(currentIndex.row());

        // On récupère la question courante (celle sélectionnée dans le treeview)
        QModelIndex index = ui->treeViewQuestion->currentIndex();
        QString coordonnees = calculerCoordonnees(index);
        Question * currentQuestion = mapTreeQuestions.value(coordonnees);

        // On supprime la réponse de la mémoire
        Reponse * r = mapTreeReponses.value(QString::number(currentIndex.row()));
        currentQuestion->supprimerReponse(r);

        // On supprime la réponse de la QMap
        mapTreeReponses.remove(QString::number(currentIndex.row()));

        QMessageBox::information(this, "Attention", "Pour éviter des incohérences dans les données, veuillez re-cliquer sur la question courante dans la bandeau de gauche");
    }
}

void MainWindow::newComMediaReponse()
{
    // On récupère la réponse selectionnée
    QModelIndex index = ui->treeViewReponse->currentIndex();
    Reponse * currentReponse = mapTreeReponses.value(QString::number(index.row()));

    if(index.parent() == QModelIndex()) // si l'élément courant n'a pas de parent (= c'est une réponse), alors on peut ajouter une réponse
    {
        myWindowTxt = new TexteWindow("");

        /* Permet de recevoir les QString émit par la QDialog TexteWindow */
        connect(myWindowTxt, SIGNAL(sendContents(QString)), this, SLOT(receiveContents(QString)));

        myWindowTxt->setModal(true);
        int value = myWindowTxt->exec();

        if(value == QDialog::Accepted)
        {
            // Création de l'item avec le texte reçu
            QStandardItem * elem = new QStandardItem("2-" + returnText);
            (model_tvReponse->itemFromIndex(ui->treeViewReponse->currentIndex()))->appendRow(elem);

            // Création de l'objet média en mémoire
            Media * newMedia = new Media(++(BDD::lastId));
            newMedia->setPath(returnText);
            newMedia->setType(MEDIA_TYPE_TEXT);

            // On ajoute le média à la réponse courante
            currentReponse->ajouterMedia(newMedia);
        }
    }
    else
    {
        QMessageBox::warning(this, "Erreur d'insertion d'un nouveau média", "Vous ne pouvez pas ajouter un nouveau média en tant que fils d'un média existant.");
    }
}

void MainWindow::newMediaReponse()
{
    // On récupère la réponse selectionnée
    QModelIndex index = ui->treeViewReponse->currentIndex();
    Reponse * currentReponse = mapTreeReponses.value(QString::number(index.row()));

    if(index.parent() == QModelIndex()) // si l'élément courant n'a pas de parent (= c'est une réponse), alors on peut ajouter une réponse
    {
        QFileInfo fi = QFileInfo(QFileDialog::getOpenFileName(this, tr("Selectionner un média à ajouter"), QDir::currentPath(), tr("Tous les fichiers(*.*)")));
        QString fileName = fi.fileName();

        if(formatImage.contains(fi.suffix()))
        {
            (model_tvReponse->itemFromIndex(ui->treeViewReponse->currentIndex()))->appendRow(new QStandardItem("1-" + fileName));

            Media * m = new Media(++(BDD::lastId));
            m->setPath(fileName);
            m->setType(MEDIA_TYPE_IMAGE);
            currentReponse->ajouterMedia(m);
        }
        else if(formatVideo.contains(fi.suffix()))
        {
            (model_tvReponse->itemFromIndex(ui->treeViewReponse->currentIndex()))->appendRow(new QStandardItem("0-" + fileName));

            Media * m = new Media(++(BDD::lastId));
            m->setPath(fileName);
            m->setType(MEDIA_TYPE_VIDEO);
            currentReponse->ajouterMedia(m);
        }
        else if(formatAudio.contains(fi.suffix()))
        {
            (model_tvReponse->itemFromIndex(ui->treeViewReponse->currentIndex()))->appendRow(new QStandardItem("3-" + fileName));

            Media * m = new Media(++(BDD::lastId));
            m->setPath(fileName);
            m->setType(MEDIA_TYPE_AUDIO);
            currentReponse->ajouterMedia(m);
        }
        else
        {
            QMessageBox::warning(this, "Problème de format de fichier", "Le format du fichier " + fileName + " n'est pas compatible avec l'application.");
        }

        // TODO : tester si le média est présent ou non dans le dossier des médias
        //      SI non, il faut le copier dans le dossier
    }
    else
    {
        QMessageBox::warning(this, "Erreur d'insertion d'un nouveau média", "Vous ne pouvez pas ajouter un nouveau média en tant que fils d'un média existant.");
    }
}

void MainWindow::modifierMediaReponse()
{

}

void MainWindow::supprimerMediaReponse()
{
    int reponse = QMessageBox::question(this, "Supprimer un média", "Etes-vous sur(e) de vouloir supprimer le média \"" + model_tvReponse->itemFromIndex(ui->treeViewReponse->currentIndex())->text() + "\" ?", QMessageBox::Yes | QMessageBox::No);

    if(reponse == QMessageBox::Yes)
    {

    }
}

void MainWindow::newResultat()
{
    Reponse * r = mapTreeReponses.value(QString::number(ui->treeViewReponse->currentIndex().row()));

    if(r->getTypeSuiv() == TYPE_EMPTY)
    {
        Espece * newEspece = new Espece(++(BDD::lastId));

        myWindowResult = new NewResultatWindow(newEspece, this);
        myWindowResult->setModal(true);
        int value = myWindowResult->exec();

        if(value == QDialog::Accepted)
        {
            // On ajoute la nouvelle espèce à la réponse
            r->setSuiv(newEspece);
            r->setTypeSuiv(TYPE_ESPECE);
        }
    }
}

void MainWindow::modifierResultat()
{
    Reponse * r = mapTreeReponses.value(QString::number(ui->treeViewReponse->currentIndex().row()));

    if(r->getTypeSuiv() == TYPE_ESPECE)
    {
        Espece * uneEspece = (Espece *)r->getSuiv();

        myWindowResult = new NewResultatWindow(uneEspece, this);
        myWindowResult->setModal(true);
        int value = myWindowResult->exec();

        if(value == QDialog::Accepted)
        {
            r->setSuiv(uneEspece);
        }
    }
}

void MainWindow::supprimerResultat()
{
    Reponse * r = mapTreeReponses.value(QString::number(ui->treeViewReponse->currentIndex().row()));

    if(r->getTypeSuiv() == TYPE_ESPECE)
    {
        int reponse = QMessageBox::question(this, "Supprimer un résultat", "Etes-vous sur(e) de vouloir supprimer le résultat \"" + ((Espece *)r->getSuiv())->getNom() + "\" ?", QMessageBox::Yes | QMessageBox::No);

        if(reponse == QMessageBox::Yes)
        {
            // On affecte NULL en tant que successeur de la réponse
            r->setSuiv(NULL);
            r->setTypeSuiv(TYPE_EMPTY);
        }
    }
    else
    {
        QMessageBox::warning(this, "Pas de résultat", "La réponse sélectionnée ne possède pas de résultat.");
    }
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
        txtCurIdx.remove(0, 2); // on supprime le chiffre et le tiret représentant le type du media
        playVideo(txtCurIdx);
    }
    else if(txtCurIdx.startsWith("1")) // Media de type MEDIA_TYPE_IMAGE
    {
        txtCurIdx.remove(0, 2);

        QImage * myImg = new QImage("images/" + txtCurIdx);
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
