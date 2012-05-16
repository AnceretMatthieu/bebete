#include <QtCore/QCoreApplication>
#include <iostream>
#include "ListeMedia.h"
#include "ListeQuestion.h"
#include "ListeReponse.h"
#include "categoriebdd.h"
#include "BDD.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    //QuestionBDD * o = new QuestionBDD();
    Categorie* categ = new Categorie(1);
    ListeQuestion * lq = CategorieBDD::CreerArbre();
    categ->ajouterQuestion(lq->at(0));
    CategorieBDD::enregistrerArbre(categ);
    //o->CreerArbre();

    return a.exec();
}
