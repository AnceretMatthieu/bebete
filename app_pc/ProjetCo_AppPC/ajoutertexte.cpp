#include "ajoutertexte.h"
#include "ui_ajoutertexte.h"

AjouterTexte::AjouterTexte(QString * unQString, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterTexte)
{
    ui->setupUi(this);

    monQString = unQString;
}

AjouterTexte::~AjouterTexte()
{
    delete ui;
}

void AjouterTexte::on_buttonBox_accepted()
{

}
