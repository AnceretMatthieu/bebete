#ifndef ESPECEBDD_H
#define ESPECEBDD_H

#include "Espece.h"
#include "BDD.h"
#include "MediaBDD.h"

/**
 *  \class EspeceBDD
 *  \brief Classe permettant de lire / ecrire une esp�ce dans un fichier XML, herite de la classe BDD
 *  \file especebdd.h
 */
class EspeceBDD : public BDD {

public:
    /**
     *  \fn static void enregistrerEspece(Espece * esp)
     *  \brief enregistre la categorie pass�e en parametre dans le noeud courrant
     *  \param Espece * esp : l'esp�ce a enregistrer
     */
    static void enregistrerEspece(Espece * esp);
};

#endif // ESPACEBDD_H
