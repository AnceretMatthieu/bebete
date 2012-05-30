#ifndef ListeQuestion_h
#define ListeQuestion_h

#include <QVector>

using namespace std;

class Question;

class ListeQuestion : public QVector<Question*> {

    private :
        int estVide;

    public:
        ListeQuestion();

        Question * getElementById(int id);

        int getEstVide() { return estVide; }
        void setEstVide(int unBool) { estVide = unBool; }
};

#endif // ListeQuestion_h
