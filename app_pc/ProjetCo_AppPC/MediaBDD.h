#ifndef MediaBDD_h
#define MediaBDD_h

#include "Media.h"
#include "BDD.h"

/**
 *  \class MediaBDD
 *  \brief Classe permettant de lire / Ã©crire un média dans un fichier XML, hÃ©rite de la classe BDD
 *  \file mediabdd.h
 */
class MediaBDD : public BDD {
public:

    /**
     *  \fn static void enregistrerMedia(Media* med);
     *  \brief permet de sauvegarder un média dans un fichier XML
     *  \param Media* med : le média à remplir
     */
    static void enregistrerMedia(Media* med);
};

#endif // MediaBDD_h
