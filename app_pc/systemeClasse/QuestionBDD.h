#ifndef QuestionBDD_h
#define QuestionBDD_h

#include "BDD.h"

class Question;
class ListeQuestion;

class QuestionBDD : public BDD {

 public:
    QuestionBDD();
    ListeQuestion * CreerArbre();
    ListeQuestion * parseXML(QByteArray oneQByteArray);
};

#endif // QuestionBDD_h
