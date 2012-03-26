/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 26. Mar 15:57:51 2012
**      by: Qt User Interface Compiler version 4.8.0
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
    QTreeView *treeViewQuestion;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QLabel *lblQuestion;
    QFrame *line_4;
    QLabel *label;
    QFrame *line_7;
    QSpacerItem *verticalSpacer;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblReponse;
    QFrame *line_5;
    QTreeView *treeViewReponse;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblReponse_2;
    QFrame *line_6;
    QLabel *labelImage;
    QWidget *widgetVideo;
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
        treeViewQuestion = new QTreeView(centralWidget);
        treeViewQuestion->setObjectName(QString::fromUtf8("treeViewQuestion"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeViewQuestion->sizePolicy().hasHeightForWidth());
        treeViewQuestion->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(12);
        treeViewQuestion->setFont(font1);

        horizontalLayout_2->addWidget(treeViewQuestion);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        QFont font2;
        font2.setBold(false);
        font2.setWeight(50);
        line->setFont(font2);
        line->setFrameShadow(QFrame::Sunken);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout_2->addWidget(line);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblQuestion = new QLabel(centralWidget);
        lblQuestion->setObjectName(QString::fromUtf8("lblQuestion"));
        lblQuestion->setEnabled(true);
        sizePolicy1.setHeightForWidth(lblQuestion->sizePolicy().hasHeightForWidth());
        lblQuestion->setSizePolicy(sizePolicy1);
        lblQuestion->setFont(font1);

        verticalLayout->addWidget(lblQuestion);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font3;
        font3.setPointSize(10);
        label->setFont(font3);

        verticalLayout->addWidget(label);

        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_7);

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

        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_5);

        treeViewReponse = new QTreeView(centralWidget);
        treeViewReponse->setObjectName(QString::fromUtf8("treeViewReponse"));
        sizePolicy1.setHeightForWidth(treeViewReponse->sizePolicy().hasHeightForWidth());
        treeViewReponse->setSizePolicy(sizePolicy1);
        treeViewReponse->setFont(font1);

        verticalLayout_2->addWidget(treeViewReponse);

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

        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_6);

        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));

        verticalLayout_3->addWidget(labelImage);

        widgetVideo = new QWidget(centralWidget);
        widgetVideo->setObjectName(QString::fromUtf8("widgetVideo"));

        verticalLayout_3->addWidget(widgetVideo);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 23));
        menuBar->setFont(font3);
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
        label->setText(QApplication::translate("MainWindow", "M\303\251dia", 0, QApplication::UnicodeUTF8));
        lblReponse->setText(QApplication::translate("MainWindow", "R\303\251ponse", 0, QApplication::UnicodeUTF8));
        lblReponse_2->setText(QApplication::translate("MainWindow", "M\303\251dia", 0, QApplication::UnicodeUTF8));
        labelImage->setText(QString());
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
