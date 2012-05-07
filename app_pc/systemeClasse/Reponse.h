#ifndef Reponse_h
#define Reponse_h

#include <QVector>
#include <QString>
#define MEDIA_NOT_IN_LIST_EXCEPTION 404

class Media;
class Question;
class Espece;
class ListeMedia;

class Reponse {

    private:
        int id;
        int idleft;
        int idright;
        QString texte;

        Question * QuestionEntree;
        Question * QuestionSortie;
        Espece * myEspece;
        ListeMedia * illustrationMedia;

    public:
        Reponse(int id);

        int getIdentifiant() {
            return id;
        }

        QString getReponse() {
            return texte;
        }

        void setIdLeft(int id)  {idleft = id;}
        void setIdRight(int id)  {idright = id;}
        int getIdLeft()  {return idleft;}
        int getIdRight()  {return idright;}

        Question * getQuestionSuiv()    {return QuestionSortie;}
        Question * getQuestionPrec()    {return QuestionEntree;}

        void setReponse(QString rep) {
            texte = rep;
        }

        void setQuestionSuiv(Question * question)   {QuestionSortie = question;}
        void setQuestionPrec(Question * question)   {QuestionEntree = question;}

        ListeMedia * getListeIllustration() {return illustrationMedia;}

        void ajouterMedia(Media * med);
        void supprimerMedia(Media * med);
        void supprimerMedia(int id);
};

#endif // Reponse_h
