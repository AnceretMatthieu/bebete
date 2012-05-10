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

    /*
    // Mettre une image dans un QLabel
    ui->labelImage->setPixmap(QPixmap("../Medias_tests/cseptempunctata.jpg"));
    ui->labelImage->adjustSize();
    ui->labelImage->show();

    // Mettre une vidéo dans un babel
    Phonon::VideoPlayer * monLecteur = new Phonon::VideoPlayer(Phonon::VideoCategory);
    QFormLayout * layout = new QFormLayout();
    monLecteur->show();
    monLecteur->play(Phonon::MediaSource("../Medias_tests/test_video.avi"));
    layout->addWidget(monLecteur);
    ui->widgetVideo->setLayout(layout);

    // lecture d'un son
    QSound::play("../Medias_tests/Klaas - Our Own Way (Official Video).wav");
    */
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
    //elem2->appendRow(new QStandardItem(yellowIcon, "Question 2.2"));
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
