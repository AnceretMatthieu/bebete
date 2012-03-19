#ifndef Categorie_h
#define Categorie_h

#include <vector>

class Question;

class Categorie {

 public:

    Categorie(int identifiant);
    ~Categorie();

    int getIdentifiant();

    char * getLabel();

    void setLabel(String lab);

private:
    integer id;
    String Label;

    /**
     * @element-type Question
     */
    std::vector< Question* > myQuestion;
};

#endif // Categorie_h
