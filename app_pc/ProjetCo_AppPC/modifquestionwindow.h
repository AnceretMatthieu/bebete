#ifndef MODIFQUESTIONWINDOW_H
#define MODIFQUESTIONWINDOW_H

#include <QDialog>
#include <QModelIndex>

namespace Ui {
    class ModifQuestionWindow;
}

class ModifQuestionWindow : public QDialog {
        Q_OBJECT

    public:
        ModifQuestionWindow(QModelIndex index, QWidget *parent = 0);
        ~ModifQuestionWindow();

    protected:
        void changeEvent(QEvent *e);

    private:
        Ui::ModifQuestionWindow *ui;
};

#endif // MODIFQUESTIONWINDOW_H
