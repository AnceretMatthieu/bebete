#ifndef ReponseBDD_h
#define ReponseBDD_h

#include "BDD.h"
#include "Reponse.h"
#include "ListeReponse.h"
#include "Question.h"
#include "Media.h"


class Reponse;
class ListeReponse;
class Question;

class ReponseBDD : public BDD {

    public:
        ReponseBDD();
        static void listeFromReponse(Reponse * rep, bool recursif);
};

#endif // ReponseBDD_h
