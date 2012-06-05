#include "modifquestionwindow.h"
#include "ui_modifquestionwindow.h"

ModifQuestionWindow::ModifQuestionWindow(Question * currentQuestion, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifQuestionWindow)
{
    ui->setupUi(this);

    // On sauvegarde la question envoyée par la fenêtre principale
    laQuestion = currentQuestion;

    if(currentQuestion->getQuestion() != QString())
    {
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

        /*ui->comboBoxReponses->addItem("");
        // On affiche les réponses qui ne pointent pas déjà sur une question
        ListeQuestion * lq = currentQuestion->getCat()->getListeQuestion();
        for(int i = 0; i < lq->size() ; i++) {
            ListeReponse * lr = currentQuestion->getListeReponse();
            for(int j = 0; j < lr->size(); j++) {
                Reponse * tmpr = currentQuestion->getListeReponse()->at(i);
                if(tmpr->getSuiv() == NULL)
                    ui->comboBoxReponses->addItem(QString::number(i) + " - " + tmpr->getReponse());
            }
        }*/
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

    if(ui->checkBox_visibleOeil->checkState() == Qt::Checked && ui->checkBox_visibleLoupe->checkState() == Qt::Checked)
    {
        laQuestion->setVisible("both");
    }
    else if(ui->checkBox_visibleOeil->checkState() == Qt::Checked && ui->checkBox_visibleLoupe->checkState() == Qt::Unchecked)
    {
        laQuestion->setVisible("true");
    }
    else if(ui->checkBox_visibleOeil->checkState() == Qt::Unchecked && ui->checkBox_visibleLoupe->checkState() == Qt::Checked)
    {
        laQuestion->setVisible("false");
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
