#ifndef Question_h
#define Question_h

#include <vector>
#include <QString>


class ListeReponse;
class ListeMedia;
class Media;
class Reponse;
class Categorie;

class Question {

 public:
    Question();
    int getIdentifiant();
    QString getQuestion();
    void ajouterReponse(Reponse * rep);
    void supprimerReponse(Reponse * rep);
    void ajouterMedia(Media * med);
    void supprimerMedia(Media * med);
    void setQuestion(QString question);

 private:
    int id;
    QString texte;
    ListeReponse * listeReponse;
    ListeMedia * listeMedia;
    Categorie *myCategorie;
};

#endif // Question_h
