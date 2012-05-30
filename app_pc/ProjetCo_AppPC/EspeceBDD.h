#ifndef EspeceBDD_h
#define EspeceBDD_h

#include "Espece.h"
#include "BDD.h"
#include "MediaBDD.h"

/**
 *  \class EspeceBDD
 *  \brief Classe permettant de lire / é'�crire une esp�ce dans un fichier XML, hérite de la classe BDD
 *  \file especebdd.h
 */
class EspeceBDD : public BDD {

public:
    /**
     *  \fn static void enregistrerEspece(Espece * esp)
     *  \brief enregistre la categorie passé en paramètre dans le noeud courrant
     *  \param Espece * esp : l'esp�ce �  enregistrer
     */
    static void enregistrerEspece(Espece * esp);
};

#endif // EspeceBDD_h
