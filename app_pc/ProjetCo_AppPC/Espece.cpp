#include "Reponse.h"
#include "Espece.h"
#include "ListeMedia.h"

Espece::Espece(int identifiant)    {
    id = identifiant;
    listeMedia = new ListeMedia();
}

void Espece::ajouterMedia(Media * med) {
    listeMedia->append(med);
}

void Espece::supprimerMedia(Media *med) {
    int i=0;
    while(i < listeMedia->size() && listeMedia->at(i) != med)
        i++;

    if(i != listeMedia->size())   {
        listeMedia->remove(i);
    }
}
