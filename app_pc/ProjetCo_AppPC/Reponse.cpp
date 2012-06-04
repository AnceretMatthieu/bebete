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
}

void Reponse::supprimerMedia(int id) {
    int i = 0;
    while(i < illustrationMedia->size() && illustrationMedia->at(i)->getIdentifiant() != id)
        i++;
    if(i < illustrationMedia->size())
        illustrationMedia->remove(i);
}

void  Reponse::setTypeSuiv(int type) {
    if(type == TYPE_ESPECE || type == TYPE_CATEGORIE)
        typeFils = type;
}

void  Reponse::setTypePrec(int type) {
    if(type == TYPE_ESPECE || type == TYPE_CATEGORIE)
        typePere = type;
}

void Reponse::setSuiv(void * suiv)   {
    fils = suiv;
    if(typePere == TYPE_ESPECE)
        ((Espece*)suiv)->setReponse(this);
    else
        ((Categorie*)suiv)->setReponse(this);
}

void * Reponse::getSuiv()            {
    return fils;
}

void Reponse::setPrec(void * prec)   {
    pere = prec;
}

void * Reponse::getPrec()            {
    return pere;
}
