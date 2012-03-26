#ifndef Media_h
#define Media_h

class Reponse;
class Question;

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
};

#endif // Media_h
