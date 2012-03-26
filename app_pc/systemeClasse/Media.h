#ifndef Media_h
#define Media_h

#include "Reponse.h"
#include "Media.h"
#include "Question.h"

class Media {

 public:

    Media();
    int getIdentifiant();
    int getType();
    void setType(int t);

 private:
    int id;
    int Type;
    Reponse *myReponse;
    Question *myQuestion;
    Reponse *myReponse;
};

#endif // Media_h
