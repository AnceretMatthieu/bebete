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
        static void listeReponseFromQuestion(Question * quest, bool recursif);
        static void enregistrerQuestion(Question * quest);
};

#endif // QuestionBDD_h
