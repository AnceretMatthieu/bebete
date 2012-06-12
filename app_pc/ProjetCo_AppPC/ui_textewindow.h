/********************************************************************************
** Form generated from reading UI file 'textewindow.ui'
**
** Created: Sun 10. Jun 23:19:09 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEWINDOW_H
#define UI_TEXTEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_textewindow
{
public:
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *textewindow)
    {
        if (textewindow->objectName().isEmpty())
            textewindow->setObjectName(QString::fromUtf8("textewindow"));
        textewindow->resize(400, 175);
        textEdit = new QTextEdit(textewindow);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 381, 121));
        buttonBox = new QDialogButtonBox(textewindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(230, 140, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(textewindow);

        QMetaObject::connectSlotsByName(textewindow);
    } // setupUi

    void retranslateUi(QDialog *textewindow)
    {
        textewindow->setWindowTitle(QApplication::translate("textewindow", "Gestion d'un commentaire", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class textewindow: public Ui_textewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEWINDOW_H
