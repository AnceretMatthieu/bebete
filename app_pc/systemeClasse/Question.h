#ifndef Question_h
#define Question_h

#include <QVector>
#include <QString>

class ListeReponse;
class ListeMedia;
class Media;
class Reponse;
class Categorie;

class Question {

    private:
       int id;
       int idleft;
       int idright;
       QString texte;

       ListeReponse * listeReponse;
       ListeMedia * listeMedia;
       Categorie *myCategorie;

    public:
        Question(int id);
        int getIdentifiant() {return id;}
        QString getQuestion() {return texte;}

        void setIdLeft(int id)  {idleft = id;}
        void setIdRight(int id)  {idright = id;}
        int getIdLeft()  {return idleft;}
        int getIdRight()  {return idright;}

        void setQuestion(QString question) {texte = question;}

        void ajouterReponse(Reponse * rep);
        void supprimerReponse(Reponse * rep);

        void ajouterMedia(Media * med);
        void supprimerMedia(Media * med);
};

#endif // Question_h
