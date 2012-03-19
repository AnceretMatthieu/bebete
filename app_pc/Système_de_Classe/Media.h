#ifndef Media_h
#define Media_h

#include "Reponse.h"
#include "Media.h"
#include "Question.h"

class Reponse;
class Question;

class Media {

 public:

    int getIdentifiant();

    int getType();

    void setType(int t);

 private:
    int id;
    int Type;

    /**
     * @element-type Reponse
     */
    Reponse *myReponse;

    /**
     * @element-type Question
     */
    Question *myQuestion;

    /**
     * @element-type Reponse
     */
    Reponse *myReponse;
};

#endif // Media_h
