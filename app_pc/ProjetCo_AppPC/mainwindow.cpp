#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QStringListModel * model = new QStringListModel;
    QStringListModel * model2 = new QStringListModel;

    QStringList liste, liste2;

    liste  << "a" << "b" << "c";
    liste2 << "h" << "t" << "o";

    model->setStringList(liste);

    model2->setStringList(liste2);
    model2->setParent(model);

    ui->setupUi(this);

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
