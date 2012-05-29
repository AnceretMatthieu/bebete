#ifndef MODIFQUESTIONWINDOW_H
#define MODIFQUESTIONWINDOW_H

#include <QDialog>
#include <QModelIndex>

#include "Question.h"

namespace Ui {
    class ModifQuestionWindow;
}

class ModifQuestionWindow : public QDialog {
        Q_OBJECT

    public:
        ModifQuestionWindow(Question * currentQuestion, QWidget *parent = 0);
        ~ModifQuestionWindow();

        Question * laQuestion;

    protected:
        void changeEvent(QEvent *e);

private slots:
        void on_buttonBox_accepted();

        void on_buttonBox_rejected();

private:
        Ui::ModifQuestionWindow *ui;
};

#endif // MODIFQUESTIONWINDOW_H
