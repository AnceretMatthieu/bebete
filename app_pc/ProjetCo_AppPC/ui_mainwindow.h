/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 30. May 22:25:16 2012
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
    QAction *actionImporter_XML;
    QAction *actionExporter_XML;
    QAction *actionQuitter;
    QAction *actionA_propos_de;
    QAction *actionRecalculer_couleur;
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
    QSpacerItem *verticalSpacer_4;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QLabel *labelQuestion;
    QFrame *line_4;
    QCheckBox *checkBoxVisibleOeil;
    QCheckBox *checkBoxVisibleLoupe;
    QFrame *line_8;
    QLabel *label;
    QFrame *line_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *button_ajouterMediaQuestion;
    QPushButton *button_ajouterComQuestion;
    QHBoxLayout *horizontalLayout_3;
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
    QFrame *line_9;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *button_modifierMediaReponse;
    QPushButton *button_ajouterComMediaReponse;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *button_supprimerMediaReponse;
    QPushButton *button_ajouterMediaReponse;
    QTreeView *treeViewReponse;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelReponse2;
    QFrame *line_6;
    QLabel *labelImage1;
    QLabel *labelImage2;
    QLabel *labelImage3;
    QLabel *labelImage4;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuAide;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1150, 768);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Helvetica Neue"));
        font.setPointSize(14);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/innophyt.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionImporter_XML = new QAction(MainWindow);
        actionImporter_XML->setObjectName(QString::fromUtf8("actionImporter_XML"));
        actionExporter_XML = new QAction(MainWindow);
        actionExporter_XML->setObjectName(QString::fromUtf8("actionExporter_XML"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionA_propos_de = new QAction(MainWindow);
        actionA_propos_de->setObjectName(QString::fromUtf8("actionA_propos_de"));
        actionRecalculer_couleur = new QAction(MainWindow);
        actionRecalculer_couleur->setObjectName(QString::fromUtf8("actionRecalculer_couleur"));
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/icon_modifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_modifierQuestion->setIcon(icon1);

        horizontalLayout_4->addWidget(button_modifierQuestion);

        button_supprimerQuestion = new QPushButton(centralWidget);
        button_supprimerQuestion->setObjectName(QString::fromUtf8("button_supprimerQuestion"));
        button_supprimerQuestion->setFont(font1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/icon_supprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_supprimerQuestion->setIcon(icon2);

        horizontalLayout_4->addWidget(button_supprimerQuestion);


        verticalLayout_4->addLayout(horizontalLayout_4);

        treeViewQuestion = new QTreeView(centralWidget);
        treeViewQuestion->setObjectName(QString::fromUtf8("treeViewQuestion"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeViewQuestion->sizePolicy().hasHeightForWidth());
        treeViewQuestion->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(12);
        treeViewQuestion->setFont(font2);
        treeViewQuestion->setContextMenuPolicy(Qt::DefaultContextMenu);
        treeViewQuestion->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeViewQuestion->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeViewQuestion->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeViewQuestion->setSelectionBehavior(QAbstractItemView::SelectRows);
        treeViewQuestion->setAnimated(true);
        treeViewQuestion->header()->setVisible(false);
        treeViewQuestion->header()->setDefaultSectionSize(500);
        treeViewQuestion->header()->setStretchLastSection(false);

        verticalLayout_4->addWidget(treeViewQuestion);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);


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
        checkBoxVisibleOeil->setEnabled(false);
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
        checkBoxVisibleLoupe->setEnabled(false);
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

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        button_ajouterMediaQuestion = new QPushButton(centralWidget);
        button_ajouterMediaQuestion->setObjectName(QString::fromUtf8("button_ajouterMediaQuestion"));
        button_ajouterMediaQuestion->setFont(font1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("images/icon_ajouter_media.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_ajouterMediaQuestion->setIcon(icon3);

        horizontalLayout_10->addWidget(button_ajouterMediaQuestion);

        button_ajouterComQuestion = new QPushButton(centralWidget);
        button_ajouterComQuestion->setObjectName(QString::fromUtf8("button_ajouterComQuestion"));
        button_ajouterComQuestion->setFont(font1);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("images/icon_ajouter_commentaire.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_ajouterComQuestion->setIcon(icon4);

        horizontalLayout_10->addWidget(button_ajouterComQuestion);


        verticalLayout_6->addLayout(horizontalLayout_10);


        verticalLayout->addLayout(verticalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        button_modifierMediaQuestion = new QPushButton(centralWidget);
        button_modifierMediaQuestion->setObjectName(QString::fromUtf8("button_modifierMediaQuestion"));
        button_modifierMediaQuestion->setFont(font1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("images/icon_modif_media.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_modifierMediaQuestion->setIcon(icon5);

        horizontalLayout_3->addWidget(button_modifierMediaQuestion);

        button_supprimerMediaQuestion = new QPushButton(centralWidget);
        button_supprimerMediaQuestion->setObjectName(QString::fromUtf8("button_supprimerMediaQuestion"));
        button_supprimerMediaQuestion->setFont(font1);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("images/icon_suppr_media.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_supprimerMediaQuestion->setIcon(icon6);

        horizontalLayout_3->addWidget(button_supprimerMediaQuestion);


        verticalLayout->addLayout(horizontalLayout_3);

        treeViewMediasQuestion = new QTreeView(centralWidget);
        treeViewMediasQuestion->setObjectName(QString::fromUtf8("treeViewMediasQuestion"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(treeViewMediasQuestion->sizePolicy().hasHeightForWidth());
        treeViewMediasQuestion->setSizePolicy(sizePolicy3);
        treeViewMediasQuestion->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeViewMediasQuestion->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeViewMediasQuestion->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeViewMediasQuestion->setAnimated(true);
        treeViewMediasQuestion->header()->setVisible(false);
        treeViewMediasQuestion->header()->setDefaultSectionSize(500);
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("images/icon_ajouter.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_ajouterReponse->setIcon(icon7);

        horizontalLayout_5->addWidget(button_ajouterReponse);

        button_modifierReponse = new QPushButton(centralWidget);
        button_modifierReponse->setObjectName(QString::fromUtf8("button_modifierReponse"));
        button_modifierReponse->setFont(font1);
        button_modifierReponse->setIcon(icon1);

        horizontalLayout_5->addWidget(button_modifierReponse);

        button_supprimerReponse = new QPushButton(centralWidget);
        button_supprimerReponse->setObjectName(QString::fromUtf8("button_supprimerReponse"));
        button_supprimerReponse->setFont(font1);
        button_supprimerReponse->setIcon(icon2);

        horizontalLayout_5->addWidget(button_supprimerReponse);


        verticalLayout_2->addLayout(horizontalLayout_5);

        line_9 = new QFrame(centralWidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_9);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        button_modifierMediaReponse = new QPushButton(centralWidget);
        button_modifierMediaReponse->setObjectName(QString::fromUtf8("button_modifierMediaReponse"));
        button_modifierMediaReponse->setFont(font1);
        button_modifierMediaReponse->setIcon(icon3);

        horizontalLayout_8->addWidget(button_modifierMediaReponse);

        button_ajouterComMediaReponse = new QPushButton(centralWidget);
        button_ajouterComMediaReponse->setObjectName(QString::fromUtf8("button_ajouterComMediaReponse"));
        button_ajouterComMediaReponse->setFont(font1);
        button_ajouterComMediaReponse->setIcon(icon4);

        horizontalLayout_8->addWidget(button_ajouterComMediaReponse);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        button_supprimerMediaReponse = new QPushButton(centralWidget);
        button_supprimerMediaReponse->setObjectName(QString::fromUtf8("button_supprimerMediaReponse"));
        button_supprimerMediaReponse->setFont(font1);
        button_supprimerMediaReponse->setIcon(icon5);

        horizontalLayout_7->addWidget(button_supprimerMediaReponse);

        button_ajouterMediaReponse = new QPushButton(centralWidget);
        button_ajouterMediaReponse->setObjectName(QString::fromUtf8("button_ajouterMediaReponse"));
        button_ajouterMediaReponse->setFont(font1);
        button_ajouterMediaReponse->setIcon(icon6);

        horizontalLayout_7->addWidget(button_ajouterMediaReponse);


        verticalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_2->addLayout(verticalLayout_5);

        treeViewReponse = new QTreeView(centralWidget);
        treeViewReponse->setObjectName(QString::fromUtf8("treeViewReponse"));
        sizePolicy.setHeightForWidth(treeViewReponse->sizePolicy().hasHeightForWidth());
        treeViewReponse->setSizePolicy(sizePolicy);
        treeViewReponse->setFont(font2);
        treeViewReponse->setContextMenuPolicy(Qt::DefaultContextMenu);
        treeViewReponse->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeViewReponse->setAnimated(true);
        treeViewReponse->setHeaderHidden(true);
        treeViewReponse->header()->setDefaultSectionSize(500);

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
        labelReponse2 = new QLabel(centralWidget);
        labelReponse2->setObjectName(QString::fromUtf8("labelReponse2"));
        labelReponse2->setFont(font2);

        verticalLayout_3->addWidget(labelReponse2);

        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_6);

        labelImage1 = new QLabel(centralWidget);
        labelImage1->setObjectName(QString::fromUtf8("labelImage1"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("DejaVu Sans"));
        font6.setPointSize(10);
        labelImage1->setFont(font6);

        verticalLayout_3->addWidget(labelImage1);

        labelImage2 = new QLabel(centralWidget);
        labelImage2->setObjectName(QString::fromUtf8("labelImage2"));

        verticalLayout_3->addWidget(labelImage2);

        labelImage3 = new QLabel(centralWidget);
        labelImage3->setObjectName(QString::fromUtf8("labelImage3"));

        verticalLayout_3->addWidget(labelImage3);

        labelImage4 = new QLabel(centralWidget);
        labelImage4->setObjectName(QString::fromUtf8("labelImage4"));

        verticalLayout_3->addWidget(labelImage4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1150, 23));
        menuBar->setFont(font5);
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionImporter_XML);
        menuFichier->addAction(actionExporter_XML);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuAide->addAction(actionA_propos_de);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "INNOPHYT Identificateur - Editeur", 0, QApplication::UnicodeUTF8));
        actionImporter_XML->setText(QApplication::translate("MainWindow", "Importer XML", 0, QApplication::UnicodeUTF8));
        actionExporter_XML->setText(QApplication::translate("MainWindow", "Exporter XML", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionA_propos_de->setText(QApplication::translate("MainWindow", "A propos de", 0, QApplication::UnicodeUTF8));
        actionRecalculer_couleur->setText(QApplication::translate("MainWindow", "Recalculer couleur", 0, QApplication::UnicodeUTF8));
        button_addQuestionFrere->setText(QApplication::translate("MainWindow", "Ajouter un fr\303\250re", 0, QApplication::UnicodeUTF8));
        button_addQuestionFils->setText(QApplication::translate("MainWindow", "Ajouter un fils", 0, QApplication::UnicodeUTF8));
        button_modifierQuestion->setText(QApplication::translate("MainWindow", "Modifier", 0, QApplication::UnicodeUTF8));
        button_supprimerQuestion->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
        labelQuestion->setText(QApplication::translate("MainWindow", "Question", 0, QApplication::UnicodeUTF8));
        checkBoxVisibleOeil->setText(QApplication::translate("MainWindow", "Visible \303\240 l'oeil nu", 0, QApplication::UnicodeUTF8));
        checkBoxVisibleLoupe->setText(QApplication::translate("MainWindow", "Visible \303\240 la loupe", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "M\303\251dias", 0, QApplication::UnicodeUTF8));
        button_ajouterMediaQuestion->setText(QApplication::translate("MainWindow", "Ajouter m\303\251dia", 0, QApplication::UnicodeUTF8));
        button_ajouterComQuestion->setText(QApplication::translate("MainWindow", "Ajouter commentaire", 0, QApplication::UnicodeUTF8));
        button_modifierMediaQuestion->setText(QApplication::translate("MainWindow", "Modifier", 0, QApplication::UnicodeUTF8));
        button_supprimerMediaQuestion->setText(QApplication::translate("MainWindow", "Supprimer", 0, QApplication::UnicodeUTF8));
        lblReponse->setText(QApplication::translate("MainWindow", "R\303\251ponses", 0, QApplication::UnicodeUTF8));
        button_ajouterReponse->setText(QApplication::translate("MainWindow", "Ajouter r\303\251ponse", 0, QApplication::UnicodeUTF8));
        button_modifierReponse->setText(QApplication::translate("MainWindow", "Modifier r\303\251ponse", 0, QApplication::UnicodeUTF8));
        button_supprimerReponse->setText(QApplication::translate("MainWindow", "Supprimer r\303\251ponse", 0, QApplication::UnicodeUTF8));
        button_modifierMediaReponse->setText(QApplication::translate("MainWindow", "Ajouter m\303\251dia", 0, QApplication::UnicodeUTF8));
        button_ajouterComMediaReponse->setText(QApplication::translate("MainWindow", "Ajouter commentaire", 0, QApplication::UnicodeUTF8));
        button_supprimerMediaReponse->setText(QApplication::translate("MainWindow", "Modifier m\303\251dia", 0, QApplication::UnicodeUTF8));
        button_ajouterMediaReponse->setText(QApplication::translate("MainWindow", "Supprimer m\303\251dia", 0, QApplication::UnicodeUTF8));
        labelReponse2->setText(QApplication::translate("MainWindow", "M\303\251dia 1", 0, QApplication::UnicodeUTF8));
        labelImage1->setText(QString());
        labelImage2->setText(QString());
        labelImage3->setText(QString());
        labelImage4->setText(QString());
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
