#ifndef BDD_H
#define BDD_H

#include <QByteArray>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QDir>
#include "ListeQuestion.h"
#include "Categorie.h"

class BDD {

    protected:
        /**
         * \brief attribut memorisant le noeud xml que l'on est en train de lire ou ecrire
         */
        static QDomNode currentNode;

        /**
         * \brief attribut memorisant le noeud xml que l'on est en train de lire ou ecrire sous la forme d'un pointeur
         */
        static QDomNode * currentNodeWrite;

        /**
         * \brief attribut memorisant le document que l'on est en train de lire ou ecrire
         */
        static QDomDocument doc;

    public:
        /**
         * \brief attribut memorisant la valeur actuelle de l'ID (incrémenté à chaque fois que l'on insère un élément)
         */
        static int lastId;

        /**
         *  \fn static ListeQuestion * CreerArbre()
         *  \brief lit tout l'arbre dans le fichier XML
         *  \return ListeQuestion * : la liste des questions Ã  la racine de l'arborescence
         */
        static ListeQuestion * CreerArbre(QString filePath);

        /**
         *  \fn static int enregistrerArbre(Categorie *racine)
         *  \brief enregistre le fichier xml dans un fichier passer en parametre
         *  \param Categorie *racine : la categorie en racine de l'arborescence
         *  \return int : 0 si enregistrement OK, -1 sinon
         */
        static int enregistrerArbre(Categorie *racine, QString filePath);
};

#endif // BDD_H
