#ifndef ListeMedia_h
#define ListeMedia_h

#include <QVector>
#include <QString>

using namespace std;

class Media;

/**
 *  \class ListeMedia
 *  \file ListeMedia.h
 *  \brief classe g�rant un vecteur de m�dia
 */
class ListeMedia : public QVector<Media*> {

    public:

        /**
         * \fn ListeMedia()
         * \brief constructeur par d�faut
         */
        ListeMedia();

        /**
         *  \fn getElementById(int id)
         *  \brief retourne un �l�ment gr�ce � son identificateur
         *  \param int id : l'identificateur de l'�l�ment
         *  \return Media*
         */
        Media * getElementById(int id);

        /**
         *  \fn getElementByPath(QString path)
         *  \brief retourne un �l�ment gr�ce � son chemin
         *  \param QString path : le chemin de l'�l�ment
         *  \return Media*
         */
        Media * getElementByPath(QString path);
};

#endif // ListeMedia_h
