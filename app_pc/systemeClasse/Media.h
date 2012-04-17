#ifndef Media_h
#define Media_h
#include <iostream>
#include <string>

class Reponse;
class Question;

class Media {
protected:
   int id;
   int Type;
   Reponse *myReponse;
   Question *myQuestion;
   char * path;
 public:
    Media();
    int getIdentifiant();
    int getType();
    const char * getPath()  {return path;}
    void setIdentifiant(int identifiant) {id = identifiant;}
    void setType(int t);
    void setPath(const char * path);
};

#endif // Media_h
