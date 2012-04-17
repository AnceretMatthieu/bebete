#include "Reponse.h"
#include "ListeReponse.h"

Reponse *ListeReponse::getElementById(int id)
{
    Reponse * temp = NULL;
    unsigned int i = 0;
    while(i< (unsigned int)this->size())  {
        temp = this->at(i);
        if(temp->getIdentifiant() == id)
            break;
        i++;
    }
    if(i == (unsigned int)this->size())
        return temp;
    else
        return NULL;
}
