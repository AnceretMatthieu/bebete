/********************************************************************************
** Form generated from reading UI file 'ajoutertexte.ui'
**
** Created: Mon 4. Jun 22:11:17 2012
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
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AjouterTexte
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *AjouterTexte)
    {
        if (AjouterTexte->objectName().isEmpty())
            AjouterTexte->setObjectName(QString::fromUtf8("AjouterTexte"));
        AjouterTexte->resize(400, 177);
        buttonBox = new QDialogButtonBox(AjouterTexte);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(AjouterTexte);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 381, 121));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textEdit);


        retranslateUi(AjouterTexte);
        QObject::connect(buttonBox, SIGNAL(accepted()), AjouterTexte, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AjouterTexte, SLOT(reject()));

        QMetaObject::connectSlotsByName(AjouterTexte);
    } // setupUi

    void retranslateUi(QDialog *AjouterTexte)
    {
        AjouterTexte->setWindowTitle(QApplication::translate("AjouterTexte", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AjouterTexte", "R\303\251ponse : ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AjouterTexte: public Ui_AjouterTexte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTERTEXTE_H
