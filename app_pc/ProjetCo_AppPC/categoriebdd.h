#ifndef CATEGORIEBDD_H
#define CATEGORIEBDD_H

#include "Question.h"
#include "QuestionBDD.h"
#include "MediaBDD.h"
#include "Categorie.h"


class Question;
class ListeQuestion;
class ReponseBDD;
class Categorie;

class CategorieBDD : public BDD
{
public:
    static ListeQuestion * CreerArbre(QString unFilePath);
    static void listeQuestionWithCategorie(Categorie * cat, bool recursif);
};

#endif // CATEGORIEBDD_H
