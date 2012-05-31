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
 *  \brief classe gérant une r�ponse avec sa description
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
         * \param int id : l'identifiant unique de la r�ponse � instancier
         */
        Reponse(int id);

        /**
         *  \fn int getIdentifiant()
         *  \brief retourne l'identifiant de la r�ponse
         *  \return int id
         */
        int getIdentifiant() {  return id; }

        /**
         *  \fn int getReponse()
         *  \brief retourne le texte de la r�ponse
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
         *  \brief change le nom de la r�ponse
         *  \param QString rep : le nouveau nom de la r�ponse
         *  \return void
         */
        void setReponse(QString rep) {
            texte = rep;
        }

        /**
         *  \fn ListeMedia * getListeIllustration()
         *  \brief retourne la liste des illustrations du r�sultat
         *  \return ListeMedia *
         */
        ListeMedia * getListeIllustration() {return illustrationMedia;}

        /**
         *  \fn void ajouterMedia(Media * med);
         *  \brief ajoute un média pour illustrer le r�sultat
         *  \param Media * med : le nouveau média
         */
        void ajouterMedia(Media * med);

        /**
         *  \fn void supprimerMedia(Media * med)
         *  \brief supprime le média des r�sultats
         *  \param Media * med : le média a supprimé
         */
        void supprimerMedia(Media * med);

        /**
         *  \fn void supprimerMedia(int id)
         *  \brief supprime le média des r�sultats en fonction de son id
         *  \param int id : l'identifiant du média a supprimé
         */
        void supprimerMedia(int id);
};

#endif // Reponse_h
