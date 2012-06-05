/********************************************************************************
** Form generated from reading UI file 'modifreponsewindow.ui'
**
** Created: Tue Jun 5 11:10:36 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFREPONSEWINDOW_H
#define UI_MODIFREPONSEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifReponseWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_idReponse;
    QLabel *label_2;
    QTextEdit *textEdit;
    QComboBox *comboBox;
    QLabel *label_3;

    void setupUi(QDialog *ModifReponseWindow)
    {
        if (ModifReponseWindow->objectName().isEmpty())
            ModifReponseWindow->setObjectName(QString::fromUtf8("ModifReponseWindow"));
        ModifReponseWindow->resize(361, 237);
        buttonBox = new QDialogButtonBox(ModifReponseWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 190, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(ModifReponseWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 343, 171));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_idReponse = new QLabel(widget);
        label_idReponse->setObjectName(QString::fromUtf8("label_idReponse"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_idReponse);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, textEdit);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);


        retranslateUi(ModifReponseWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), ModifReponseWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ModifReponseWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(ModifReponseWindow);
    } // setupUi

    void retranslateUi(QDialog *ModifReponseWindow)
    {
        ModifReponseWindow->setWindowTitle(QApplication::translate("ModifReponseWindow", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ModifReponseWindow", "ID : ", 0, QApplication::UnicodeUTF8));
        label_idReponse->setText(QApplication::translate("ModifReponseWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ModifReponseWindow", "Texte r\303\251ponse : ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ModifReponseWindow", "Question suivante : ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ModifReponseWindow: public Ui_ModifReponseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFREPONSEWINDOW_H
