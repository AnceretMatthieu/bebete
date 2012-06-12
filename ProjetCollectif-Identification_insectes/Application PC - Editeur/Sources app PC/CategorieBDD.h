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
 *  \brief Classe permettant de lire / ecrire une categorie dans un fichier XML, herite de la classe BDD
 *  \file CategorieBDD.h
 */
class CategorieBDD : public BDD {

    public:

        /**
         *  \fn static void listeQuestionWithCategorie(Categorie * cat, bool recursif);
         *  \brief lit les questions du noeud en cours et remplie la categorie passée en parametre
         *  \param Categorie * cat : la categorie a remplir
         *  \param bool recursif : indique si l'on doit parcourrir les fils du noeud en cours
         */
        static void listeQuestionWithCategorie(Categorie * cat, bool recursif);

        /**
         *  \fn static void enregistrerArbre(Categorie * racine, QString filePath);
         *  \brief permet de sauvegarder l'arbre en mémoire dans un fichier XML
         *  \param Categorie * racine : la categorie à remplir
         *  \param QString filePath : chemin du fichier XML à produire
         */
        static void enregistrerArbre(Categorie *racine, QString filePath);

        /**
         *  \fn static void enregistrerCategorie(Categorie * currentCat)
         *  \brief enregistre la categorie passée en parametre dans le noeud courrant
         *  \param Categorie * currentCat : la categorie a enregistrer
         */
        static void enregistrerCategorie(Categorie * currentCat);
};

#endif // CATEGORIEBDD_H
