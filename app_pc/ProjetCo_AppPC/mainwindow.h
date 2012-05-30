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
#include "categoriebdd.h"
#include "Reponse.h"
#include "ListeMedia.h"
#include "audioplayer.h"
#include "videoplayer.h"
#include "ajoutertexte.h"
#include "modifreponsewindow.h"

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

        QAction * addQuestionFils;
        QAction * addQuestionFrere;
        QAction * modifQuestion;
        QAction * delQuestion;
        QAction * addReponse;
        QAction * modifReponse;
        QAction * delReponse;

        ListeQuestion * maListeQuestions;

        QMap<QString, Question *> mapTreeQuestions;
        QMap<QString, Reponse *> mapTreeReponses;

        ModifQuestionWindow * myWindowQues;
        ModifReponseWindow * myWindowRep;
        AudioPlayer * myAudioPlayer;
        VideoPlayer * myVideoPlayer;
        AjouterTexte * myTxtWindow;

        void peuplerListeQuestionsXML(ListeQuestion * uneListeQuestions, QStandardItem * pere, int nbPere);
        void createAction();

    private slots:
        void on_actionQuitter_triggered();
        void on_actionExporter_XML_triggered();
        void on_actionImporter_XML_triggered();
        void on_actionApropos();
        void on_clickTreeViewQuestions(const QModelIndex &index);
        void on_clickTreeViewMediasQuestions(const QModelIndex &index);
        void on_clickTreeViewReponse(const QModelIndex &index);

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
