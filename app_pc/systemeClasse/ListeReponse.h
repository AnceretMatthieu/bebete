#ifndef ListeReponse_h
#define ListeReponse_h

#include <QVector>

using namespace std;

class Reponse;

class ListeReponse : public QVector<Reponse*> {

    public:
        ListeReponse();

        Reponse * getElementById(int id);
};

#endif // ListeReponse_h
