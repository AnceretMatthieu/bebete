#ifndef MODIFREPONSEWINDOW_H
#define MODIFREPONSEWINDOW_H

#include <QDialog>
#include "Reponse.h"
#include "ListeQuestion.h"
#include "Question.h"
#include "Espece.h"

namespace Ui {
    class ModifReponseWindow;
}

class ModifReponseWindow : public QDialog
{
    Q_OBJECT
    
    public:
        explicit ModifReponseWindow(Reponse * currentReponse, QWidget *parent = 0);
        ~ModifReponseWindow();

private slots:
    void on_buttonBox_accepted();

private:
        Ui::ModifReponseWindow *ui;
        Reponse * maReponse;
};

#endif // MODIFREPONSEWINDOW_H
