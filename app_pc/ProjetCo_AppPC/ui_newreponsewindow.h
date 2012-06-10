/********************************************************************************
** Form generated from reading UI file 'newreponsewindow.ui'
**
** Created: Sun 10. Jun 22:25:59 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWREPONSEWINDOW_H
#define UI_NEWREPONSEWINDOW_H

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

class Ui_NewReponseWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *NewReponseWindow)
    {
        if (NewReponseWindow->objectName().isEmpty())
            NewReponseWindow->setObjectName(QString::fromUtf8("NewReponseWindow"));
        NewReponseWindow->resize(400, 177);
        buttonBox = new QDialogButtonBox(NewReponseWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(NewReponseWindow);
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


        retranslateUi(NewReponseWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewReponseWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewReponseWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewReponseWindow);
    } // setupUi

    void retranslateUi(QDialog *NewReponseWindow)
    {
        NewReponseWindow->setWindowTitle(QApplication::translate("NewReponseWindow", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewReponseWindow", "R\303\251ponse : ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewReponseWindow: public Ui_NewReponseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWREPONSEWINDOW_H
