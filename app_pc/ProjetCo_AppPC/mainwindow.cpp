#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /* Remplissage TreeView des questions */
    QStandardItemModel * model = new QStandardItemModel;

    QStandardItem * elem1 = new QStandardItem("Question 1");
    model->appendRow(elem1);
    elem1->appendRow(new QStandardItem("Question 1.1"));
    elem1->appendRow(new QStandardItem("Question 1.2"));

    QStandardItem * elem2 = new QStandardItem("Question 2");
    model->appendRow(elem2);

    QStandardItem * elem3 = new QStandardItem("Question 3");
    model->appendRow(elem3);
    elem3->appendRow(new QStandardItem("Question 3.1"));
    elem3->appendRow(new QStandardItem("Question 3.2"));
    elem3->appendRow(new QStandardItem("Question 3.3"));

    /* Remplissage TreeView des réponses */
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

    ui->treeViewQuestion->header()->hide();
    ui->treeViewQuestion->setModel(model);

    ui->treeViewReponse->header()->hide();
    ui->treeViewReponse->setModel(model2);

    /* On ouvre le fichier CSS et on l'applique sur le widget QTreeView */
    QFile styleFile("style_qtreeview.css");
    styleFile.open(QFile::ReadOnly);

    QString style(styleFile.readAll());
    ui->treeViewQuestion->setStyleSheet(style);

    /* Affectation des actions aux boutons du menu */
    connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(on_actionApropos()));

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
