#include "Question.h"
#include "Categorie.h"

Categorie::Categorie(int identifiant)   {
    this->id = identifiant;
    myQuestion = new ListeQuestion();
    this->myReponsePere = NULL;
}


void Categorie::ajouterQuestion(Question *rep) {
    rep->setCat(this);
    myQuestion->append(rep);
}

void Categorie::supprimerQuestion(Question *rep) {
    int i=0;
    while(i < myQuestion->size() && myQuestion->at(i) != rep)
        i++;

    if(i != myQuestion->size())   {
        myQuestion->at(i)->setCat(NULL);
        myQuestion->remove(i);
    }
}
