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
    explicit AjouterTexte(QWidget *parent = 0);
    ~AjouterTexte();
    
private:
    Ui::AjouterTexte *ui;
};

#endif // AJOUTERTEXTE_H
