#ifndef QuestionBDD_h
#define QuestionBDD_h

#include "BDD.h"
#include <QByteArray>
#include <QDomDocument>
#include <QFile>


class Question;
class ListeQuestion;

class QuestionBDD : public BDD {

 public:
    QuestionBDD();
    ListeQuestion * CreerArbre();
    ListeQuestion * parseXML(QByteArray oneQByteArray);
};

#endif // QuestionBDD_h
