/**
  * \file videoplayer.cpp
  * \brief Conteneur de la classe videoplayer.
 */
#include "videoplayer.h"
#include "ui_videoplayer.h"

VideoPlayer::VideoPlayer(QString filePath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoPlayer)
{
    ui->setupUi(this);

    // On initialise les attributs utilises par la classe
    sortie = new Phonon::AudioOutput(Phonon::VideoCategory, this);
    mediaObjet = new Phonon::MediaObject(this);
    // playerVideo = new Phonon::VideoPlayer(this);
    monVideoWidget = new Phonon::VideoWidget(this);

    // On donne inclu la vidéo au Layout prévu pour son affichage
    ui->vLayoutVideo->addWidget(monVideoWidget);

    // On initialise le temps de "tick"
    // Grace à cela, on a à SIGNAL qui se fait toute les 1000 millisecondes (soit toutes les secondes)
    mediaObjet->setTickInterval(1000);

    // On initialise l'affichage du LCD Number
    ui->lcdNumber_2->display("00:00");

    // Création des barres d'avancement et de volume
    // on cree la seek slider
    barreAvancement = new Phonon::SeekSlider(this);
    barreAvancement->setMediaObject(mediaObjet);
    ui->vLayoutAvancement_2->addWidget(barreAvancement);

    // on cree la volume slider
    barreVolume = new Phonon::VolumeSlider(this);
    barreVolume->setAudioOutput(sortie);
    ui->hLayoutVolume_2->addWidget(barreVolume);

    // on connecte les fonctions aux signaux
    mediaObjet->setCurrentSource(Phonon::MediaSource(filePath));

    // On relie le MediaObject à ses sorties (audio puis video)
    Phonon::createPath(mediaObjet, sortie);
    Phonon::createPath(mediaObjet, monVideoWidget);

    // Parametrage du VideoWidget
    monVideoWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    monVideoWidget->setScaleMode(Phonon::VideoWidget::ScaleAndCrop);
    monVideoWidget->setAspectRatio(Phonon::VideoWidget::AspectRatioWidget);
    monVideoWidget->installEventFilter(this);

    // On connecte les signaux aux slots pour les boutons PLAY, PAUSE et STOP ainsi que pour le défilement du temps
    connect(ui->btnPlay_2, SIGNAL(clicked()), this, SLOT(playVideo()));

    connect(ui->btnPause_2, SIGNAL(clicked()), this, SLOT(pauseVideo()));

    connect(ui->btnStop_2, SIGNAL(clicked()), this, SLOT(stopVideo()));

    // on relie le media au LCD (temps)
    connect(mediaObjet, SIGNAL(tick(qint64)), this, SLOT(changerTemps()));
}

VideoPlayer::~VideoPlayer()
{
    delete ui;
}

//changerTemps()
void VideoPlayer::changerTemps()
{
    // Initialisation de la variable temps a 0
    qint64 temps = 0;
    // On récupère le temps parcouru dans le media en faisant la différance entre le temps total et le temps restant
    temps = mediaObjet->totalTime() - mediaObjet->remainingTime();

    // on recupere le temps
    QTime monTemps(0, (temps / 60000) % 60, (temps / 1000) % 60);

    // on rentre le temps dans le lcd number
    ui->lcdNumber_2->display(monTemps.toString("mm:ss"));
}

//playVideo()
void VideoPlayer::playVideo()
{
    mediaObjet->play();
}

//pauseVideo()
void VideoPlayer::pauseVideo()
{
    mediaObjet->pause();
}

//stopVideo()
void VideoPlayer::stopVideo()
{
    mediaObjet->stop();
}

void VideoPlayer::closeEvent(QCloseEvent *event)
{
    ui->btnStop_2->click(); // permet d'arrêter la vidéo lorsque l'on ferme la fenêtre
    close();
}

