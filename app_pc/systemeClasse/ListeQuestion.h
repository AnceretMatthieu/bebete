#ifndef ListeQuestion_h
#define ListeQuestion_h

#include <vector>
#include "Question.h"

using namespace std;
//template<class Question>;
class ListeQuestion {//: public vector<Question*> {

 public:
    ListeQuestion();
    Question * getElementById(int id);
};

#endif // ListeQuestion_h
