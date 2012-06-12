#ifndef NEWRESULTATWINDOW_H
#define NEWRESULTATWINDOW_H

#include <QDialog>
#include <QDebug>

#include "Espece.h"

namespace Ui {
class NewResultatWindow;
}

class NewResultatWindow : public QDialog
{
    Q_OBJECT
    
    public:
        explicit NewResultatWindow(Espece * uneEspece, QWidget *parent = 0);
        ~NewResultatWindow();

    private slots:
        void clic_accepted();
        void clic_rejected();

    private:
        Ui::NewResultatWindow *ui;
        Espece * monEspece;
};

#endif // NEWRESULTATWINDOW_H
