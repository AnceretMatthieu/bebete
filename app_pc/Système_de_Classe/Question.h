#ifndef Question_h
#define Question_h

#include <vector>

#include "ListeMedia.h"
#include "ListeReponse.h"
#include "Media.h"
#include "Reponse.h"
#include "Question.h"
#include "Categorie.h"

class Question {

 public:

    int getIdentifiant();

    char * getQuestion();

    void ajouterReponse(Reponse rep);

    void supprimerReponse(Reponse rep);

    void ajouterMedia(Media med);

    void supprimerMedia(Media med);

    void setQuestion(char * question);

 private:
    int id;
    char * texte;
    ListeReponse listeReponse;
    ListeMedia listeMedia;
    Categorie *myCategorie;
};

#endif // Question_h
