#include "newreponsewindow.h"
#include "ui_newreponsewindow.h"

NewReponseWindow::NewReponseWindow(Reponse * uneReponse, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewReponseWindow)
{
    ui->setupUi(this);

    maReponse = uneReponse;
}

NewReponseWindow::~NewReponseWindow()
{
    delete ui;
}

void NewReponseWindow::on_buttonBox_accepted()
{
    maReponse->setReponse(ui->textEdit->toPlainText());
}
