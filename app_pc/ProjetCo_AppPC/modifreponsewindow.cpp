#include "modifreponsewindow.h"
#include "ui_modifreponsewindow.h"

ModifReponseWindow::ModifReponseWindow(Reponse * currentReponse, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifReponseWindow)
{
    ui->setupUi(this);

    // On sauvegarde la réponse envoyée par la fenêtre principale
    maReponse = currentReponse;

    if(currentReponse->getReponse() != "")
    {
        ui->label_idReponse->setText(QString::number(currentReponse->getIdentifiant()));
        ui->lineEdit->setText(currentReponse->getReponse());
    }
    else
    {
        ui->label_idReponse->setText(QString::number(currentReponse->getIdentifiant()));
    }

    if(currentReponse->getTypeSuiv() == TYPE_CATEGORIE) // c'est une catégorie
    {
        ListeQuestion * lq = ((Categorie *)(currentReponse->getSuiv()))->getListeQuestion();
        if(lq->size() != 0)
        {
            ui->labelQuestionSuivante->setText(lq->at(0)->getQuestion());
        }
        else
        {
            ui->labelQuestionSuivante->setText("Pas de question suivante...");
        }
    }
    else if(currentReponse->getTypeSuiv() == TYPE_ESPECE) // c'est une espèce
    {
        Espece * currentResult = ((Espece *)currentReponse->getSuiv());
        QString nom = currentResult->getNom();
        ui->labelQuestionSuivante->setText(nom);
    }
    else
    {
        ui->labelQuestionSuivante->setText("Pas de question suivante...");
    }
}

ModifReponseWindow::~ModifReponseWindow()
{
    delete ui;
}

void ModifReponseWindow::on_buttonBox_accepted()
{
    maReponse->setReponse(ui->lineEdit->text());
}
