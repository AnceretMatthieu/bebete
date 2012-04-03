#ifndef Espece_h
#define Espece_h
#include <QString>

class Reponse;

class Espece {

 public:
    Espece(int identifiant);
    int getIdentifiant();
    int getType();
    QString getRegimeAlimentaire();
    QString getInformation();
    void setType(int type);
    void setRegimeAlimentaire(char * ra);
    void setInformation(char * inf);

 private:
    int id;
    int Type;
    QString regimeAlimentaire;
    QString Information;
    Reponse * myReponse;
};

#endif // Espece_h
