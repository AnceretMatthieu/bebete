#include "newresultatwindow.h"
#include "ui_newresultatwindow.h"

NewResultatWindow::NewResultatWindow(Espece * uneEspece, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewResultatWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(accepted()), this, SLOT(clic_accepted()));
    connect(this, SIGNAL(rejected()), this, SLOT(clic_rejected()));

    monEspece = uneEspece;

    if(uneEspece->getNom() != QString(""))
    {
        ui->editNom->setText(uneEspece->getNom());
        ui->editType->setText(uneEspece->getType());
        ui->editRegimeAlim->setText(uneEspece->getRegimeAlimentaire());
        ui->editInfos->setText(uneEspece->getInformation());
    }
}

NewResultatWindow::~NewResultatWindow()
{
    delete ui;
}

void NewResultatWindow::clic_accepted()
{
    monEspece->setNom(ui->editNom->text());
    monEspece->setType(ui->editType->text());
    monEspece->setRegimeAlimentaire(ui->editRegimeAlim->text());
    monEspece->setInformation(ui->editInfos->text());
}

void NewResultatWindow::clic_rejected()
{
    close();
}
