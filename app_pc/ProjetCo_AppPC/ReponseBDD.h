#ifndef REPONSEBDD_H
#define REPONSEBDD_H

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
 *\brief Classe permettant de lire / ecrire une r�ponse dans un fichier XML, herite de la classe BDD
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
         *  \param Reponse *rep : la r�ponse a remplir
         *  \param bool recursif : indique si l'on doit parcourrir les fils du noeud en cours
         */
        static void listeFromReponse(Reponse * rep, bool recursif);

        /**
         *  \fn static void enregistrerReponse(Reponse * rep)
         *  \brief enregistre la r�ponse pass�e en parametre dans le noeud courrant
         *  \param Reponse * rep : la r�ponse a enregistrer
         */
        static void enregistrerReponse(Reponse * rep);
};

#endif // REPONSEBDD_H
