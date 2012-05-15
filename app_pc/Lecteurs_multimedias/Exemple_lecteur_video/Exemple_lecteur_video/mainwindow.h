#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <phonon>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

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

#endif // MAINWINDOW_H
