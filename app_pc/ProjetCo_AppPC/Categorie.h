#ifndef Categorie_h
#define Categorie_h

#include <QVector>
#include <QString>

#include "ListeQuestion.h"
#include "Reponse.h"

using namespace std;

class Question;
class Reponse;
class ListeQuestion;

class Categorie {

    private:
        int id;
        QString label;
        Reponse * pere;
        ListeQuestion * myQuestion;

    public:
        Categorie(int identifiant);

        int getIdentifiant() { return id; }

        QString getLabel() { return label; }

        void setLabel(QString unLabel) { label = unLabel; }

        void setReponse(Reponse * r)    { pere = r;}
        Reponse * getReponse()          { return pere; }

        void ajouterQuestion(Question * rep);
        void supprimerQuestion(Question * rep);
        ListeQuestion * getListeQuestion()  { return myQuestion; }
};

#endif // Categorie_h
