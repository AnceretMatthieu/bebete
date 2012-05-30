#ifndef ReponseBDD_h
#define ReponseBDD_h

#include "BDD.h"
#include "Reponse.h"
#include "ListeReponse.h"
#include "Question.h"
#include "Media.h"
#include "EspeceBDD.h"
#include <QMessageBox>

class Reponse;
class ListeReponse;
class Question;

/**
 *\file ReponseBDD.h
 *\class ReponseBDD
 *\brief Classe permettant d'enregistrer et lire dans un fichier XML
 */

class ReponseBDD : public BDD {

    public:
        /** \brief Constructeur par d�faut de la classe ReponseBDD
         */
        ReponseBDD();

        /** \fn ListeFromReponse
         * \param rep On r�cup�re un pointeur sur une r�ponse
         * \param recursif Bool�en afin de savoir si on a une r�ponse par la suite
         */

        static void listeFromReponse(Reponse * rep, bool recursif);
        static void enregistrerReponse(Reponse * rep);
};

#endif // ReponseBDD_h
