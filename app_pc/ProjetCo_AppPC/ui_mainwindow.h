/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 24. May 00:11:27 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
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
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *button_addQuestionFrere;
    QPushButton *button_addQuestionFils;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *button_modifierQuestion;
    QPushButton *button_supprimerQuestion;
    QTreeView *treeViewQuestion;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QLabel *labelQuestion;
    QFrame *line_4;
    QCheckBox *checkBoxVisibleOeil;
    QCheckBox *checkBoxVisibleLoupe;
    QFrame *line_8;
    QLabel *label;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *button_ajouterMediaQuestion;
    QPushButton *button_modifierMediaQuestion;
    QPushButton *button_supprimerMediaQuestion;
    QTreeView *treeViewMediasQuestion;
    QSpacerItem *verticalSpacer;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblReponse;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *button_ajouterReponse;
    QPushButton *button_modifierReponse;
    QPushButton *button_supprimerReponse;
    QTreeView *treeViewReponse;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblReponse_2;
    QFrame *line_6;
    QLabel *labelImage;
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
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
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
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        button_addQuestionFrere = new QPushButton(centralWidget);
        button_addQuestionFrere->setObjectName(QString::fromUtf8("button_addQuestionFrere"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(10);
        button_addQuestionFrere->setFont(font1);

        horizontalLayout_6->addWidget(button_addQuestionFrere);

        button_addQuestionFils = new QPushButton(centralWidget);
        button_addQuestionFils->setObjectName(QString::fromUtf8("button_addQuestionFils"));
        button_addQuestionFils->setFont(font1);

        horizontalLayout_6->addWidget(button_addQuestionFils);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        button_modifierQuestion = new QPushButton(centralWidget);
        button_modifierQuestion->setObjectName(QString::fromUtf8("button_modifierQuestion"));
        button_modifierQuestion->setFont(font1);

        horizontalLayout_4->addWidget(button_modifierQuestion);

        button_supprimerQuestion = new QPushButton(centralWidget);
        button_supprimerQuestion->setObjectName(QString::fromUtf8("button_supprimerQuestion"));
        button_supprimerQuestion->setFont(font1);

        horizontalLayout_4->addWidget(button_supprimerQuestion);


        verticalLayout_4->addLayout(horizontalLayout_4);

        treeViewQuestion = new QTreeView(centralWidget);
        treeViewQuestion->setObjectName(QString::fromUtf8("treeViewQuestion"));
        sizePolicy.setHeightForWidth(treeViewQuestion->sizePolicy().hasHeightForWidth());
        treeViewQuestion->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(12);
        treeViewQuestion->setFont(font2);
        treeViewQuestion->setContextMenuPolicy(Qt::CustomContextMenu);
        treeViewQuestion->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeViewQuestion->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_4->addWidget(treeViewQuestion);


        horizontalLayout_2->addLayout(verticalLayout_4);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        QFont font3;
        font3.setBold(false);
        font3.setWeight(50);
        line->setFont(font3);
        line->setFrameShadow(QFrame::Sunken);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout_2->addWidget(line);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelQuestion = new QLabel(centralWidget);
        labelQuestion->setObjectName(QString::fromUtf8("labelQuestion"));
        labelQuestion->setEnabled(true);
        sizePolicy.setHeightForWidth(labelQuestion->sizePolicy().hasHeightForWidth());
        labelQuestion->setSizePolicy(sizePolicy);
        labelQuestion->setFont(font2);

        verticalLayout->addWidget(labelQuestion);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        checkBoxVisibleOeil = new QCheckBox(centralWidget);
        checkBoxVisibleOeil->setObjectName(QString::fromUtf8("checkBoxVisibleOeil"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        checkBoxVisibleOeil->setFont(font4);
        checkBoxVisibleOeil->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(checkBoxVisibleOeil);

        checkBoxVisibleLoupe = new QCheckBox(centralWidget);
        checkBoxVisibleLoupe->setObjectName(QString::fromUtf8("checkBoxVisibleLoupe"));
        checkBoxVisibleLoupe->setFont(font4);

        verticalLayout->addWidget(checkBoxVisibleLoupe);

        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_8);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font5;
        font5.setPointSize(10);
        label->setFont(font5);

        verticalLayout->addWidget(label);

        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        button_ajouterMediaQuestion = new QPushButton(centralWidget);
        button_ajouterMediaQuestion->setObjectName(QString::fromUtf8("button_ajouterMediaQuestion"));
        button_ajouterMediaQuestion->setFont(font1);

        horizontalLayout_3->addWidget(button_ajouterMediaQuestion);

        button_modifierMediaQuestion = new QPushButton(centralWidget);
        button_modifierMediaQuestion->setObjectName(QString::fromUtf8("button_modifierMediaQuestion"));
        button_modifierMediaQuestion->setFont(font1);

        horizontalLayout_3->addWidget(button_modifierMediaQuestion);

        button_supprimerMediaQuestion = new QPushButton(centralWidget);
        button_supprimerMediaQuestion->setObjectName(QString::fromUtf8("button_supprimerMediaQuestion"));
        button_supprimerMediaQuestion->setFont(font1);

        horizontalLayout_3->addWidget(button_supprimerMediaQuestion);


        verticalLayout->addLayout(horizontalLayout_3);

        treeViewMediasQuestion = new QTreeView(centralWidget);
        treeViewMediasQuestion->setObjectName(QString::fromUtf8("treeViewMediasQuestion"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeViewMediasQuestion->sizePolicy().hasHeightForWidth());
        treeViewMediasQuestion->setSizePolicy(sizePolicy2);
        treeViewMediasQuestion->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeViewMediasQuestion->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeViewMediasQuestion->setAnimated(false);
        treeViewMediasQuestion->header()->setMinimumSectionSize(25);

        verticalLayout->addWidget(treeViewMediasQuestion);

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
        lblReponse->setFont(font2);

        verticalLayout_2->addWidget(lblReponse);

        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        button_ajouterReponse = new QPushButton(centralWidget);
        button_ajouterReponse->setObjectName(QString::fromUtf8("button_ajouterReponse"));
        button_ajouterReponse->setFont(font1);

        horizontalLayout_5->addWidget(button_ajouterReponse);

        button_modifierReponse = new QPushButton(centralWidget);
        button_modifierReponse->setObjectName(QString::fromUtf8("button_modifierReponse"));
        button_modifierReponse->setFont(font1);

        horizontalLayout_5->addWidget(button_modifierReponse);

        button_supprimerReponse = new QPushButton(centralWidget);
        button_supprimerReponse->setObjectName(QString::fromUtf8("button_supprimerReponse"));
        button_supprimerReponse->setFont(font1);

        horizontalLayout_5->addWidget(button_supprimerReponse);


        verticalLayout_2->addLayout(horizontalLayout_5);

        treeViewReponse = new QTreeView(centralWidget);
        treeViewReponse->setObjectName(QString::fromUtf8("treeViewReponse"));
        sizePolicy.setHeightForWidth(treeViewReponse->sizePolicy().hasHeightForWidth());
        treeViewReponse->setSizePolicy(sizePolicy);
        treeViewReponse->setFont(font2);
        treeViewReponse->setContextMenuPolicy(Qt::CustomContextMenu);

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
        lblReponse_2->setFont(font2);

        verticalLayout_3->addWidget(lblReponse_2);

        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_6);

        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("DejaVu Sans"));
        font6.setPointSize(10);
        labelImage->setFont(font6);

        verticalLayout_3->addWidget(labelImage);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 23));
        menuBar->setFont(font5);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "INNOPHYT Identificateur - Editeur", 0, QApplication::UnicodeUTF8));
        actionExporter_XML->setText(QApplication::translate("MainWindow", "Exporter XML", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionImporter_XML->setText(QApplication::translate("MainWindow", "Importer XML", 0, QApplication::UnicodeUTF8));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", 0, QApplication::UnicodeUTF8));
        button_addQuestionFrere->setText(QApplication::translate("MainWindow", "Ajouter un fr\303\250re", 0, QApplication::UnicodeUTF8));
        button_addQuestionFils->setText(QApplication::translate("MainWindow", "Ajouter un fils", 0, QApplication::UnicodeUTF8));
        button_modifierQuestion->setText(QApplication::translate("MainWindow", "Modifier", 0, QApplication::UnicodeUTF8));
        button_supprimerQuestion->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
        labelQuestion->setText(QApplication::translate("MainWindow", "Question", 0, QApplication::UnicodeUTF8));
        checkBoxVisibleOeil->setText(QApplication::translate("MainWindow", "Visible \303\240 l'oeil nu", 0, QApplication::UnicodeUTF8));
        checkBoxVisibleLoupe->setText(QApplication::translate("MainWindow", "Visible \303\240 la loupe", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "M\303\251dias", 0, QApplication::UnicodeUTF8));
        button_ajouterMediaQuestion->setText(QApplication::translate("MainWindow", "Ajouter", 0, QApplication::UnicodeUTF8));
        button_modifierMediaQuestion->setText(QApplication::translate("MainWindow", "Modifier", 0, QApplication::UnicodeUTF8));
        button_supprimerMediaQuestion->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
        lblReponse->setText(QApplication::translate("MainWindow", "R\303\251ponses", 0, QApplication::UnicodeUTF8));
        button_ajouterReponse->setText(QApplication::translate("MainWindow", "Ajouter", 0, QApplication::UnicodeUTF8));
        button_modifierReponse->setText(QApplication::translate("MainWindow", "Modifier", 0, QApplication::UnicodeUTF8));
        button_supprimerReponse->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
        lblReponse_2->setText(QApplication::translate("MainWindow", "M\303\251dia 1", 0, QApplication::UnicodeUTF8));
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
