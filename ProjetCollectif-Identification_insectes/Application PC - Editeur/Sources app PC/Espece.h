#ifndef ESPECE_H
#define ESPECE_H

#include "ListeMedia.h"
#include <QString>

class Reponse;

/**
 *  \class Espece
 *  \file Espece.h
 *  \brief classe gerant une espece avec sa description et la liste de ses illustrations
 */
class Espece {

    private:
        int id;
        QString type;
        QString nom;
        QString regimeAlimentaire;
        QString information;

        Reponse * myReponse;
        ListeMedia * listeMedia;

    public:
        /**
         * \fn Espece(int identifiant)
         * \brief constructeur
         * \param int idenfifiant : l'identifiant unique de l'espece à instancier
         */
        Espece(int identifiant);

        /**
         *  \fn int getIdentifiant()
         *  \brief retourne l'identifiant de l'espece
         *  \return int
         */
        int getIdentifiant() { return id; }

        /**
         *  \fn QString getNom()
         *  \brief retourne le nom de l'espece
         *  \return QString
         */
        QString getNom()    {return nom;}

        /**
         *  \fn void setNom(QString o)
         *  \brief change le nom de l'espece
         *  \param QString o : le nouveau nom pour l'espece
         */
        void setNom(QString o)  {nom = o;}

        /**
         *  \fn QString getType()
         *  \brief retourne le type de l'espece
         *  \return QString
         */
        QString getType() { return type; }

        void setReponse(Reponse * pere)    {   myReponse = pere;    }

        /**
         *  \fn QString getRegimeAlimentaire()
         *  \brief retourne le regime alimentaire de l'espece
         *  \return QString
         */
        QString getRegimeAlimentaire() {    return regimeAlimentaire; }

        /**
         *  \fn QString getInformation()
         *  \brief retourne les informations sur l'espece
         *  \return QString
         */
        QString getInformation() { return information; }

        /**
         *  \fn void setType(QString unType);
         *  \brief change le type de l'espece
         *  \param QString unType : le nouveau type
         */
        void setType(QString unType) { type = unType; }

        /**
         *  \fn void setRegimeAlimentaire(QString unRegime);
         *  \brief change le regime alimentaire de l'espece
         *  \param QString unRegime : le nouveau regime alimentaire
         */
        void setRegimeAlimentaire(QString unRegime);

        /**
         *  \fn void setInformation(QString uneInformation);
         *  \brief change les informations sur l'espece
         *  \param QString uneInformation : les nouvelles informations
         */
        void setInformation(QString uneInformation) { information = uneInformation; }

        /**
         *  \fn void ajouterMedia(Media * med);
         *  \brief ajoute un media pour illustrer l'espece
         *  \param Media * med : le nouveau media
         */
        void ajouterMedia(Media * med);

        /**
         *  \fn void supprimerMedia(Media * med)
         *  \brief supprime le media de la liste des illustrations
         *  \param Media * med : le media a supprimer
         */
        void supprimerMedia(Media * med);

        /**
         *  \fn ListeMedia * getListeMedia()
         *  \brief retourne la liste des medias de l'espece
         *  \return ListeMedia *
         */
        ListeMedia * getListeMedia()    {return listeMedia;}
};

#endif // ESPECE_H
