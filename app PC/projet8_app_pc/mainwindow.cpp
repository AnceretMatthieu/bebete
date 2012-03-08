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
