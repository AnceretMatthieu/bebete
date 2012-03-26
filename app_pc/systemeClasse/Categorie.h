#ifndef Categorie_h
#define Categorie_h

#include <vector>
#include "Question.h"

using namespace std;
class Categorie {

 public:
    Categorie(int identifiant);
    int getIdentifiant();
    char * getLabel();
    void setLabel(char* lab);

private:
    int id;
    char * Label;
    vector<Question*> myQuestion;
};

#endif // Categorie_h
