/********************************************************************************
** Form generated from reading UI file 'audioplayer.ui'
**
** Created: Tue Jun 5 11:10:36 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOPLAYER_H
#define UI_AUDIOPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioPlayer
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hLayoutBoutons;
    QPushButton *btnPlay;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *hLayoutVolume;
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *fLayoutVideo;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *vLayoutAvancement;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *vLayoutTemps;
    QLCDNumber *lcdNumber;

    void setupUi(QDialog *AudioPlayer)
    {
        if (AudioPlayer->objectName().isEmpty())
            AudioPlayer->setObjectName(QString::fromUtf8("AudioPlayer"));
        AudioPlayer->resize(400, 180);
        horizontalLayoutWidget = new QWidget(AudioPlayer);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 100, 179, 80));
        hLayoutBoutons = new QHBoxLayout(horizontalLayoutWidget);
        hLayoutBoutons->setObjectName(QString::fromUtf8("hLayoutBoutons"));
        hLayoutBoutons->setContentsMargins(0, 0, 0, 0);
        btnPlay = new QPushButton(horizontalLayoutWidget);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/audio_player_play.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlay->setIcon(icon);

        hLayoutBoutons->addWidget(btnPlay);

        btnPause = new QPushButton(horizontalLayoutWidget);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/audio_player_pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause->setIcon(icon1);

        hLayoutBoutons->addWidget(btnPause);

        btnStop = new QPushButton(horizontalLayoutWidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/audio_player_stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon2);

        hLayoutBoutons->addWidget(btnStop);

        horizontalLayoutWidget_2 = new QWidget(AudioPlayer);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(240, 100, 160, 80));
        hLayoutVolume = new QHBoxLayout(horizontalLayoutWidget_2);
        hLayoutVolume->setObjectName(QString::fromUtf8("hLayoutVolume"));
        hLayoutVolume->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("images/audio_player_volume.png")));

        hLayoutVolume->addWidget(label);

        formLayoutWidget = new QWidget(AudioPlayer);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 401, 51));
        fLayoutVideo = new QFormLayout(formLayoutWidget);
        fLayoutVideo->setObjectName(QString::fromUtf8("fLayoutVideo"));
        fLayoutVideo->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_3 = new QWidget(AudioPlayer);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 50, 321, 51));
        vLayoutAvancement = new QVBoxLayout(verticalLayoutWidget_3);
        vLayoutAvancement->setObjectName(QString::fromUtf8("vLayoutAvancement"));
        vLayoutAvancement->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_4 = new QWidget(AudioPlayer);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(320, 50, 81, 51));
        vLayoutTemps = new QVBoxLayout(verticalLayoutWidget_4);
        vLayoutTemps->setObjectName(QString::fromUtf8("vLayoutTemps"));
        vLayoutTemps->setContentsMargins(0, 0, 0, 0);
        lcdNumber = new QLCDNumber(verticalLayoutWidget_4);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        vLayoutTemps->addWidget(lcdNumber);


        retranslateUi(AudioPlayer);

        QMetaObject::connectSlotsByName(AudioPlayer);
    } // setupUi

    void retranslateUi(QDialog *AudioPlayer)
    {
        AudioPlayer->setWindowTitle(QApplication::translate("AudioPlayer", "AudioPlayer", 0, QApplication::UnicodeUTF8));
        btnPlay->setText(QString());
        btnPause->setText(QString());
        btnStop->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AudioPlayer: public Ui_AudioPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOPLAYER_H
