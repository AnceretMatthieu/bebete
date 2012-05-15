#ifndef Reponse_h
#define Reponse_h

#include <QVector>
#include <QString>
#define MEDIA_NOT_IN_LIST_EXCEPTION 404
#define TYPE_ESPECE 0
#define TYPE_CATEGORIE 1

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

        void * pere;
        void * fils;
        int typePere;
        int typeFils;

        ListeMedia * illustrationMedia;

    public:
        Reponse(int id);

        int getIdentifiant() {  return id; }
        QString getReponse() {  return texte;   }

        void setSuiv(void * suiv)   {   fils = suiv; }
        void * getSuiv()            { return fils; }
        void setPrec(void * prec)   {   pere = prec; }
        void * getPrec()            { return pere; }

        void setTypeSuiv(int type);
        int getTypeSuiv()   {return typeFils;}

        void setTypePrec(int type);
        int getTypePrec()   {return typePere;}

        void setIdLeft(int id)  {idleft = id;}
        void setIdRight(int id)  {idright = id;}
        int getIdLeft()  {return idleft;}
        int getIdRight()  {return idright;}

        void setReponse(QString rep) {
            texte = rep;
        }

        ListeMedia * getListeIllustration() {return illustrationMedia;}

        void ajouterMedia(Media * med);
        void supprimerMedia(Media * med);
        void supprimerMedia(int id);
};

#endif // Reponse_h
