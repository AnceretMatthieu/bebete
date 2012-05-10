#ifndef ReponseBDD_h
#define ReponseBDD_h

#include "BDD.h"
#include "Reponse.h"
#include "ListeReponse.h"
#include "Question.h"


class Reponse;
class ListeReponse;
class Question;

class ReponseBDD : public BDD {

    public:
        ReponseBDD();
        void listeReponseFromQuestion(Question * quest, bool recursif);
};

#endif // ReponseBDD_h
