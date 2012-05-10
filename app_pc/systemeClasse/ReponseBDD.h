#ifndef ReponseBDD_h
#define ReponseBDD_h

#include "BDD.h"

class Reponse;
class ListeReponse;
class Question;

class ReponseBDD : public BDD {

    public:
        ReponseBDD();
        void listeReponseFromQuestion(Question * quest, bool recursif);
};

#endif // ReponseBDD_h
