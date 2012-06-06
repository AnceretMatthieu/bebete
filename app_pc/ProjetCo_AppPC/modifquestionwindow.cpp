#include "modifquestionwindow.h"
#include "ui_modifquestionwindow.h"

ModifQuestionWindow::ModifQuestionWindow(Question * currentQuestion, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifQuestionWindow)
{
    ui->setupUi(this);

    // On sauvegarde la question envoyée par la fenêtre principale
    laQuestion = currentQuestion;

    // Dans le cas où c'est une modification de question
    if(currentQuestion->getQuestion() != QString())
    {
        this->setWindowTitle("Modifier une question");

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
    else
    {
        this->setWindowTitle("Nouvelle question");
        ui->label_id->setText("Pas d'ID");
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

void ModifQuestionWindow::on_buttonBox_accepted()
{
    laQuestion->setQuestion(ui->textEdit->toPlainText());

    if(ui->checkBox_visibleOeil->checkState() == Qt::Checked)
    {
        if(ui->checkBox_visibleLoupe->checkState() == Qt::Checked)
        {
            laQuestion->setVisible("both");
        }
        else
        {
            laQuestion->setVisible("false");
        }
    }
    else if(ui->checkBox_visibleLoupe->checkState() == Qt::Checked)
    {
        laQuestion->setVisible("true");
    }
    else
    {
        laQuestion->setVisible("");
    }
}

void ModifQuestionWindow::on_buttonBox_rejected()
{
    // L'utilisateur a appuyé sur "Annuler" ==> on ne fait rien
}
