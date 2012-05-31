#ifndef MediaBDD_h
#define MediaBDD_h

#include "Media.h"
#include "BDD.h"

/**
 *  \class MediaBDD
 *  \brief Classe permettant de lire / écrire un m�dia dans un fichier XML, hérite de la classe BDD
 *  \file mediabdd.h
 */
class MediaBDD : public BDD {
public:

    /**
     *  \fn static void enregistrerMedia(Media* med);
     *  \brief permet de sauvegarder un m�dia dans un fichier XML
     *  \param Media* med : le m�dia � remplir
     */
    static void enregistrerMedia(Media* med);
};

#endif // MediaBDD_h
