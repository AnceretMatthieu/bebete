#ifndef ListeReponse_h
#define ListeReponse_h

#include <vector>
#include "Reponse.h"

using namespace std;
//template<class Reponse>;
class ListeReponse {//: public vector<Reponse*> {
 public:
    ListeReponse();
    Reponse * getElementById(int id);
};

#endif // ListeReponse_h
