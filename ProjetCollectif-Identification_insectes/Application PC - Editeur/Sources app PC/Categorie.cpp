#include "Question.h"
#include "Categorie.h"

Categorie::Categorie(int identifiant)   {
    this->id = identifiant;
    myQuestion = new ListeQuestion();
    this->myReponsePere = NULL;
    this->label = QString("");
}

void Categorie::ajouterQuestion(Question *rep) {
    rep->setCat(this);
    myQuestion->append(rep);
    myQuestion->setEstVide(0);
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
