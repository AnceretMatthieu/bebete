/********************************************************************************
** Form generated from reading UI file 'modifquestionwindow.ui'
**
** Created: Mon May 14 09:52:27 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFQUESTIONWINDOW_H
#define UI_MODIFQUESTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ModifQuestionWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *ModifQuestionWindow)
    {
        if (ModifQuestionWindow->objectName().isEmpty())
            ModifQuestionWindow->setObjectName(QString::fromUtf8("ModifQuestionWindow"));
        ModifQuestionWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(ModifQuestionWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(ModifQuestionWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 371, 16));
        textEdit = new QTextEdit(ModifQuestionWindow);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 40, 381, 141));

        retranslateUi(ModifQuestionWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), ModifQuestionWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ModifQuestionWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(ModifQuestionWindow);
    } // setupUi

    void retranslateUi(QDialog *ModifQuestionWindow)
    {
        ModifQuestionWindow->setWindowTitle(QApplication::translate("ModifQuestionWindow", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ModifQuestionWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ModifQuestionWindow: public Ui_ModifQuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFQUESTIONWINDOW_H
