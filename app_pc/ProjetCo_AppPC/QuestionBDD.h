#ifndef QuestionBDD_h
#define QuestionBDD_h

#include "BDD.h"
#include "ListeQuestion.h"
#include "ListeReponse.h"
#include "Question.h"
#include "ReponseBDD.h"
#include "MediaBDD.h"
#include "Categorie.h"
#include "ListeMedia.h"

class Question;
class ListeQuestion;
class ReponseBDD;
class Categorie;

/**
 *  \class QuestionBDD
 *  \brief Classe permettant de lire / écrire une question dans un fichier XML, hérite de la classe BDD
 *  \file questionbdd.h
 */
class QuestionBDD : public BDD {

    public:

        /**
         *  \fn static void listeReponseFromQuestion(Question *quest, bool recursif);
         *  \brief lit les r�ponses du noeud en cours
         *  \paramQuestion *quest : la question �  remplir
         *  \param bool recursif : indique si l'on doit parcourrir les fils du noeud en cours
         */
        static void listeReponseFromQuestion(Question * quest, bool recursif);

        /**
         *  \fn static void enregistrerQuestion(Question * quest)
         *  \brief enregistre la question passé en paramètre dans le noeud courrant
         *  \param Question * quest : la question �  enregistrer
         */
        static void enregistrerQuestion(Question * quest);
};

#endif // QuestionBDD_h
