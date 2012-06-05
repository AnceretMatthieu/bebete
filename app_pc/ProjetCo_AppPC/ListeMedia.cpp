#include "ListeMedia.h"
#include "Media.h"

ListeMedia::ListeMedia() : QVector<Media*>()
{

}

Media *ListeMedia::getElementById(int id)
{
    Media * temp = NULL;
    unsigned int i = 0;

    while(i < (unsigned int) this->size())  {
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

Media * ListeMedia::getElementByPath(QString path)
{
    Media * temp;
    unsigned int i = 0;

    while(i < (unsigned int) this->size())  {
        temp = this->at(i);
        if(temp->getPath() == path)
            break;
        i++;
    }

    if(i == (unsigned int)this->size())
        return temp;
    else
        return NULL;
}
