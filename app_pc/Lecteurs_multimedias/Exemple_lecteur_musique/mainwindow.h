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

public slots:
    void changerTemps();
    void changerSourceVolume();
    void changerSourceAvancement();

private:
    Ui::MainWindow *ui;

    // Les 2 slider (avancement et volume)
    Phonon::SeekSlider * barreAvancement;
    Phonon::VolumeSlider *barreVolume;

    Phonon::MediaObject *mediaObjet;

    // Sortie audio des "musiques"
    Phonon::AudioOutput *sortie;
};

#endif // MAINWINDOW_H
