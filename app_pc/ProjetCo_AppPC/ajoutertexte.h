#ifndef AJOUTERTEXTE_H
#define AJOUTERTEXTE_H

#include <QDialog>

namespace Ui {
class AjouterTexte;
}

class AjouterTexte : public QDialog
{
    Q_OBJECT
    
public:
    explicit AjouterTexte(QString * unQString, QWidget *parent = 0);
    ~AjouterTexte();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::AjouterTexte *ui;

    QString * monQString;
};

#endif // AJOUTERTEXTE_H
