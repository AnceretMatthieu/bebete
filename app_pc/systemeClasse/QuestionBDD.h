#ifndef QuestionBDD_h
#define QuestionBDD_h

#include "BDD.h"
#include "ListeQuestion.h"
#include "ListeReponse.h"
#include "Question.h"
#include "ReponseBDD.h"
#include "MediaBDD.h"
#include "Categorie.h"


class Question;
class ListeQuestion;
class ReponseBDD;
class Categorie;

class QuestionBDD : public BDD {

    public:
        QuestionBDD();

        static ListeQuestion * CreerArbre();
        static ListeQuestion * parseXML();
        static void listeQuestionWithCategorie(Categorie * cat, bool recursif);
};

#endif // QuestionBDD_h
