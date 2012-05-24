#include "ajoutertexte.h"
#include "ui_ajoutertexte.h"

AjouterTexte::AjouterTexte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterTexte)
{
    ui->setupUi(this);
}

AjouterTexte::~AjouterTexte()
{
    delete ui;
}
