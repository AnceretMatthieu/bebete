#ifndef QuestionBDD_h
#define QuestionBDD_h

#include "BDD.h"
#include "ListeQuestion.h"
#include "Question.h"


class QuestionBDD : public BDD {

 public:
    QuestionBDD();
    ListeQuestion * CreerArbre();
};

#endif // QuestionBDD_h