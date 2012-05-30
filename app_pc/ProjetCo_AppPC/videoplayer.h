#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

/**
  * \file videoplayer.h
  * \brief Fichier de d�claration du lecteur vid�o.
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

        Phonon::MediaObject *mediaObjet; /**< Objet contenant le m�dia */

        Phonon::AudioOutput *sortie; /**< Sortie audio du m�dia vid�o */

    public slots:
        /**
          * \fn void changerTemps()
          * \brief Fonction qui permet d'afficher le temps passe sur le media courant.
          * Cette fonction permet de changer le temps du LCD Number.
          * On r�cup�re le temps total et le temps restant avant la fin de la video.
          * Grace a ca, on peut calculer le temps parcouru dans la video et l'afficher dans le LCD Number.
        */
        void changerTemps();

        /**
          * \fn void playVideo()
          * \brief Lance la vid�o par l'action PLAY du mediaObject.
         */
        void playVideo();

        /**
          * \fn void pauseVideo()
          * \brief Met en pause le mediaObject gr�ce � l'action PAUSE de celui-ci.
          * Le m�dia reste au temps ou il a �t� mit en pause.
         */
        void pauseVideo();

        /**
          * \fn void stopVideo()
          * \brief Stop le media object gr�ce � son action STOP.
          * Le m�dia est alors r�initialis� au d�but (affichage noir � l'�cran dans le cadre vid�o).
         */
        void stopVideo();
};

#endif // VIDEOPLAYER_H
