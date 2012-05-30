/**
  * \file audioplayer.cpp
  * \brief Corps des méthodes du lecteur audio
 */
#include "audioplayer.h"
#include "ui_audioplayer.h"

AudioPlayer::AudioPlayer(QString filePath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AudioPlayer)
{    
    ui->setupUi(this);

    //On initialise les attributs utilises par la classe
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

    // Connexion des signaux des boutons PLAY, PAUSE et STOP avec leurs actions sur le MediaObject
    connect(ui->btnPlay, SIGNAL(clicked()), mediaObjet, SLOT(play()));
    connect(ui->btnPause, SIGNAL(clicked()), mediaObjet, SLOT(pause()));
    connect(ui->btnStop, SIGNAL(clicked()), mediaObjet, SLOT(stop()));

    // on relie le media au LCD (temps)
    connect(mediaObjet, SIGNAL(tick(qint64)), this, SLOT(changerTemps()));

    // Modification de la source pour la VolumeSlider et la SeekSlider dès qu'elle est modifée dans l'objet
    // de type MediaSource (dans MediaObject)
    connect(mediaObjet,SIGNAL(currentSourceChanged(Phonon::MediaSource)), this, SLOT(changerSourceVolume()));
    connect(mediaObjet,SIGNAL(currentSourceChanged(Phonon::MediaSource)), this, SLOT(changerSourceAvancement()));
}

AudioPlayer::~AudioPlayer()
{
    delete ui;
}

//void AudioPlayer::changerTemps()
void AudioPlayer::changerTemps()
{
    qint64 temps = 0;

    temps = mediaObjet->totalTime() - mediaObjet->remainingTime();

    // on recupere le temps
    QTime monTemps(0, (temps / 60000) % 60, (temps / 1000) % 60);

    // on rentre le temps dans le lcd number
    ui->lcdNumber->display(monTemps.toString("mm:ss"));
}

//changerSourceVolume()
void AudioPlayer::changerSourceVolume()
{
    barreVolume->setAudioOutput(sortie);
}

//changerSourceAvancement()
void AudioPlayer::changerSourceAvancement()
{
    barreAvancement->setMediaObject(mediaObjet);
}

void AudioPlayer::closeEvent(QCloseEvent *event)
{
    ui->btnStop->click(); // permet d'arrêter le son lorsque l'on ferme la fenêtre
    close();
}
