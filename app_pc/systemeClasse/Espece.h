#ifndef Espece_h
#define Espece_h

#include <QString>

class Reponse;

class Espece {

    private:
        int id;
        int type;
        QString regimeAlimentaire;
        QString information;

        Reponse * myReponse;

    public:
        Espece(int identifiant);

        int getIdentifiant() {
            return id;
        }

        int getType() {
            return type;
        }

        QString getRegimeAlimentaire() {
            return regimeAlimentaire;
        }

        QString getInformation() {
            return information;
        }

        void setType(int unType) {
            type = unType;
        }

        void setRegimeAlimentaire(QString unRegime) {
            regimeAlimentaire = unRegime;
        }

        void setInformation(QString uneInformation) {
            information = uneInformation;
        }
};

#endif // Espece_h
