#ifndef ListeQuestion_h
#define ListeQuestion_h

#include <QVector>

using namespace std;

class Question;

class ListeQuestion : public QVector<Question*> {

    public:
        ListeQuestion();

        Question * getElementById(int id);
};

#endif // ListeQuestion_h
