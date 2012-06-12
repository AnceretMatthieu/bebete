/********************************************************************************
** Form generated from reading UI file 'modifreponsewindow.ui'
**
** Created: Sun 10. Jun 23:17:17 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFREPONSEWINDOW_H
#define UI_MODIFREPONSEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifReponseWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_idReponse;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *labelQuestionSuivante;
    QLineEdit *lineEdit;

    void setupUi(QDialog *ModifReponseWindow)
    {
        if (ModifReponseWindow->objectName().isEmpty())
            ModifReponseWindow->setObjectName(QString::fromUtf8("ModifReponseWindow"));
        ModifReponseWindow->resize(361, 152);
        buttonBox = new QDialogButtonBox(ModifReponseWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 110, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(ModifReponseWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 343, 91));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_idReponse = new QLabel(layoutWidget);
        label_idReponse->setObjectName(QString::fromUtf8("label_idReponse"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_idReponse);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        labelQuestionSuivante = new QLabel(layoutWidget);
        labelQuestionSuivante->setObjectName(QString::fromUtf8("labelQuestionSuivante"));

        formLayout->setWidget(3, QFormLayout::FieldRole, labelQuestionSuivante);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit);


        retranslateUi(ModifReponseWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), ModifReponseWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ModifReponseWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(ModifReponseWindow);
    } // setupUi

    void retranslateUi(QDialog *ModifReponseWindow)
    {
        ModifReponseWindow->setWindowTitle(QApplication::translate("ModifReponseWindow", "Gestion d'une r\303\251ponse", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ModifReponseWindow", "ID : ", 0, QApplication::UnicodeUTF8));
        label_idReponse->setText(QApplication::translate("ModifReponseWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ModifReponseWindow", "Texte r\303\251ponse : ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ModifReponseWindow", "Question suivante : ", 0, QApplication::UnicodeUTF8));
        labelQuestionSuivante->setText(QApplication::translate("ModifReponseWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ModifReponseWindow: public Ui_ModifReponseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFREPONSEWINDOW_H
