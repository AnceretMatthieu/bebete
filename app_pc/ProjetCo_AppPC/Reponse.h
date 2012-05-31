#ifndef Reponse_h
#define Reponse_h

#include <QVector>
#include <QString>

#include "Categorie.h"

#define MEDIA_NOT_IN_LIST_EXCEPTION 404
#define TYPE_ESPECE 0
#define TYPE_CATEGORIE 1

class Media;
class Question;
class Espece;
class ListeMedia;

/**
 *  \class Reponse
 *  \file Reponse.h
 *  \brief classe gÃ©rant une réponse avec sa description
 */
class Reponse {

    private:
        int id;
        int idleft;
        int idright;
        QString texte;

        void * pere;
        void * fils;
        int typePere;
        int typeFils;

        ListeMedia * illustrationMedia;

    public:

        /**
         * \fn Reponse(int id)
         * \brief constructeur
         * \param int id : l'identifiant unique de la réponse à instancier
         */
        Reponse(int id);

        /**
         *  \fn int getIdentifiant()
         *  \brief retourne l'identifiant de la réponse
         *  \return int id
         */
        int getIdentifiant() {  return id; }

        /**
         *  \fn int getReponse()
         *  \brief retourne le texte de la réponse
         *  \return QString texte
         */
        QString getReponse() {  return texte;   }


        void setSuiv(void * suiv);
        void * getSuiv();
        void setPrec(void * prec);
        void * getPrec();

        void setTypeSuiv(int type);
        int getTypeSuiv()   {return typeFils;}

        void setTypePrec(int type);
        int getTypePrec()   {return typePere;}

        void setIdLeft(int id)  {idleft = id;}
        void setIdRight(int id)  {idright = id;}
        int getIdLeft()  {return idleft;}
        int getIdRight()  {return idright;}

        /**
         *  \fn void setReponse(QString rep)
         *  \brief change le nom de la réponse
         *  \param QString rep : le nouveau nom de la réponse
         *  \return void
         */
        void setReponse(QString rep) {
            texte = rep;
        }

        /**
         *  \fn ListeMedia * getListeIllustration()
         *  \brief retourne la liste des illustrations du résultat
         *  \return ListeMedia *
         */
        ListeMedia * getListeIllustration() {return illustrationMedia;}

        /**
         *  \fn void ajouterMedia(Media * med);
         *  \brief ajoute un mÃ©dia pour illustrer le résultat
         *  \param Media * med : le nouveau mÃ©dia
         */
        void ajouterMedia(Media * med);

        /**
         *  \fn void supprimerMedia(Media * med)
         *  \brief supprime le mÃ©dia des résultats
         *  \param Media * med : le mÃ©dia a supprimÃ©
         */
        void supprimerMedia(Media * med);

        /**
         *  \fn void supprimerMedia(int id)
         *  \brief supprime le mÃ©dia des résultats en fonction de son id
         *  \param int id : l'identifiant du mÃ©dia a supprimÃ©
         */
        void supprimerMedia(int id);
};

#endif // Reponse_h
