#ifndef QuestionBDD_h
#define QuestionBDD_h

#include "BDD.h"
#include <QByteArray>
<<<<<<< HEAD
=======
#include <QDomDocument>
#include <QFile>
>>>>>>> cb7579a9876a2f7ce952f15d30d750270b925fd3

class Question;
class ListeQuestion;

class QuestionBDD : public BDD {

 public:
    QuestionBDD();
    ListeQuestion * CreerArbre();
    ListeQuestion * parseXML(QByteArray oneQByteArray);
};

#endif // QuestionBDD_h
