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
         * \brief Permet d'intercepter l'�v�nement de fermeture de l'application pour s'assurer que l'utilisateur ne la ferme pas pas erreur
         * \param *event : l'�v�nement de fermeture
         */
        void closeEvent(QCloseEvent *event);

    private:
        Ui::MainWindow *ui;

        QStandardItemModel * model_tvQuestion; /*!< Le mod�le de donn�es du TreeView des questions */
        QStandardItemModel * model_tvReponse; /*!< Le mod�le de donn�es du TreeView des r�ponses */
        QStandardItemModel * model_tvMediaQuestion; /*!< Le mod�le de donn�es du TreeView des m�dias des questions */

        QIcon greenIcon; /*!< Icone vert sp�cifiant la "qualit�" d'une question */
        QIcon yellowIcon; /*!< Icone jaune sp�cifiant la "qualit�" d'une question */
        QIcon redIcon; /*!< Icone rouge sp�cifiant la "qualit�" d'une question */

        ListeQuestion * maListeQuestions; /*!< Liste des questions couramment en m�moire */

        QMap<QString, Question *> mapTreeQuestions; /*!< QMap contenant l'association entre l'item du TreeView des questions (ses coordonn�es) et le pointeur vers la question en m�moire */
        QMap<QString, Reponse *> mapTreeReponses; /*!< QMap contenant l'association entre l'item du TreeView des r�ponses (ses coordonn�es) et le pointeur vers la question en r�ponse */

        ModifQuestionWindow * myWindowQues; /*!< Repr�sente la fen�tre de cr�ation/modification d'une question */
        ModifReponseWindow * myWindowRep; /*!< Repr�sente la fen�tre de cr�ation/modification d'une r�ponse */
        TexteWindow * myWindowTxt; /*!< Repr�sente la fen�tre de cr�ation/modification d'une question */
        NewResultatWindow * myWindowResult; /*!< Repr�sente la fen�tre de cr�ation/modification d'un r�sultat */
        AudioPlayer * myAudioPlayer; /*!< Repr�sente la fen�tre du lecteur audio */
        VideoPlayer * myVideoPlayer; /*!< Repr�sente la fen�tre du lecteur vid�o */

        // Format de fichier reconnu par l'application
        QList<QString> formatImage; /*!< Liste des formats de fichier image reconnus par l'application */
        QList<QString> formatAudio; /*!< Liste des formats de fichier audio reconnus par l'application */
        QList<QString> formatVideo; /*!< Liste des formats de fichier vid�o reconnus par l'application */

        QString returnText; /*!< Variable contenant le texte retourn� par la fen�tre de saisie de texte (TexteWindow) */

        /**
         * \fn void peuplerListeQuestionsXML(ListeQuestion * uneListeQuestions, QStandardItem * pere, int nbPere, QString coordPere)
         * \brief Permet de remplir le TreeView des questions � partir des donn�es en m�moire (obtenues via un fichier XML)
         * \param uneListeQuestions : la liste des questions racines de l'arbre ; pere : l'�l�ment racine du treeview ; nbPere : le nombre de p�re de l'�l�ment courant ; coordPere : les coordon�es du p�re de l'�l�ment courant
         */
        void peuplerListeQuestionsXML(ListeQuestion * uneListeQuestions, QStandardItem * pere, int nbPere, QString coordPere);

        /**
          * \fn void createAction()
          * \brief Permet de cr�er manuellement tous les m�canismes de signaux/slots
          */
        void createAction();

        /**
          * \fn QString calculerCoordonnees(QModelIndex index)
          * \brief Permet de retourner les coordonn�es d'un noeud du TreeView
          * \param index : l'index du noeud dont on veut calculer les coordonn�es
          */
        QString calculerCoordonnees(QModelIndex index);

    private slots:
        /**
          * \fn void actionQuitter_triggered()
          * \brief Permet de g�rer l'action du bouton "Quitter" du menu
          */
        void actionQuitter_triggered();

        /**
          * \fn void actionExporter_XML_triggered()
          * \brief Permet de g�rer l'action du bouton "Exporter XML" du menu
          */
        void actionExporter_XML_triggered();

        /**
          * \fn void actionImporter_XML_triggered()
          * \brief Permet de g�rer l'action du bouton "Importer XML" du menu
          */
        void actionImporter_XML_triggered();

        /**
          * \fn void actionApropos()
          * \brief Permet de g�rer l'action du bouton "A propos de" du menu
          */
        void actionApropos();

        /**
          * \fn void clickTreeViewQuestions(const QModelIndex &index)
          * \brief Permet de g�rer le clic sur le TreeView des questions
          * \param index : l'index de l'�l�ment qui a �t� cliqu�
          */
        void clickTreeViewQuestions(const QModelIndex &index);

        /**
          * \fn void clickTreeViewMediasQuestions(const QModelIndex &index)
          * \brief Permet g�rer le clic sur le TreeView des m�dias des questions
          * \param index : l'index de l'�l�ment qui a �t� cliqu�
          */
        void clickTreeViewMediasQuestions(const QModelIndex &index);

        /**
          * \fn void clickTreeViewReponse(const QModelIndex &index)
          * \brief Permet de g�rer le clic sur le TreeView des r�ponses
          * \param index : l'index de l'�l�ment qui a �t� cliqu�
          */
        void clickTreeViewReponse(const QModelIndex &index);

        /**
          * \fn void playAudio(QString fileName)
          * \brief Ouvre le lecteur audio avec le fichier de musique sp�cifi� en param�tre
          * \param fileName : le chemin du fichier de musique
          */
        void playAudio(QString fileName);

        /**
          * \fn void playVideo(QString fileName)
          * \brief Ouvre le lecteur vid�o avec le fichier vid�o sp�cifi� en param�tre
          * \param fileName : le chemin du fichier vid�o
          */
        void playVideo(QString fileName);

        /**
          * \fn void openMedia(QString fileName, int typeMedia)
          * \brief Permet d'afficher correctement le m�dia pass� en param�tre
          * \param fileName : le chemin du m�dia ; typeMedia : le type du m�dia (audio, video, musique, image) DEPRECIATED
          */
        void openMedia(QString fileName, int typeMedia);

        /**
          * \fn void receiveContents(QString str)
          * \brief Permet de r�cup�rer le texte de la fen�tre TexteWindow
          * \param str : la chaine de caract�re retourn�e par le fen�tre
          */
        void receiveContents(QString str);

        /* Permet de g�rer les questions */
        void newQuestion();
        void modifierQuestion();
        void supprimerQuestion();

        /* Permet de g�rer les m�dias d'une question */
        void newCommentaire();
        void newMedia();
        void modifierMedia();
        void supprimerMedia();

        /* Permet de g�rer les r�ponses */
        void newReponse();
        void modifierReponse();
        void supprimerReponse();

        /* Permet de g�rer les m�dias d'une r�ponse */
        void newComMediaReponse();
        void newMediaReponse();
        void modifierMediaReponse();
        void supprimerMediaReponse();

        /* Permet de g�rer les r�sultats */
        void newResultat();
        void modifierResultat();
        void supprimerResultat();
};

#endif // MAINWINDOW_H
