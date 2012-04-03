#ifndef Categorie_h
#define Categorie_h

#include <vector>
#include <QString>

class Question;
using namespace std;

class Categorie {

 public:
    Categorie(int identifiant);
    int getIdentifiant();
    QString getLabel();
    void setLabel(QString lab);

private:
    int id;
    QString Label;
    vector<Question*> myQuestion;
};

#endif // Categorie_h
