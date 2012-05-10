#include "Reponse.h"
#include "ListeMedia.h"
#include "Media.h"
#include "Question.h"
#include "Espece.h"

Reponse::Reponse(int id)    {
    this->id = id;
    idleft = 0;
    idright = 0;
    illustrationMedia = new ListeMedia();
    QuestionEntree = NULL;
    QuestionSortie = NULL;
    myEspece = NULL;
}

void Reponse::ajouterMedia(Media *med) {
    illustrationMedia->append(med);
}

void Reponse::supprimerMedia(Media *med) {
    int i = 0;
    while(i < illustrationMedia->size() && illustrationMedia->at(i) != med)
        i++;
    if(i < illustrationMedia->size())
        illustrationMedia->remove(i);
    else
        throw exception();
}

void Reponse::supprimerMedia(int id) {
    int i = 0;
    while(i < illustrationMedia->size() && illustrationMedia->at(i)->getIdentifiant() != id)
        i++;
    if(i < illustrationMedia->size())
        illustrationMedia->remove(i);
    else
        throw exception();
}
