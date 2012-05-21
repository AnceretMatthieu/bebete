#include "ListeMedia.h"
#include "ListeReponse.h"
#include "Media.h"
#include "Reponse.h"
#include "Categorie.h"
#include "Question.h"


Question::Question(int id) {
    this->id = id;
    this->idleft = 0;
    this->idright = 0;
    listeReponse = new ListeReponse();
    listeMedia = new ListeMedia();
    this->texte = QString();
    myCategorie = NULL;
}

void Question::ajouterReponse(Reponse *rep) {
    rep->setPrec(this);
    listeReponse->append(rep);
}

void Question::supprimerReponse(Reponse *rep) {
    int i=0;
    while(i < listeReponse->size() && listeReponse->at(i) != rep)
        i++;

    if(i != listeReponse->size())   {
        listeReponse->at(i)->setPrec(NULL);
        listeReponse->remove(i);
    }
}

void Question::ajouterMedia(Media * med) {
    listeMedia->append(med);
}

void Question::supprimerMedia(Media *med) {
    int i=0;
    while(i < listeMedia->size() && listeMedia->at(i) != med)
        i++;

    if(i != listeMedia->size())   {
        listeMedia->remove(i);
    }
}
