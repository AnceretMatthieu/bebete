#ifndef Espece_h
#define Espece_h

#include "Reponse.h"

class Espece {

 public:

    Espece(int identifiant);

    ~Espece();

    int getIdentifiant();

    int getType();

    char * getRegimeAlimentaire();

    char * getInformation();

    void setType(int type);

    void setRegimeAlimentaire(char * ra);

    void setInformation(char * inf);

 private:
    int id;
    int Type;
    char * regimeAlimentaire;
    char * Information;

    /**
     * @element-type Reponse
     */
    Reponse *myReponse;
};

#endif // Espece_h
