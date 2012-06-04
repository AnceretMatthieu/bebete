#ifndef BDD_h
#define BDD_h

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
         * \brief attribut mémorisant le noeud xml que l'on est en train de lire ou ecrire
         */
        static QDomNode currentNode;
        static QDomNode * currentNodeWrite;
        /**
         * \brief attribut mémorisant le document que l'on est en train de lire ou ecrire
         */
         static QDomDocument doc;
    public:
        /**
         *  \fn static ListeQuestion * CreerArbre()
         *  \brief lit tout l'arbre dans le fichier XML
         *  \return ListeQuestion * : la liste des questions �  la racine de l'arborescence
         */
        static ListeQuestion * CreerArbre(QString filePath);

        /**
         *  \fn static void enregistrerArbre(Categorie *racine)
         *  \brief enregistre le fichier xml dans un fichier passer en paramètre
         *  \param Categorie *racine : la categorie en racine de l'arborescence
         */
        static void enregistrerArbre(Categorie *racine, QString filePath);
};

#endif // BDD_h
