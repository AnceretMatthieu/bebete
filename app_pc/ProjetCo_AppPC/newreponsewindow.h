#ifndef NEWREPONSEWINDOW_H
#define NEWREPONSEWINDOW_H

#include <QDialog>
#include "Reponse.h"

namespace Ui {
    class NewReponseWindow;
}

class NewReponseWindow : public QDialog
{
    Q_OBJECT
    
    public:
        explicit NewReponseWindow(Reponse * uneReponse, QWidget *parent = 0);
        ~NewReponseWindow();

    private slots:
        void on_buttonBox_accepted();

    private:
        Ui::NewReponseWindow *ui;

        Reponse * maReponse;
};

#endif // NEWREPONSEWINDOW_H
