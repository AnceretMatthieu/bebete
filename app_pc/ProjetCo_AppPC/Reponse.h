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

        /**
         * \fn setSuiv(void* suiv)
         * \brief Permet de mettre le pointeur sur le suivant
         * \param void * suiv
         */
        void setSuiv(void * suiv);

        /**
         * \fn getSuiv()
         * \brief Permet de r�cuperer le pointeur sur le suivant
         * \return void *
         */
        void * getSuiv();

        /**
         * \fn setPrec(void* prec)
         * \brief Permet de mettre le pointeur sur le pr�c�dent
         * \param void * prec
         */
        void setPrec(void * prec);

        /**
         * \fn getPrec()
         * \brief Permet de r�cuperer le pointeur sur le pr�c�dent
         * \return void *
         */
        void * getPrec();

        /**
         * \fn setTypeSuiv(int type)
         * \brief Permet de changer le type du suivant
         * \param int type : on d�finit l'int du nouveau type
         */
        void setTypeSuiv(int type);

        /**
         * \fn getTypeSuiv()
         * \brief Permet de r�cup�rer le type du suivant
         * \return int typeFils : on r�cup�re le type du fils
         */
        int getTypeSuiv()   {return typeFils;}

        /**
         * \fn setTypePrec(int type)
         * \brief Permet de changer le type du pr�c�dent
         * \param int type : on d�finit l'int du nouveau type
         */
        void setTypePrec(int type);

        /**
         * \fn getTypePrec()
         * \brief Permet de r�cup�rer le type du pr�c�dent
         * \return int typeFils : on r�cup�re le type du p�re
         */
        int getTypePrec()   {return typePere;}

        /**
         *  \fn void setIdLeft(int id)
         *  \brief change l'Id de celui de gauche
         *  \param int id
         */
        void setIdLeft(int id)  {idleft = id;}

        /**
         *  \fn void setIdRight(int id)
         *  \brief change l'Id de celui de droite
         *  \param int id
         */
        void setIdRight(int id)  {idright = id;}

        /**
         *  \fn int getIdLeft()
         *  \brief r�cup�re l'Id de celui de gauche
         *  \return int idleft
         */
        int getIdLeft()  {return idleft;}

        /**
         *  \fn int getIdRight()
         *  \brief r�cup�re l'Id de celui de droite
         *  \return int idright
         */
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
