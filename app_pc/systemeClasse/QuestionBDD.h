#ifndef QuestionBDD_h
#define QuestionBDD_h

#include "BDD.h"

class Question;
class ListeQuestion;
class ReponseBDD;
class Categorie;

class QuestionBDD : public BDD {

    public:
        QuestionBDD();

        ListeQuestion * CreerArbre();
        ListeQuestion * parseXML();
        void listeQuestionWithCategorie(Categorie * cat, bool recursif);
};

#endif // QuestionBDD_h
