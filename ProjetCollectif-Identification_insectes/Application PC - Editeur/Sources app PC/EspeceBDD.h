#ifndef ESPECEBDD_H
#define ESPECEBDD_H

#include "Espece.h"
#include "BDD.h"
#include "MediaBDD.h"

/**
 *  \class EspeceBDD
 *  \brief Classe permettant de lire / ecrire une espèce dans un fichier XML, herite de la classe BDD
 *  \file especebdd.h
 */
class EspeceBDD : public BDD {

public:
    /**
     *  \fn static void enregistrerEspece(Espece * esp)
     *  \brief enregistre la categorie passée en parametre dans le noeud courrant
     *  \param Espece * esp : l'espèce a enregistrer
     */
    static void enregistrerEspece(Espece * esp);
};

#endif // ESPACEBDD_H
