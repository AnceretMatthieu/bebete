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
       QString visible;

       ListeReponse * listeReponse;
       ListeMedia * listeMedia;
       Categorie *myCategorie;

    public:
        Question(int id);
        Question(Question *);

        int getIdentifiant() { return id; }
        QString getQuestion() { return texte; }
        QString getVisible() { return visible; }

        void setVisible(QString visible) {this->visible = visible;}
        void setIdLeft(int id)  {idleft = id;}
        void setIdRight(int id)  {idright = id;}
        int getIdLeft()  {return idleft;}
        int getIdRight()  {return idright;}

        void setCat(Categorie * c)  { myCategorie = c;}
        Categorie * getCat()    { return myCategorie; }


        void setQuestion(QString question) {texte = question;}

        void ajouterReponse(Reponse * rep);
        void supprimerReponse(Reponse * rep);
        ListeReponse* getListeReponse()  {return listeReponse;}

        void ajouterMedia(Media * med);
        void supprimerMedia(Media * med);
        ListeMedia * getListeMedia()    {return listeMedia;}
};

#endif // Question_h
