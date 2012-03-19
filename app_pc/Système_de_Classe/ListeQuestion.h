#ifndef ListeQuestion_h
#define ListeQuestion_h

#include <vector>
#include "Question.h"


class ListeQuestion : public std::vector {

 public:

    Question getElementById(int id);
};

#endif // ListeQuestion_h
