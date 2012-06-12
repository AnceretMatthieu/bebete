#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

/**
  * \file videoplayer.h
  * \brief Fichier de déclaration du lecteur vidéo.
 */
#include <QDialog>
#include <phonon>
#include <QTime>

namespace Ui {
    class VideoPlayer;
}

class VideoPlayer : public QDialog
{
    Q_OBJECT
    
    public:
        explicit VideoPlayer(QString filepath, QWidget *parent = 0);
        ~VideoPlayer();

        void closeEvent(QCloseEvent *event);

    private:
        Ui::VideoPlayer *ui;

        Phonon::VideoWidget *monVideoWidget; /**< Widget contenant les parametres video */

        Phonon::SeekSlider * barreAvancement; /**< Slider d'avancement */
        Phonon::VolumeSlider *barreVolume; /**< Slider de volume */

        Phonon::MediaObject *mediaObjet; /**< Objet contenant le média */

        Phonon::AudioOutput *sortie; /**< Sortie audio du média vidéo */

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
          * \fn void playVideo()
          * \brief Lance la vidéo par l'action PLAY du mediaObject.
         */
        void playVideo();

        /**
          * \fn void pauseVideo()
          * \brief Met en pause le mediaObject grâce à l'action PAUSE de celui-ci.
          * Le média reste au temps ou il a été mit en pause.
         */
        void pauseVideo();

        /**
          * \fn void stopVideo()
          * \brief Stop le media object grâce à son action STOP.
          * Le média est alors réinitialisé au début (affichage noir à l'écran dans le cadre vidéo).
         */
        void stopVideo();
};

#endif // VIDEOPLAYER_H
