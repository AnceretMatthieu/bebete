#ifndef Media_h
#define Media_h

#include <iostream>
#include <QString>

class Reponse;
class Question;

class Media {

    protected:
        int id;
        int type;
        QString path;

        Reponse *myReponse;
        Question *myQuestion;

    public:
        Media();

        int getIdentifiant() {
            return id;
        }

        int getType() {
            return type;
        }

        const QString getPath()  {
            return path;
        }

        void setIdentifiant(int identifiant) {
            id = identifiant;
        }

        void setType(int t) {
            type = t;
        }

        void setPath(QString unPath) {
            path = unPath;
        }
};

#endif // Media_h
