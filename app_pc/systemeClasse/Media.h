#ifndef Media_h
#define Media_h
#include <iostream>
#include <string>

class Reponse;
class Question;

class Media {

    protected:
       int id;
       int type;
       char * path;

       Reponse *myReponse;
       Question *myQuestion;

     public:
        Media();

        int getIdentifiant() {
            return id;
        }

        int getType() {
            return type;
        }

        const char * getPath()  {
            return path;
        }

        void setIdentifiant(int identifiant) {
            id = identifiant;
        }

        void setType(int t) {
            type = t;
        }

        void setPath(char * unPath) {
            path = unPath;
        }
};

#endif // Media_h
