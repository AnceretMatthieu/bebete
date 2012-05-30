#ifndef ListeReponse_h
#define ListeReponse_h

#include <QVector>
#include "Reponse.h"

using namespace std;

class Reponse;

/**
 *  \class ListeReponse
 *  \file ListeReponse.h
 *  \brief classe g�rant un vecteur de r�ponse
 */
class ListeReponse : public QVector<Reponse*> {

    public:
        /**
         * \fn ListeReponse()
         * \brief constructeur par d�faut
         */
        ListeReponse();
        /**
         *  \fn getElementById(int id)
         *  \brief retourne l'�l�ment gr�ce � l'identifiant pass� en param�tre
         *  \param int id : l'identificateur de l'�l�ment
         *  \return Reponse*
         */
        Reponse * getElementById(int id);
};

#endif // ListeReponse_h
