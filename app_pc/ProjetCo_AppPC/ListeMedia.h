#ifndef ListeMedia_h
#define ListeMedia_h

#include <QVector>
#include <QString>

using namespace std;

class Media;

/**
 *  \class ListeMedia
 *  \file ListeMedia.h
 *  \brief classe gérant un vecteur de média
 */
class ListeMedia : public QVector<Media*> {

    public:

        /**
         * \fn ListeMedia()
         * \brief constructeur par défaut
         */
        ListeMedia();

        /**
         *  \fn getElementById(int id)
         *  \brief retourne un élément grâce à son identificateur
         *  \param int id : l'identificateur de l'élément
         *  \return Media*
         */
        Media * getElementById(int id);

        /**
         *  \fn getElementByPath(QString path)
         *  \brief retourne un élément grâce à son chemin
         *  \param QString path : le chemin de l'élément
         *  \return Media*
         */
        Media * getElementByPath(QString path);
};

#endif // ListeMedia_h
