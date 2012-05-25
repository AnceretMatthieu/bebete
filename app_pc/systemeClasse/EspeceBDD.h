#ifndef EspeceBDD_h
#define EspeceBDD_h

#include "Espece.h"
#include "BDD.h"

class EspeceBDD : public BDD {

public:
    static void enregistrerEspece(Espece * esp);
};

#endif // EspeceBDD_h
