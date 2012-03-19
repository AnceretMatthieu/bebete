/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Mar 19 15:24:07 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExporter_XML;
    QAction *actionQuitter;
    QAction *actionImporter_XML;
    QAction *actionA_propos;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QTreeView *qlstArbo;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QLabel *lblQuestion;
    QSpacerItem *verticalSpacer;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblReponse;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblReponse_2;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAffichage;
    QMenu *menuOutils;
    QMenu *menuAide;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 768);
        QFont font;
        font.setFamily(QString::fromUtf8("Helvetica Neue"));
        font.setPointSize(14);
        MainWindow->setFont(font);
        actionExporter_XML = new QAction(MainWindow);
        actionExporter_XML->setObjectName(QString::fromUtf8("actionExporter_XML"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionImporter_XML = new QAction(MainWindow);
        actionImporter_XML->setObjectName(QString::fromUtf8("actionImporter_XML"));
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName(QString::fromUtf8("actionA_propos"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        qlstArbo = new QTreeView(centralWidget);
        qlstArbo->setObjectName(QString::fromUtf8("qlstArbo"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qlstArbo->sizePolicy().hasHeightForWidth());
        qlstArbo->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(qlstArbo);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblQuestion = new QLabel(centralWidget);
        lblQuestion->setObjectName(QString::fromUtf8("lblQuestion"));
        lblQuestion->setEnabled(true);
        sizePolicy1.setHeightForWidth(lblQuestion->sizePolicy().hasHeightForWidth());
        lblQuestion->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(12);
        lblQuestion->setFont(font1);

        verticalLayout->addWidget(lblQuestion);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lblReponse = new QLabel(centralWidget);
        lblReponse->setObjectName(QString::fromUtf8("lblReponse"));
        lblReponse->setFont(font1);

        verticalLayout_2->addWidget(lblReponse);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lblReponse_2 = new QLabel(centralWidget);
        lblReponse_2->setObjectName(QString::fromUtf8("lblReponse_2"));
        lblReponse_2->setFont(font1);

        verticalLayout_3->addWidget(lblReponse_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        QFont font2;
        font2.setPointSize(10);
        menuBar->setFont(font2);
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuAffichage = new QMenu(menuBar);
        menuAffichage->setObjectName(QString::fromUtf8("menuAffichage"));
        menuOutils = new QMenu(menuBar);
        menuOutils->setObjectName(QString::fromUtf8("menuOutils"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuAffichage->menuAction());
        menuBar->addAction(menuOutils->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionImporter_XML);
        menuFichier->addAction(actionExporter_XML);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuAide->addAction(actionA_propos);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Bebete", 0, QApplication::UnicodeUTF8));
        actionExporter_XML->setText(QApplication::translate("MainWindow", "Exporter XML", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionImporter_XML->setText(QApplication::translate("MainWindow", "Importer XML", 0, QApplication::UnicodeUTF8));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", 0, QApplication::UnicodeUTF8));
        lblQuestion->setText(QApplication::translate("MainWindow", "Question", 0, QApplication::UnicodeUTF8));
        lblReponse->setText(QApplication::translate("MainWindow", "R\303\251ponse", 0, QApplication::UnicodeUTF8));
        lblReponse_2->setText(QApplication::translate("MainWindow", "M\303\251dia", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0, QApplication::UnicodeUTF8));
        menuAffichage->setTitle(QApplication::translate("MainWindow", "Affichage", 0, QApplication::UnicodeUTF8));
        menuOutils->setTitle(QApplication::translate("MainWindow", "Outils", 0, QApplication::UnicodeUTF8));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
