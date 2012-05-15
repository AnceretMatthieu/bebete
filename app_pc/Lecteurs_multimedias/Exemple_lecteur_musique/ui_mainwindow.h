/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 14. May 09:00:46 2012
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
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vLayoutAvancement;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hLayoutBoutons;
    QPushButton *btnPlay;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *hLayoutVolume;
    QLabel *label;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *vLayoutTemps;
    QLCDNumber *lcdNumber;
    QWidget *formLayoutWidget;
    QFormLayout *fLayoutVideo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 180);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 50, 321, 51));
        vLayoutAvancement = new QVBoxLayout(verticalLayoutWidget);
        vLayoutAvancement->setSpacing(6);
        vLayoutAvancement->setContentsMargins(11, 11, 11, 11);
        vLayoutAvancement->setObjectName(QString::fromUtf8("vLayoutAvancement"));
        vLayoutAvancement->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 100, 179, 80));
        hLayoutBoutons = new QHBoxLayout(horizontalLayoutWidget);
        hLayoutBoutons->setSpacing(6);
        hLayoutBoutons->setContentsMargins(11, 11, 11, 11);
        hLayoutBoutons->setObjectName(QString::fromUtf8("hLayoutBoutons"));
        hLayoutBoutons->setContentsMargins(0, 0, 0, 0);
        btnPlay = new QPushButton(horizontalLayoutWidget);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("img_lecteur/jouer-a-droite-fleche-icone-6822-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlay->setIcon(icon);

        hLayoutBoutons->addWidget(btnPlay);

        btnPause = new QPushButton(horizontalLayoutWidget);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("img_lecteur/pause-icone-4803-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause->setIcon(icon1);

        hLayoutBoutons->addWidget(btnPause);

        btnStop = new QPushButton(horizontalLayoutWidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("img_lecteur/arreter-icone-7083-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon2);

        hLayoutBoutons->addWidget(btnStop);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(240, 100, 160, 80));
        hLayoutVolume = new QHBoxLayout(horizontalLayoutWidget_2);
        hLayoutVolume->setSpacing(6);
        hLayoutVolume->setContentsMargins(11, 11, 11, 11);
        hLayoutVolume->setObjectName(QString::fromUtf8("hLayoutVolume"));
        hLayoutVolume->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("img_lecteur/joueur-volume-icone-9860-32.png")));

        hLayoutVolume->addWidget(label);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(320, 50, 81, 51));
        vLayoutTemps = new QVBoxLayout(verticalLayoutWidget_2);
        vLayoutTemps->setSpacing(6);
        vLayoutTemps->setContentsMargins(11, 11, 11, 11);
        vLayoutTemps->setObjectName(QString::fromUtf8("vLayoutTemps"));
        vLayoutTemps->setContentsMargins(0, 0, 0, 0);
        lcdNumber = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        vLayoutTemps->addWidget(lcdNumber);

        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 401, 51));
        fLayoutVideo = new QFormLayout(formLayoutWidget);
        fLayoutVideo->setSpacing(6);
        fLayoutVideo->setContentsMargins(11, 11, 11, 11);
        fLayoutVideo->setObjectName(QString::fromUtf8("fLayoutVideo"));
        fLayoutVideo->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        btnPlay->setText(QString());
        btnPause->setText(QString());
        btnStop->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
