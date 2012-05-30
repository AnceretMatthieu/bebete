#include "modifreponsewindow.h"
#include "ui_modifreponsewindow.h"

ModifReponseWindow::ModifReponseWindow(Reponse * currentReponse, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifReponseWindow)
{
    ui->setupUi(this);

    // On sauvegarde la réponse envoyée par la fenêtre principale
    maReponse = currentReponse;

    // Tester si la réponse vaut NULL
    // ==> si c'est le cas, c'est une nouvelle réponse
    // ==> sinon c'est une modification d'une réponse existante
    // Penser à répercuter les modifications en mémoire
    if(currentReponse->getReponse() != QString())
    {
        ui->label_idReponse->setText(QString::number(currentReponse->getIdentifiant()));
        ui->textEdit->setText(currentReponse->getReponse());
    }

    // On remplie la comboBox des questions possibles
    ListeQuestion * lq = ((Categorie *)currentReponse->getSuiv())->getListeQuestion();
    for(int i = 0; i < lq->size(); i++)
    {
        // TODO : lq->at(0) suffirait probablement car on ne veut que le suivant
        // Il faudrait pouvoir afficher toutes les questions possibles et afficher la question courante suivante en premier
        Question * q = lq->at(i);
        ui->comboBox->addItem(q->getQuestion());
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
