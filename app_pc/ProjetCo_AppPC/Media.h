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
         * \param int idenfifiant : l'identifiant unique du media à instancier
         */
        Media(int identifiant);

        /**
         *  \fn int getIdentifiant()
         *  \brief retourne l'identifiant du média
         *  \return int
         */
        int getIdentifiant() {
            return id;
        }

        /**
         *  \fn int getType()
         *  \brief retourne le type de media
         *  \return type
         */
        int getType() {
            return type;
        }

        /**
         *  \fn QString getPath()
         *  \brief retourne le chemin du media
         *  \return type
         */
        const QString getPath()  {
            return path;
        }

        /**
         *  \fn void setIdentifiant(int identifiant)
         *  \brief change l'identifiant du média
         *  \param int identifiant
         */
        void setIdentifiant(int identifiant) {
            id = identifiant;
        }

        /**
         *  \fn void setType(int t)
         *  \brief change le type du media
         *  \param int t
         */
        void setType(int t) {
            type = t;
        }

        /**
         *  \fn void setPath(QString unPath)
         *  \brief change le chemin du média
         *  \param QString unPath
         */
        void setPath(QString unPath) {
            path = unPath;
        }
};

#endif // Media_h
