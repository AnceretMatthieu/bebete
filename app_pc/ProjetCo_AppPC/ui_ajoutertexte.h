/********************************************************************************
** Form generated from reading UI file 'ajoutertexte.ui'
**
** Created: Thu 24. May 19:17:30 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTERTEXTE_H
#define UI_AJOUTERTEXTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AjouterTexte
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;

    void setupUi(QDialog *AjouterTexte)
    {
        if (AjouterTexte->objectName().isEmpty())
            AjouterTexte->setObjectName(QString::fromUtf8("AjouterTexte"));
        AjouterTexte->resize(400, 176);
        buttonBox = new QDialogButtonBox(AjouterTexte);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit = new QTextEdit(AjouterTexte);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 30, 381, 101));

        retranslateUi(AjouterTexte);
        QObject::connect(buttonBox, SIGNAL(accepted()), AjouterTexte, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AjouterTexte, SLOT(reject()));

        QMetaObject::connectSlotsByName(AjouterTexte);
    } // setupUi

    void retranslateUi(QDialog *AjouterTexte)
    {
        AjouterTexte->setWindowTitle(QApplication::translate("AjouterTexte", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AjouterTexte: public Ui_AjouterTexte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERTEXTE_H
