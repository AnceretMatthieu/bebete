#ifndef ListeReponse_h
#define ListeReponse_h

#include <vector>

class Reponse;
using namespace std;

class ListeReponse : public vector<Reponse*> {
 public:
    ListeReponse();
    Reponse * getElementById(int id);
};

#endif // ListeReponse_h
