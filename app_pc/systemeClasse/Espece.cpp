#include "Reponse.h"
#include "Espece.h"

int Espece::getIdentifiant()    {
    return id;
}

int Espece::getType()   {
    return Type;
}

QString Espece::getRegimeAlimentaire()   {
    return regimeAlimentaire;
}
QString Espece::getInformation() {
    return Information;
}

void Espece::setType(int type)  {
    Type = type;
}
void Espece::setRegimeAlimentaire(QString ra)    {
    regimeAlimentaire = ra;
}
void Espece::setInformation(QString inf) {
    Information = inf;
}
