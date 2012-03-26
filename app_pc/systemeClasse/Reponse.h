#ifndef Reponse_h
#define Reponse_h

#include <vector>

class Media;
class Question;
class Espece;
class ListeMedia;

class Reponse {
 public:
    Reponse();
    int getIdentifiant();
    char * getReponse();
    void AjouterMedia(Media * media);
    void SupprimerMedia(int id);
    Question * getQuestionSuiv();
    Question * getQuestionPrec();
    ListeMedia * getListeIllustration();
    void setReponse(char * rep);
    void setQuestionSuiv(Question * question);
    void setQuestionPrec(Question * question);
    void ajouterMedia(Media * med);
    void supprimerMedia(Media * med);

 private:
    int id;
    char * texte;
    Question * QuestionEntree;
    Question * QuestionSortie;
    Espece * myEspece;
    ListeMedia * illustrationMedia;
};

#endif // Reponse_h
