#ifndef Media_h
#define Media_h

#include <iostream>
#include <QString>

#define MEDIA_TYPE_VIDEO    0
#define MEDIA_TYPE_IMAGE    1
#define MEDIA_TYPE_TEXT     2
#define MEDIA_TYPE_AUDIO    3

class Reponse;
class Question;

/**
 *  \class Media
 *  \file Media.h
 *  \brief classe gÃ©rant un  média avec sa description
 */
class Media {

    protected:
        int id;
        int type;
        QString path;

        Reponse *myReponse;
        Question *myQuestion;

    public:
        /**
         * \fn Media(int identifiant)
         * \brief constructeur
         */
        Media(int identifiant);

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
