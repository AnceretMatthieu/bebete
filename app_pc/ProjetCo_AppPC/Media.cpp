#include "Reponse.h"
#include "Question.h"
#include "Media.h"

Media::Media(int identifiant)   {
    id = identifiant;
    myQuestion = NULL;
    myReponse = NULL;
    path = QString("");
    this->type = 0;
}
