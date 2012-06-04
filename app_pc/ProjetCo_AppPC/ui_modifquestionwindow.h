/********************************************************************************
** Form generated from reading UI file 'modifquestionwindow.ui'
**
** Created: Tue 5. Jun 01:10:23 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFQUESTIONWINDOW_H
#define UI_MODIFQUESTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
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
    QLabel *label_id;
    QLabel *label_3;
    QTextEdit *textEdit;
    QCheckBox *checkBox_visibleOeil;
    QCheckBox *checkBox_visibleLoupe;
    QComboBox *comboBoxReponses;
    QLabel *label_2;

    void setupUi(QDialog *ModifQuestionWindow)
    {
        if (ModifQuestionWindow->objectName().isEmpty())
            ModifQuestionWindow->setObjectName(QString::fromUtf8("ModifQuestionWindow"));
        ModifQuestionWindow->resize(400, 371);
        buttonBox = new QDialogButtonBox(ModifQuestionWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 330, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(ModifQuestionWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 365, 321));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_id = new QLabel(layoutWidget);
        label_id->setObjectName(QString::fromUtf8("label_id"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_id);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit);

        checkBox_visibleOeil = new QCheckBox(layoutWidget);
        checkBox_visibleOeil->setObjectName(QString::fromUtf8("checkBox_visibleOeil"));

        formLayout->setWidget(2, QFormLayout::FieldRole, checkBox_visibleOeil);

        checkBox_visibleLoupe = new QCheckBox(layoutWidget);
        checkBox_visibleLoupe->setObjectName(QString::fromUtf8("checkBox_visibleLoupe"));

        formLayout->setWidget(3, QFormLayout::FieldRole, checkBox_visibleLoupe);

        comboBoxReponses = new QComboBox(layoutWidget);
        comboBoxReponses->setObjectName(QString::fromUtf8("comboBoxReponses"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBoxReponses);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);


        retranslateUi(ModifQuestionWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), ModifQuestionWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ModifQuestionWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(ModifQuestionWindow);
    } // setupUi

    void retranslateUi(QDialog *ModifQuestionWindow)
    {
        ModifQuestionWindow->setWindowTitle(QApplication::translate("ModifQuestionWindow", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ModifQuestionWindow", "ID : ", 0, QApplication::UnicodeUTF8));
        label_id->setText(QApplication::translate("ModifQuestionWindow", "id_question", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ModifQuestionWindow", "Texte : ", 0, QApplication::UnicodeUTF8));
        checkBox_visibleOeil->setText(QApplication::translate("ModifQuestionWindow", "Visible \303\240 l'oeil nu", 0, QApplication::UnicodeUTF8));
        checkBox_visibleLoupe->setText(QApplication::translate("ModifQuestionWindow", "Visible \303\240 la loupe", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ModifQuestionWindow", "R\303\251ponse :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ModifQuestionWindow: public Ui_ModifQuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFQUESTIONWINDOW_H
