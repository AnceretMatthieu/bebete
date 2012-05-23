#include "modifquestionwindow.h"
#include "ui_modifquestionwindow.h"

ModifQuestionWindow::ModifQuestionWindow(Question * currentQuestion, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifQuestionWindow)
{
    ui->setupUi(this);

    // Tester si la question vaut NULL
    // ==> si c'est le cas, c'est une nouvelle question
    // ==> sinon c'est une modification d'une question existante
    // Penser à répercuter les modifications en mémoire

    ui->label_id->setText(QString::number(currentQuestion->getIdentifiant()));
    ui->textEdit->setText(currentQuestion->getQuestion());

    if(currentQuestion->getVisible() == "true")
    {
        ui->checkBox_visibleOeil->setChecked(true);
        ui->checkBox_visibleLoupe->setChecked(false);
    }
    else if(currentQuestion->getVisible() == "false")
    {
        ui->checkBox_visibleOeil->setChecked(false);
        ui->checkBox_visibleLoupe->setChecked(true);
    }
    else if(currentQuestion->getVisible() == "both")
    {
        ui->checkBox_visibleOeil->setChecked(true);
        ui->checkBox_visibleLoupe->setChecked(true);
    }
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
