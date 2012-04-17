#ifndef ListeReponse_h
#define ListeReponse_h

#include <vector>

using namespace std;

class Reponse;

class ListeReponse : public vector<Reponse*> {
    public:
        ListeReponse();
        Reponse * getElementById(int id);
};

#endif // ListeReponse_h
