#include "Question.h"
#include "Categorie.h"

Categorie::Categorie(int identifiant)   {
    this->id = identifiant;
    myQuestion = new ListeQuestion();
}


void Categorie::ajouterQuestion(Question *rep) {
    myQuestion->append(rep);
}

void Categorie::supprimerQuestion(Question *rep) {
    int i=0;
    while(i < myQuestion->size() && myQuestion->at(i) != rep)
        i++;

    if(i != myQuestion->size())   {
        myQuestion->remove(i);
    }
}
