#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

/**
  * \file audioplayer.h
  * \brief Fichier de déclaration du lecteur audio
 */
#include <QDialog>
#include <phonon>
#include <QTime>

namespace Ui {
    class AudioPlayer;
}

/**
  * \class AudioPlayer
  * \brief Classe qui gère le lecteur audio.
 */
class AudioPlayer : public QDialog
{
    Q_OBJECT
    
    public:
        explicit AudioPlayer(QString filePath, QWidget *parent = 0);
        ~AudioPlayer();

        void closeEvent(QCloseEvent *event);

    public slots:
        /**
          * \fn void changerTemps()
          * \brief Fonction qui permet d'afficher le temps passe sur le media courant.
          * Cette fonction permet de changer le temps du LCD Number.
          * On récupère le temps total et le temps restant avant la fin de la video.
          * Grace a ca, on peut calculer le temps parcouru dans la video et l'afficher dans le LCD Number.
        */
        void changerTemps();

        /**
          * \fn void changerSourceVolume()
          * \brief Fonction qui modifie la source pour la VolumeSlider
         */
        void changerSourceVolume();

        /**
          * \fn void changerSourceAvancement()
          * \brief Fonction qui modifie la source de la SeekSlider
         */
        void changerSourceAvancement();

    private:
        Ui::AudioPlayer *ui;

        Phonon::SeekSlider * barreAvancement; /**< Pointeur sur l'objet de la barre d'avancement */
        Phonon::VolumeSlider *barreVolume; /**< Pointeur sur l'objet de la barre de volume */

        Phonon::MediaObject *mediaObjet; /**< Pointeur sur l'objet MediaObject contenant toutes les informations du média en paramètre */
        Phonon::AudioOutput *sortie; /**< Pointeur sur la sortie audio du lecteur */
};

#endif // AUDIOPLAYER_H
