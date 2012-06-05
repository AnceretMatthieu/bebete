#include "modifreponsewindow.h"
#include "ui_modifreponsewindow.h"

ModifReponseWindow::ModifReponseWindow(Reponse * currentReponse, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifReponseWindow)
{
    ui->setupUi(this);

    // On sauvegarde la r�ponse envoy�e par la fen�tre principale
    maReponse = currentReponse;

    // Tester si la r�ponse vaut NULL
    // ==> si c'est le cas, c'est une nouvelle r�ponse
    // ==> sinon c'est une modification d'une r�ponse existante
    // Penser � r�percuter les modifications en m�moire
    if(currentReponse->getReponse() != "")
    {
        ui->label_idReponse->setText(QString::number(currentReponse->getIdentifiant()));
        ui->textEdit->setText(currentReponse->getReponse());
    }

    if(currentReponse->getTypeSuiv() == TYPE_CATEGORIE) // c'est une cat�gorie
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
    else if(currentReponse->getTypeSuiv() == TYPE_ESPECE) // c'est une esp�ce
    {
        Espece * currentResult = ((Espece *)currentReponse->getSuiv());
        QString nom = currentResult->getNom();
        ui->labelQuestionSuivante->setText(nom);
    }
    else
    {

    }
}

ModifReponseWindow::~ModifReponseWindow()
{
    delete ui;
}

void ModifReponseWindow::on_buttonBox_accepted()
{
    maReponse->setReponse(ui->textEdit->toPlainText());
}
