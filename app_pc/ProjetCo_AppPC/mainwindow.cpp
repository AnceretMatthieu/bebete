#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QStandardItemModel * model = new QStandardItemModel;

    QStandardItem * elem1 = new QStandardItem("Element 1");
    model->appendRow(elem1);
    elem1->appendRow(new QStandardItem("Sub-element 1.1"));
    elem1->appendRow(new QStandardItem("Sub-element 1.2"));

    QStandardItem * elem2 = new QStandardItem("Element 2");
    model->appendRow(elem2);

    QStandardItem * elem3 = new QStandardItem("Element 3");
    model->appendRow(elem3);
    elem3->appendRow(new QStandardItem("Sub-element 3.1"));
    elem3->appendRow(new QStandardItem("Sub-element 3.2"));
    elem3->appendRow(new QStandardItem("Sub-element 3.3"));

    ui->setupUi(this);

    ui->qlstArbo->header()->hide();
    ui->qlstArbo->setModel(model);
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
    /* On envoi l'évènement "fermer la fenêtre" qui sera traitée par la fonction "closeEvent()" */

    close();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    /* Traitement de l'évènement "fermer la fenêtre" */

    int reponse = QMessageBox::question(this, "Quitter", "Etes-vous sur(e) de vouloir quitter ?", QMessageBox::Yes | QMessageBox::No);

    if(reponse == QMessageBox::Yes) {
        event->accept();
    }
    else if (reponse == QMessageBox::No) {
        event->ignore();
    }
}
