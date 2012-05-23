#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

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

    private:
        Ui::VideoPlayer *ui;

        // Widget contenant les parametres video
        Phonon::VideoWidget *monVideoWidget;

        // Les 2 slider (avancement et volume)
        Phonon::SeekSlider * barreAvancement;
        Phonon::VolumeSlider *barreVolume;

        // Objet contenant le media
        Phonon::MediaObject *mediaObjet;

        // Sortie audio
        Phonon::AudioOutput *sortie;

    public slots:
        void changerTemps();
        void playVideo();
        void pauseVideo();
        void stopVideo();
};

#endif // VIDEOPLAYER_H
