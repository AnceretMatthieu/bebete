#ifndef Espece_h
#define Espece_h

#include "ListeMedia.h"
#include <QString>

class Reponse;

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
        Espece(int identifiant);

        int getIdentifiant() {
            return id;
        }

        QString getNom()    {return nom;}
        void setNom(QString o)  {nom = o;}

        QString getType() {
            return type;
        }

        QString getRegimeAlimentaire() {
            return regimeAlimentaire;
        }

        QString getInformation() {
            return information;
        }

        void setType(QString unType) {
            type = unType;
        }

        void setRegimeAlimentaire(QString unRegime) {
            regimeAlimentaire = unRegime;
        }

        void setInformation(QString uneInformation) {
            information = uneInformation;
        }

        void ajouterMedia(Media * med);
        void supprimerMedia(Media * med);
        ListeMedia * getListeMedia()    {return listeMedia;}
};

#endif // Espece_h
