#ifndef QUESTIONBDD_H
#define QUESTIONBDD_H

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
 *  \brief Classe permettant de lire / ecrire une question dans un fichier XML, herite de la classe BDD
 *  \file QuestionBDD.h
 */
class QuestionBDD : public BDD {

    public:

        /**
         *  \fn static void listeReponseFromQuestion(Question *quest, bool recursif);
         *  \brief lit les réponses du noeud en cours
         *  \param Question *quest : la question a remplir
         *  \param bool recursif : indique si l'on doit parcourrir les fils du noeud en cours
         */
        static void listeReponseFromQuestion(Question * quest, bool recursif);

        /**
         *  \fn static void enregistrerQuestion(Question * quest)
         *  \brief enregistre la question passée en parametre dans le noeud courrant
         *  \param Question * quest : la question a enregistrer
         */
        static void enregistrerQuestion(Question * quest);
};

#endif // QUESTIONBDD_H
