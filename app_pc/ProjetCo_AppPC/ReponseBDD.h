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
 *\brief Classe permettant de lire / écrire une r�ponse dans un fichier XML, hérite de la classe BDD
 */

class ReponseBDD : public BDD {

    public:
        /**
         *\fn ReponseBDD()
         *\brief Constructeur par d�faut de la classe ReponseBDD
         */
        ReponseBDD();

        /**
         *  \fn static void listeFromReponse(Reponse *rep, bool recursif);
         *  \brief lit les r�sultats du noeud en cours
         *  \param Reponse *rep : la r�ponse �  remplir
         *  \param bool recursif : indique si l'on doit parcourrir les fils du noeud en cours
         */
        static void listeFromReponse(Reponse * rep, bool recursif);

        /**
         *  \fn static void enregistrerReponse(Reponse * rep)
         *  \brief enregistre la r�ponse passé en paramètre dans le noeud courrant
         *  \param Reponse * rep : la r�ponse �  enregistrer
         */
        static void enregistrerReponse(Reponse * rep);
};

#endif // ReponseBDD_h
