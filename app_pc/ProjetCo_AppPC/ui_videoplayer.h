/********************************************************************************
** Form generated from reading UI file 'videoplayer.ui'
**
** Created: Tue 5. Jun 13:35:25 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYER_H
#define UI_VIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoPlayer
{
public:
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *vLayoutVideo;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vLayoutAvancement_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *vLayoutTemps_2;
    QLCDNumber *lcdNumber_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hLayoutBoutons_2;
    QPushButton *btnPlay_2;
    QPushButton *btnPause_2;
    QPushButton *btnStop_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *hLayoutVolume_2;
    QLabel *label_2;

    void setupUi(QDialog *VideoPlayer)
    {
        if (VideoPlayer->objectName().isEmpty())
            VideoPlayer->setObjectName(QString::fromUtf8("VideoPlayer"));
        VideoPlayer->resize(400, 393);
        verticalLayoutWidget_3 = new QWidget(VideoPlayer);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 401, 261));
        vLayoutVideo = new QVBoxLayout(verticalLayoutWidget_3);
        vLayoutVideo->setObjectName(QString::fromUtf8("vLayoutVideo"));
        vLayoutVideo->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget = new QWidget(VideoPlayer);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1, 261, 321, 51));
        vLayoutAvancement_2 = new QVBoxLayout(verticalLayoutWidget);
        vLayoutAvancement_2->setObjectName(QString::fromUtf8("vLayoutAvancement_2"));
        vLayoutAvancement_2->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(VideoPlayer);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(321, 261, 81, 51));
        vLayoutTemps_2 = new QVBoxLayout(verticalLayoutWidget_2);
        vLayoutTemps_2->setObjectName(QString::fromUtf8("vLayoutTemps_2"));
        vLayoutTemps_2->setContentsMargins(0, 0, 0, 0);
        lcdNumber_2 = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));

        vLayoutTemps_2->addWidget(lcdNumber_2);

        horizontalLayoutWidget = new QWidget(VideoPlayer);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(1, 311, 179, 80));
        hLayoutBoutons_2 = new QHBoxLayout(horizontalLayoutWidget);
        hLayoutBoutons_2->setObjectName(QString::fromUtf8("hLayoutBoutons_2"));
        hLayoutBoutons_2->setContentsMargins(0, 0, 0, 0);
        btnPlay_2 = new QPushButton(horizontalLayoutWidget);
        btnPlay_2->setObjectName(QString::fromUtf8("btnPlay_2"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/audio_player_play.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlay_2->setIcon(icon);

        hLayoutBoutons_2->addWidget(btnPlay_2);

        btnPause_2 = new QPushButton(horizontalLayoutWidget);
        btnPause_2->setObjectName(QString::fromUtf8("btnPause_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/audio_player_pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause_2->setIcon(icon1);

        hLayoutBoutons_2->addWidget(btnPause_2);

        btnStop_2 = new QPushButton(horizontalLayoutWidget);
        btnStop_2->setObjectName(QString::fromUtf8("btnStop_2"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/audio_player_stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop_2->setIcon(icon2);

        hLayoutBoutons_2->addWidget(btnStop_2);

        horizontalLayoutWidget_2 = new QWidget(VideoPlayer);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(241, 311, 160, 80));
        hLayoutVolume_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        hLayoutVolume_2->setObjectName(QString::fromUtf8("hLayoutVolume_2"));
        hLayoutVolume_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("images/audio_player_volume.png")));

        hLayoutVolume_2->addWidget(label_2);


        retranslateUi(VideoPlayer);

        QMetaObject::connectSlotsByName(VideoPlayer);
    } // setupUi

    void retranslateUi(QDialog *VideoPlayer)
    {
        VideoPlayer->setWindowTitle(QApplication::translate("VideoPlayer", "VideoPlayer", 0, QApplication::UnicodeUTF8));
        btnPlay_2->setText(QString());
        btnPause_2->setText(QString());
        btnStop_2->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoPlayer: public Ui_VideoPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYER_H
