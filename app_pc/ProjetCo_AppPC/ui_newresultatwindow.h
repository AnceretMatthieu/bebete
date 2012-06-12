/********************************************************************************
** Form generated from reading UI file 'newresultatwindow.ui'
**
** Created: Sun 10. Jun 23:17:17 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWRESULTATWINDOW_H
#define UI_NEWRESULTATWINDOW_H

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

class Ui_NewResultatWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_5;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *editNom;
    QLineEdit *editType;
    QLineEdit *editRegimeAlim;
    QLineEdit *editInfos;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *NewResultatWindow)
    {
        if (NewResultatWindow->objectName().isEmpty())
            NewResultatWindow->setObjectName(QString::fromUtf8("NewResultatWindow"));
        NewResultatWindow->resize(400, 208);
        buttonBox = new QDialogButtonBox(NewResultatWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 170, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_5 = new QLabel(NewResultatWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 381, 21));
        QFont font;
        font.setPointSize(14);
        label_5->setFont(font);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(NewResultatWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 381, 121));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        editNom = new QLineEdit(layoutWidget);
        editNom->setObjectName(QString::fromUtf8("editNom"));

        formLayout->setWidget(0, QFormLayout::FieldRole, editNom);

        editType = new QLineEdit(layoutWidget);
        editType->setObjectName(QString::fromUtf8("editType"));

        formLayout->setWidget(1, QFormLayout::FieldRole, editType);

        editRegimeAlim = new QLineEdit(layoutWidget);
        editRegimeAlim->setObjectName(QString::fromUtf8("editRegimeAlim"));

        formLayout->setWidget(2, QFormLayout::FieldRole, editRegimeAlim);

        editInfos = new QLineEdit(layoutWidget);
        editInfos->setObjectName(QString::fromUtf8("editInfos"));

        formLayout->setWidget(3, QFormLayout::FieldRole, editInfos);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);


        retranslateUi(NewResultatWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewResultatWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewResultatWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewResultatWindow);
    } // setupUi

    void retranslateUi(QDialog *NewResultatWindow)
    {
        NewResultatWindow->setWindowTitle(QApplication::translate("NewResultatWindow", "Gestion d'un r\303\251sultat", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NewResultatWindow", "Esp\303\250ce r\303\251sultat", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewResultatWindow", "Nom : ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewResultatWindow", "Type : ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NewResultatWindow", "R\303\251gime alimentaire : ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NewResultatWindow", "Informations : ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewResultatWindow: public Ui_NewResultatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWRESULTATWINDOW_H
