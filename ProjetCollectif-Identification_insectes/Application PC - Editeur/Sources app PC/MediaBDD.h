#ifndef MEDIABDD_H
#define MEDIABDD_H

#include "Media.h"
#include "BDD.h"

/**
 *  \class MediaBDD
 *  \brief Classe permettant de lire / ecrire un média dans un fichier XML, herite de la classe BDD
 *  \file MediaBDD.h
 */
class MediaBDD : public BDD {
public:

    /**
     *  \fn static void enregistrerMedia(Media * med);
     *  \brief permet de sauvegarder un média dans un fichier XML
     *  \param Media * med : le média à remplir
     */
    static void enregistrerMedia(Media * med);
};

#endif // MEDIABDD_H
