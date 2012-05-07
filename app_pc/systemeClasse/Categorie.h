#ifndef Categorie_h
#define Categorie_h

#include <QVector>
#include <QString>

using namespace std;

class Question;
class ListeQuestion;

class Categorie {

    private:
        int id;
        QString label;
        ListeQuestion * myQuestion;

    public:
        Categorie(int identifiant);

        int getIdentifiant() {
            return id;
        }

        QString getLabel() {
            return label;
        }

        void setLabel(QString unLabel) {
            label = unLabel;
        }

        void ajouterQuestion(Reponse * rep);
        void supprimerQuestion(Reponse * rep);
        ListeQuestion * getListeQuestion()  {return myQuestion;}
};

#endif // Categorie_h
