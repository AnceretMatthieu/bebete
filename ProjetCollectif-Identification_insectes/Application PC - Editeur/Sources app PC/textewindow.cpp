#include "textewindow.h"
#include "ui_textewindow.h"

TexteWindow::TexteWindow(QString str, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::textewindow)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(textewindow_accepted()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(textewindow_rejected()));

    ui->textEdit->setText(str);
}

TexteWindow::~TexteWindow()
{
    delete ui;
}

void TexteWindow::textewindow_accepted()
{
    emit sendContents(ui->textEdit->toPlainText());
    accept();
}

void TexteWindow::textewindow_rejected()
{
    reject();
}
