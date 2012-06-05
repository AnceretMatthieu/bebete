#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDrag>
#include <QDropEvent>
#include <QFileSystemModel>
#include <QStandardItemModel>
#include <phonon/phonon>
#include <QFormLayout>
#include <QSound>
#include <QIcon>

#include <iostream>

#include "aboutwindow.h"
#include "modifquestionwindow.h"
#include "CategorieBDD.h"
#include "Reponse.h"
#include "ListeMedia.h"
#include "audioplayer.h"
#include "videoplayer.h"
#include "newreponsewindow.h"
#include "modifreponsewindow.h"
#include "Espece.h"
#include "ListeReponse.h"
#include "Media.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        void closeEvent(QCloseEvent *event);

    private:
        Ui::MainWindow *ui;

        QStandardItemModel * model_tvQuestion;
        QStandardItemModel * model_tvReponse;
        QStandardItemModel * model_tvMediaQuestion;

        QIcon greenIcon;
        QIcon yellowIcon;
        QIcon redIcon;

        ListeQuestion * maListeQuestions;

        QMap<QString, Question *> mapTreeQuestions;
        QMap<QString, Reponse *> mapTreeReponses;

        ModifQuestionWindow * myWindowQues;
        ModifReponseWindow * myWindowRep;
        NewReponseWindow * myWindowText;
        AudioPlayer * myAudioPlayer;
        VideoPlayer * myVideoPlayer;

        void peuplerListeQuestionsXML(ListeQuestion * uneListeQuestions, QStandardItem * pere, int nbPere, QString coordPere);
        void createAction();

        QString calculerCoordonnees(QModelIndex index);

    private slots:
        void actionQuitter_triggered();
        void actionExporter_XML_triggered();
        void actionImporter_XML_triggered();
        void actionApropos();
        void clickTreeViewQuestions(const QModelIndex &index);
        void clickTreeViewMediasQuestions(const QModelIndex &index);
        void clickTreeViewReponse(const QModelIndex &index);

        void playAudio(QString fileName);
        void playVideo(QString fileName);
        void openMedia(QString fileName, int typeMedia);

        void newQuestionFils();
        void newQuestionFrere();
        void modifierQuestion();
        void supprimerQuestion();

        void newCommentaire();
        void newMedia();
        void modifierMedia();
        void supprimerMedia();

        void newReponse();
        void modifierReponse();
        void supprimerReponse();

        void newComMediaReponse();
        void newMediaReponse();
        void modifierMediaReponse();
        void supprimerMediaReponse();
};

#endif // MAINWINDOW_H
