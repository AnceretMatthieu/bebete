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

    /* Affectation des actions aux boutons du menu */
    connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(on_actionApropos()));
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
