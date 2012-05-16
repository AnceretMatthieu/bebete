#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /**
      * on initialise les attributs utilises par la classe
    **/
    sortie = new Phonon::AudioOutput(Phonon::VideoCategory, this);
    mediaObjet = new Phonon::MediaObject(this);
    // playerVideo = new Phonon::VideoPlayer(this);
    monVideoWidget = new Phonon::VideoWidget(this);

    /**
      * On donne inclu la vidéo au Layout prévu pour son affichage
    **/
    ui->vLayoutVideo->addWidget(monVideoWidget);

    /**
      * On initialise le temps de "tick"
      * Grace à cela, on a à SIGNAL qui se fait toute les 1000 millisecondes (soit toutes les secondes)
    **/
    mediaObjet->setTickInterval(1000);

    /**
      * On initialise l'affichage du LCD Number
    **/
    ui->lcdNumber->display("00:00");

    /**
      * création des barres d'avancement et de volume
    **/
    // on cree la seek slider
    barreAvancement = new Phonon::SeekSlider(this);
    barreAvancement->setMediaObject(mediaObjet);
    ui->vLayoutAvancement->addWidget(barreAvancement);

    // on cree la volume slider
    barreVolume = new Phonon::VolumeSlider(this);
    barreVolume->setAudioOutput(sortie);
    ui->hLayoutVolume->addWidget(barreVolume);

    // on connecte les fonctions aux signaux
    mediaObjet->setCurrentSource(Phonon::MediaSource("img_lecteur/test_video.avi"));

    /**
      * On relie le MediaObject à ses sorties (audio puis video)
    **/
    Phonon::createPath(mediaObjet, sortie);
    Phonon::createPath(mediaObjet, monVideoWidget);

    /**
      * Parametrage du VideoWidget
    **/
    monVideoWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    monVideoWidget->setScaleMode(Phonon::VideoWidget::ScaleAndCrop);
    monVideoWidget->setAspectRatio(Phonon::VideoWidget::AspectRatioWidget);
    monVideoWidget->installEventFilter(this);

    /**
      * On connecte les signaux aux slots pour les boutons PLAY, PAUSE et STOP ainsi que pour le défilement du temps
    **/
    connect(ui->btnPlay, SIGNAL(clicked()), this, SLOT(playVideo()));

    connect(ui->btnPause, SIGNAL(clicked()), this, SLOT(pauseVideo()));

    connect(ui->btnStop, SIGNAL(clicked()), this, SLOT(stopVideo()));

    // on relie le media au LCD (temps)
    connect(mediaObjet, SIGNAL(tick(qint64)), this, SLOT(changerTemps()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
  * changerTemps()
  * Cette fonction permet de changer le temps du LCD Number.
  * On récupère le temps total et le temps restant avant la fin de la video.
  * Grace a ca, on peut calculer le temps parcouru dans la video et l'afficher dans le LCD Number.
**/
void MainWindow::changerTemps()
{
    // Initialisation de la variable temps a 0
    qint64 temps = 0;
    // On récupère le temps parcouru dans le media en faisant la différance entre le temps total et le temps restant
    temps = mediaObjet->totalTime() - mediaObjet->remainingTime();

    // on recupere le temps
    QTime monTemps(0, (temps / 60000) % 60, (temps / 1000) % 60);

    // on rentre le temps dans le lcd number
    ui->lcdNumber->display(monTemps.toString("mm:ss"));
}

/**
  * playVideo()
  * Permet de lancer le mediaObject.
**/
void MainWindow::playVideo()
{
    mediaObjet->play();
}

/**
  * pauseVideo()
  * Met en pause le mediaObject.
**/
void MainWindow::pauseVideo()
{
    mediaObjet->pause();
}

/**
  * stopVideo()
  * Stop le mediaObject (affichage noir + retour au début du media)
**/
void MainWindow::stopVideo()
{
    mediaObjet->stop();
}
