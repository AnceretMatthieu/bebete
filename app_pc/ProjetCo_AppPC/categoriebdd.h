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

class CategorieBDD : public BDD
{
public:
    static ListeQuestion * CreerArbre(QString filePath);
    static void listeQuestionWithCategorie(Categorie * cat, bool recursif);
    static void enregistrerArbre(Categorie *racine, QString filePath);
    static void enregistrerCategorie(Categorie * currentCat);
};

#endif // CATEGORIEBDD_H
