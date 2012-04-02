#ifndef ListeQuestion_h
#define ListeQuestion_h

#include <vector>

class Question;
using namespace std;

class ListeQuestion : public vector<Question*> {

 public:
    ListeQuestion();
    Question * getElementById(int id);
};

#endif // ListeQuestion_h
