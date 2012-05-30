#ifndef CATEGORIEBDD_H
#define CATEGORIEBDD_H

#include "Question.h"
#include "QuestionBDD.h"
#include "MediaBDD.h"
#include "Categorie.h"
#include "QFile.h"


class Question;
class ListeQuestion;
class ReponseBDD;
class Categorie;

/**
 *  \class CategorieBDD
 *  \brief Classe permettant de lire / écrire une categorie dans un fichier XML, hérite de la classe BDD
 *  \file categoriebdd.h
 */
class CategorieBDD : public BDD
{
public:
    /**
     *  \fn static void listeQuestionWithCategorie(Categorie * cat, bool recursif);
     *  \brief lit les questions du noeud en cours et remplie la catégorie passé en paramètre
     *  \param Categorie * cat : la categorie �  remplir
     *  \param bool recursif : indique si l'on doit parcourrir les fils du noeud en cours
     */
    static void listeQuestionWithCategorie(Categorie * cat, bool recursif);

    /**
     *  \fn static void enregistrerCategorie(Categorie * currentCat)
     *  \brief enregistre la categorie passé en paramètre dans le noeud courrant
     *  \param Categorie * currentCat : la categorie �  enregistrer
     */
    static void enregistrerCategorie(Categorie * currentCat);

};

#endif // CATEGORIEBDD_H
