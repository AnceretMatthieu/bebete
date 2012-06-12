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

#include "CategorieBDD.h"
#include "Reponse.h"
#include "ListeMedia.h"
#include "Espece.h"
#include "ListeReponse.h"
#include "Media.h"

#include "aboutwindow.h"
#include "modifquestionwindow.h"
#include "audioplayer.h"
#include "videoplayer.h"
#include "modifreponsewindow.h"
#include "textewindow.h"
#include "newresultatwindow.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        /**
         * \fn void closeEvent(QCloseEvent *event)
         * \brief Permet d'intercepter l'évènement de fermeture de l'application pour s'assurer que l'utilisateur ne la ferme pas pas erreur
         * \param *event : l'évènement de fermeture
         */
        void closeEvent(QCloseEvent *event);

    private:
        Ui::MainWindow *ui;

        QStandardItemModel * model_tvQuestion; /*!< Le modèle de données du TreeView des questions */
        QStandardItemModel * model_tvReponse; /*!< Le modèle de données du TreeView des réponses */
        QStandardItemModel * model_tvMediaQuestion; /*!< Le modèle de données du TreeView des médias des questions */

        QIcon greenIcon; /*!< Icone vert spécifiant la "qualité" d'une question */
        QIcon yellowIcon; /*!< Icone jaune spécifiant la "qualité" d'une question */
        QIcon redIcon; /*!< Icone rouge spécifiant la "qualité" d'une question */

        ListeQuestion * maListeQuestions; /*!< Liste des questions couramment en mémoire */

        QMap<QString, Question *> mapTreeQuestions; /*!< QMap contenant l'association entre l'item du TreeView des questions (ses coordonnées) et le pointeur vers la question en mémoire */
        QMap<QString, Reponse *> mapTreeReponses; /*!< QMap contenant l'association entre l'item du TreeView des réponses (ses coordonnées) et le pointeur vers la question en réponse */

        ModifQuestionWindow * myWindowQues; /*!< Représente la fenêtre de création/modification d'une question */
        ModifReponseWindow * myWindowRep; /*!< Représente la fenêtre de création/modification d'une réponse */
        TexteWindow * myWindowTxt; /*!< Représente la fenêtre de création/modification d'une question */
        NewResultatWindow * myWindowResult; /*!< Représente la fenêtre de création/modification d'un résultat */
        AudioPlayer * myAudioPlayer; /*!< Représente la fenêtre du lecteur audio */
        VideoPlayer * myVideoPlayer; /*!< Représente la fenêtre du lecteur vidéo */

        // Format de fichier reconnu par l'application
        QList<QString> formatImage; /*!< Liste des formats de fichier image reconnus par l'application */
        QList<QString> formatAudio; /*!< Liste des formats de fichier audio reconnus par l'application */
        QList<QString> formatVideo; /*!< Liste des formats de fichier vidéo reconnus par l'application */

        QString returnText; /*!< Variable contenant le texte retourné par la fenêtre de saisie de texte (TexteWindow) */

        /**
         * \fn void peuplerListeQuestionsXML(ListeQuestion * uneListeQuestions, QStandardItem * pere, int nbPere, QString coordPere)
         * \brief Permet de remplir le TreeView des questions à partir des données en mémoire (obtenues via un fichier XML)
         * \param uneListeQuestions : la liste des questions racines de l'arbre ; pere : l'élément racine du treeview ; nbPere : le nombre de père de l'élément courant ; coordPere : les coordonées du père de l'élément courant
         */
        void peuplerListeQuestionsXML(ListeQuestion * uneListeQuestions, QStandardItem * pere, int nbPere, QString coordPere);

        /**
          * \fn void createAction()
          * \brief Permet de créer manuellement tous les mécanismes de signaux/slots
          */
        void createAction();

        /**
          * \fn QString calculerCoordonnees(QModelIndex index)
          * \brief Permet de retourner les coordonnées d'un noeud du TreeView
          * \param index : l'index du noeud dont on veut calculer les coordonnées
          */
        QString calculerCoordonnees(QModelIndex index);

    private slots:
        /**
          * \fn void actionQuitter_triggered()
          * \brief Permet de gérer l'action du bouton "Quitter" du menu
          */
        void actionQuitter_triggered();

        /**
          * \fn void actionExporter_XML_triggered()
          * \brief Permet de gérer l'action du bouton "Exporter XML" du menu
          */
        void actionExporter_XML_triggered();

        /**
          * \fn void actionImporter_XML_triggered()
          * \brief Permet de gérer l'action du bouton "Importer XML" du menu
          */
        void actionImporter_XML_triggered();

        /**
          * \fn void actionApropos()
          * \brief Permet de gérer l'action du bouton "A propos de" du menu
          */
        void actionApropos();

        /**
          * \fn void clickTreeViewQuestions(const QModelIndex &index)
          * \brief Permet de gérer le clic sur le TreeView des questions
          * \param index : l'index de l'élément qui a été cliqué
          */
        void clickTreeViewQuestions(const QModelIndex &index);

        /**
          * \fn void clickTreeViewMediasQuestions(const QModelIndex &index)
          * \brief Permet gérer le clic sur le TreeView des médias des questions
          * \param index : l'index de l'élément qui a été cliqué
          */
        void clickTreeViewMediasQuestions(const QModelIndex &index);

        /**
          * \fn void clickTreeViewReponse(const QModelIndex &index)
          * \brief Permet de gérer le clic sur le TreeView des réponses
          * \param index : l'index de l'élément qui a été cliqué
          */
        void clickTreeViewReponse(const QModelIndex &index);

        /**
          * \fn void playAudio(QString fileName)
          * \brief Ouvre le lecteur audio avec le fichier de musique spécifié en paramètre
          * \param fileName : le chemin du fichier de musique
          */
        void playAudio(QString fileName);

        /**
          * \fn void playVideo(QString fileName)
          * \brief Ouvre le lecteur vidéo avec le fichier vidéo spécifié en paramètre
          * \param fileName : le chemin du fichier vidéo
          */
        void playVideo(QString fileName);

        /**
          * \fn void openMedia(QString fileName, int typeMedia)
          * \brief Permet d'afficher correctement le média passé en paramètre
          * \param fileName : le chemin du média ; typeMedia : le type du média (audio, video, musique, image) DEPRECIATED
          */
        void openMedia(QString fileName, int typeMedia);

        /**
          * \fn void receiveContents(QString str)
          * \brief Permet de récupérer le texte de la fenêtre TexteWindow
          * \param str : la chaine de caractère retournée par le fenêtre
          */
        void receiveContents(QString str);

        /* Permet de gérer les questions */
        void newQuestion();
        void modifierQuestion();
        void supprimerQuestion();

        /* Permet de gérer les médias d'une question */
        void newCommentaire();
        void newMedia();
        void modifierMedia();
        void supprimerMedia();

        /* Permet de gérer les réponses */
        void newReponse();
        void modifierReponse();
        void supprimerReponse();

        /* Permet de gérer les médias d'une réponse */
        void newComMediaReponse();
        void newMediaReponse();
        void modifierMediaReponse();
        void supprimerMediaReponse();

        /* Permet de gérer les résultats */
        void newResultat();
        void modifierResultat();
        void supprimerResultat();
};

#endif // MAINWINDOW_H
