#ifndef ListeReponse_h
#define ListeReponse_h

#include <QVector>
#include "Reponse.h"

using namespace std;

class Reponse;

/**
 *  \class ListeReponse
 *  \file ListeReponse.h
 *  \brief classe gérant un vecteur de réponse
 */
class ListeReponse : public QVector<Reponse*> {

    public:
        /**
         * \fn ListeReponse()
         * \brief constructeur par défaut
         */
        ListeReponse();
        /**
         *  \fn getElementById(int id)
         *  \brief retourne l'élément grâce à l'identifiant passé en paramètre
         *  \param int id : l'identificateur de l'élément
         *  \return Reponse*
         */
        Reponse * getElementById(int id);
};

#endif // ListeReponse_h
