#ifndef Categorie_h
#define Categorie_h

#include <QVector>
#include <QString>

using namespace std;

class Question;

class Categorie {

    private:
        int id;
        QString label;
        QVector<Question*> myQuestion;

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
};

#endif // Categorie_h
