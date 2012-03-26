#ifndef Question_h
#define Question_h

#include <vector>

class ListeReponse;
class ListeMedia;
class Media;
class Reponse;
class Categorie;

class Question {

 public:
    Question();
    int getIdentifiant();
    char * getQuestion();
    void ajouterReponse(Reponse * rep);
    void supprimerReponse(Reponse * rep);
    void ajouterMedia(Media * med);
    void supprimerMedia(Media * med);
    void setQuestion(char * question);

 private:
    int id;
    char * texte;
    ListeReponse * listeReponse;
    ListeMedia * listeMedia;
    Categorie *myCategorie;
};

#endif // Question_h
