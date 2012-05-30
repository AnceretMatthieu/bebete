#ifndef EspeceBDD_h
#define EspeceBDD_h

#include "Espece.h"
#include "BDD.h"
#include "MediaBDD.h"

/**
 *  \class EspeceBDD
 *  \brief Classe permettant de lire / √©'Ècrire une espËce dans un fichier XML, h√©rite de la classe BDD
 *  \file especebdd.h
 */
class EspeceBDD : public BDD {

public:
    /**
     *  \fn static void enregistrerEspece(Espece * esp)
     *  \brief enregistre la categorie pass√© en param√®tre dans le noeud courrant
     *  \param Espece * esp : l'espËce √  enregistrer
     */
    static void enregistrerEspece(Espece * esp);
};

#endif // EspeceBDD_h
