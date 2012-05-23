#include "audioplayer.h"
#include "ui_audioplayer.h"

AudioPlayer::AudioPlayer(QString filePath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AudioPlayer)
{    
    ui->setupUi(this);

    // On initialise les attributs utilises par la classe
    sortie = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    mediaObjet = new Phonon::MediaObject(this);

    mediaObjet->setTickInterval(1000);

    // Création des barres d'avancement et de volume
    // on cree la seek slider
    barreAvancement = new Phonon::SeekSlider(this);
    barreAvancement->setMediaObject(mediaObjet);
    ui->vLayoutAvancement->addWidget(barreAvancement);

    // on cree la volume slider
    barreVolume = new Phonon::VolumeSlider(this);
    barreVolume->setAudioOutput(sortie);
    ui->hLayoutVolume->addWidget(barreVolume);

    // on connecte les fonctions aux signaux
    mediaObjet->setCurrentSource(Phonon::MediaSource(filePath));

    // on donne le chemin pour les médias
    Phonon::createPath(mediaObjet, sortie);

    connect(ui->btnPlay, SIGNAL(clicked()), mediaObjet, SLOT(play()));
    connect(ui->btnPause, SIGNAL(clicked()), mediaObjet, SLOT(pause()));
    connect(ui->btnStop, SIGNAL(clicked()), mediaObjet, SLOT(stop()));

    // on relie le media au LCD (temps)
    connect(mediaObjet, SIGNAL(tick(qint64)), this, SLOT(changerTemps()));

    connect(mediaObjet,SIGNAL(currentSourceChanged(Phonon::MediaSource)), this, SLOT(changerSourceVolume()));
    connect(mediaObjet,SIGNAL(currentSourceChanged(Phonon::MediaSource)), this, SLOT(changerSourceAvancement()));
}

AudioPlayer::~AudioPlayer()
{
    delete ui;
}

/**
  * changerTemps()
  * permet d'afficher le temps passe sur le media courant
**/
void AudioPlayer::changerTemps()
{
    qDebug() << "changerTemps()";
    qint64 temps = 0;

    temps = mediaObjet->totalTime() - mediaObjet->remainingTime();

    // on recupere le temps
    QTime monTemps(0, (temps / 60000) % 60, (temps / 1000) % 60);

    // on rentre le temps dans le lcd number
    ui->lcdNumber->display(monTemps.toString("mm:ss"));
}

/**
  * changerSourceVolume()
  * change la source de la volume Slider
**/
void AudioPlayer::changerSourceVolume()
{
    qDebug() << "changerSourceVolume()";
    barreVolume->setAudioOutput(sortie);
}

/**
  * changerSourceAvancement()
  * change la source de la seek slider
**/
void AudioPlayer::changerSourceAvancement()
{
    qDebug() << "changerSourceAvancement()";
    barreAvancement->setMediaObject(mediaObjet);
}

void AudioPlayer::on_AudioPlayer_destroyed()
{
    close();
}
