#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /* Remplissage TreeView des questions */
    QStringList listeHeader;
    QStandardItemModel * model = new QStandardItemModel(2, 2);
    listeHeader << "Nom" << "Symbole couleur";
    model->setHorizontalHeaderLabels(listeHeader);

    QStandardItem * elem1 = new QStandardItem("Elem 1");
    model->setItem(0, 0, elem1);
    model->setItem(0, 1, new QStandardItem(QIcon("images/icon_green.png"), ""));
    elem1->appendRow(new QStandardItem("Sous-elem 1"));
    elem1->appendRow(new QStandardItem("Sous-elem 2"));

    QStandardItem * elem2 = new QStandardItem("Elem 2");
    model->setItem(1, 0, elem2);
    model->setItem(1, 1, new QStandardItem(QIcon("images/icon_red.png"), ""));
    //elem2->appendRow(new QStandardItem("Sous-elem 3"));
    elem2->appendRow(new QStandardItem(QIcon("images/icon_green.ng"), "Sous-elem 3"));
    elem2->appendRow(new QStandardItem(QIcon("images/icon_yellow.png"), "Sous-elem 31"));
    elem2->appendRow(new QStandardItem(QIcon("images/icon_yellow.png"), "Sous-elem 32"));

    QStandardItem * elem3 = new QStandardItem("Elem 3");
    model->setItem(2, 0, elem3);
    model->setItem(2, 1, new QStandardItem(QIcon("images/icon_yellow.png"), ""));
    elem3->appendRow(new QStandardItem("Sous-elem 4"));
    elem3->appendRow(new QStandardItem("Sous-elem 5"));
    elem3->appendRow(new QStandardItem("Sous-elem 6"));


    /* Remplissage TreeView des reponses */
    QStandardItemModel * model2 = new QStandardItemModel;

    QStandardItem * elem4 = new QStandardItem("Reponse 1");
    model2->appendRow(elem4);

    QStandardItem * elem5 = new QStandardItem("Reponse 2");
    model2->appendRow(elem5);

    QStandardItem * elem6 = new QStandardItem("Reponse 3");
    model2->appendRow(elem6);
    elem6->appendRow(new QStandardItem("aide reponse 3"));
    elem6->appendRow(new QStandardItem("media 1"));

    ui->setupUi(this);

    //ui->treeViewQuestion->header()->hide();
    ui->treeViewQuestion->setModel(model);
    //ui->treeViewQuestion->header()->setMovable(false); // on empeche le deplacement des colonnes
    ui->treeViewQuestion->setEditTriggers(QAbstractItemView::NoEditTriggers); // on empeche la modification

    ui->treeViewReponse->header()->hide();
    ui->treeViewReponse->setModel(model2);

    /* On ouvre le fichier CSS et on l'applique sur le widget QTreeView */
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

    // Mettre une vid�o dans un babel
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

void MainWindow::on_actionImporter_XML_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir le fichier de base de données"), QDir::currentPath(), tr("Fichier XML (*.xml)"));
    std::cout << "Nom du fichier selectionne : " << qPrintable(fileName) << std::endl;
}

void MainWindow::on_actionExporter_XML_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir le fichier de base de données"), QDir::currentPath(), tr("Fichier XML (*.xml)"));
    std::cout << "Nom du fichier selectionne : " << qPrintable(fileName) << std::endl;
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
