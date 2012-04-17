#ifndef ListeQuestion_h
#define ListeQuestion_h

#include <vector>

using namespace std;

class Question;

class ListeQuestion : public vector<Question*> {

    public:
        ListeQuestion();
        Question * getElementById(int id);
};

#endif // ListeQuestion_h
