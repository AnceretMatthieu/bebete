#include "Reponse.h"
#include "Question.h"
#include "Media.h"

int Media::getIdentifiant() {
    return id;
}

int Media::getType()    {
    return Type;
}

void Media::setType(int t)  {
    Type = t;
}
