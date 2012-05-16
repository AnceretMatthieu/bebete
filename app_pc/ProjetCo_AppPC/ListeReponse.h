#ifndef ListeReponse_h
#define ListeReponse_h

#include <QVector>
#include "Reponse.h"

using namespace std;

class Reponse;

class ListeReponse : public QVector<Reponse*> {

    public:
        ListeReponse();

        /**
         *  Retourne l'élément avec l'identifiant passé en paramètre
         *  NB : est différent de at(int) qui retourne l'élément dans le vecteur �  l'indice passé en paramètre
         */
        Reponse * getElementById(int id);
};

#endif // ListeReponse_h
