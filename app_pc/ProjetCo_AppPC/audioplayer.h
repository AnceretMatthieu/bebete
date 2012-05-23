#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QDialog>
#include <phonon>
#include <QTime>

namespace Ui {
    class AudioPlayer;
}

class AudioPlayer : public QDialog
{
    Q_OBJECT
    
    public:
        explicit AudioPlayer(QString filePath, QWidget *parent = 0);
        ~AudioPlayer();

    public slots:
        void changerTemps();
        void changerSourceVolume();
        void changerSourceAvancement();

    private slots:
        void on_AudioPlayer_destroyed();

    private:
        Ui::AudioPlayer *ui;

        Phonon::SeekSlider * barreAvancement;
        Phonon::VolumeSlider *barreVolume;

        Phonon::MediaObject *mediaObjet;
        Phonon::AudioOutput *sortie;
};

#endif // AUDIOPLAYER_H
