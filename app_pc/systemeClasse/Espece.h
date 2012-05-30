#ifndef Espece_h
#define Espece_h

#include "ListeMedia.h"
#include <QString>

class Reponse;

/**
 *  \class Espece
 *  \file Espece.h
 *  \brief classe gérant une espèce avec ça description et la liste de ces illustrations
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
         * \param int idenfifiant : l'identifiant unique de l'espèce à instancier
         */
        Espece(int identifiant);

        /**
         *  \fn int getIdentifiant()
         *  \brief retourne l'identifiant de l'espèce
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
         *  \brief change le nom de l'espèce
         *  \param QString o : le nouveau nom pour l'espèce
         */
        void setNom(QString o)  {nom = o;}

        /**
         *  \fn QString getType()
         *  \brief retourne le type de l'espèce
         *  \return QString
         */
        QString getType() { return type; }

        /**
         *  \fn QString getRegimeAlimentaire()
         *  \brief retourne le régime alimentaire de l'espèce
         *  \return QString
         */
        QString getRegimeAlimentaire() {    return regimeAlimentaire; }

        /**
         *  \fn QString getInformation()
         *  \brief retourne les informations sur l'espèce
         *  \return QString
         */
        QString getInformation() { return information; }

        /**
         *  \fn void setType(QString unType);
         *  \brief change le type de l'espèce
         *  \param QString unType : le nouveau type
         */
        void setType(QString unType) { type = unType; }

        /**
         *  \fn void setRegimeAlimentaire(QString unRegime);
         *  \brief change le regime alimentaire de l'espèce
         *  \param QString unRegime : le nouveau regime alimentaire
         */
        void setRegimeAlimentaire(QString unRegime) { regimeAlimentaire = unRegime; }

        /**
         *  \fn void setInformation(QString uneInformation);
         *  \brief change les informations sur l'espèce
         *  \param QString uneInformation : les nouvelles informations
         */
        void setInformation(QString uneInformation) { information = uneInformation; }

        /**
         *  \fn void ajouterMedia(Media * med);
         *  \brief ajoute un média pour illustrer l'espèce
         *  \param Media * med : le nouveau média
         */
        void ajouterMedia(Media * med);

        /**
         *  \fn void supprimerMedia(Media * med)
         *  \brief supprime le média de la liste des illustrations
         *  \param Media * med : le média a supprimé
         */
        void supprimerMedia(Media * med);

        /**
         *  \fn ListeMedia * getListeMedia()
         *  \brief retourne la liste des médias de l'espèce
         *  \return ListeMedia *
         */
        ListeMedia * getListeMedia()    {return listeMedia;}
};

#endif // Espece_h
