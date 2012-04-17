#ifndef Reponse_h
#define Reponse_h

#include <QVector>
#include <QString>


class Media;
class Question;
class Espece;
class ListeMedia;

class Reponse {

    private:
        int id;
        QString texte;

        Question * QuestionEntree;
        Question * QuestionSortie;
        Espece * myEspece;
        ListeMedia * illustrationMedia;

    public:
        Reponse();

        int getIdentifiant() {
            return id;
        }

        QString getReponse() {
            return texte;
        }

        Question * getQuestionSuiv();
        Question * getQuestionPrec();

        void setReponse(QString rep) {
            texte = rep;
        }

        void setQuestionSuiv(Question * question);
        void setQuestionPrec(Question * question);

        ListeMedia * getListeIllustration();
        void ajouterMedia(Media * med);
        void supprimerMedia(Media * med);
        void SupprimerMedia(int id);
};

#endif // Reponse_h
