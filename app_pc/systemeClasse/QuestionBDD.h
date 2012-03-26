#ifndef QuestionBDD_h
#define QuestionBDD_h

#include "BDD.h"

class Question;
class ListeQuestion;

class QuestionBDD : public BDD {

 public:
    QuestionBDD();
    ListeQuestion * CreerArbre();
};

#endif // QuestionBDD_h
