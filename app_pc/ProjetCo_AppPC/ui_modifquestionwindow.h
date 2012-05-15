/********************************************************************************
** Form generated from reading UI file 'modifquestionwindow.ui'
**
** Created: Tue May 15 08:39:53 2012
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
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifQuestionWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit;
    QLabel *label_4;
    QComboBox *comboBox;

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
        layoutWidget = new QWidget(ModifQuestionWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 365, 230));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox);


        retranslateUi(ModifQuestionWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), ModifQuestionWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ModifQuestionWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(ModifQuestionWindow);
    } // setupUi

    void retranslateUi(QDialog *ModifQuestionWindow)
    {
        ModifQuestionWindow->setWindowTitle(QApplication::translate("ModifQuestionWindow", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ModifQuestionWindow", "ID : ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ModifQuestionWindow", "id_question", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ModifQuestionWindow", "Texte : ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ModifQuestionWindow", "Visibilit\303\251 : ", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ModifQuestionWindow", "A l'oeil nu", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModifQuestionWindow", "A la loupe", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModifQuestionWindow", "Les deux", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class ModifQuestionWindow: public Ui_ModifQuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFQUESTIONWINDOW_H
