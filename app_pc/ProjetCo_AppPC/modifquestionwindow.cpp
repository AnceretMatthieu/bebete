#include "modifquestionwindow.h"
#include "ui_modifquestionwindow.h"

ModifQuestionWindow::ModifQuestionWindow(QModelIndex index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifQuestionWindow)
{
    //ui->label->setText(index.row() + " - monTexte");

    ui->setupUi(this);
}

ModifQuestionWindow::~ModifQuestionWindow()
{
    delete ui;
}

void ModifQuestionWindow::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
