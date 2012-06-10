#ifndef TEXTEWINDOW_H
#define TEXTEWINDOW_H

#include <QDialog>
#include "QDebug"

namespace Ui {
    class textewindow;
}

class TexteWindow : public QDialog
{
    Q_OBJECT
    
    public:
        explicit TexteWindow(QString str, QWidget *parent = 0);
        ~TexteWindow();

    signals:
        void sendContents(QString);

    private slots:
        void textewindow_accepted();
        void textewindow_rejected();

    private:
        Ui::textewindow *ui;
};

#endif // TEXTEWINDOW_H
