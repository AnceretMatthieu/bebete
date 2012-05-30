#include "BDD.h"
#include "categoriebdd.h"

QDomNode BDD::currentNode;
QDomDocument BDD::doc;

ListeQuestion * BDD::CreerArbre()
{
#ifdef Q_OS_MACX
    QDir dir(QDir::currentPath());
    dir.cd("../../..");
    QFile fichier(dir.path() + "/accueil.xml");
#else
    QFile fichier(QDir::currentPath() + "/accueil.xml");
#endif
    doc.setContent(&fichier);
    BDD::currentNode = doc.elementsByTagName("arbre").at(0);

    //firstchild = branche
    currentNode = currentNode.firstChild();

    Categorie * cat = new Categorie(0);

    CategorieBDD::listeQuestionWithCategorie(cat, true);

    return cat->getListeQuestion();
}

void BDD::enregistrerArbre(Categorie *racine)
{
    doc.clear();
    QDomNode noeud = doc.createProcessingInstruction("xml","version=\"1.0\"");
    doc.appendChild(noeud);

    QDomElement arbre = doc.createElement("arbre");
    doc.appendChild(arbre);

    currentNode = arbre;

    CategorieBDD::enregistrerCategorie(racine);

#ifdef Q_OS_MACX
    QDir dir(QDir::currentPath());
    dir.cd("../../..");
    QFile fichier(dir.path() + "/enregistrement.xml");
#else
    QFile fichier(QDir::currentPath() + "/enregistrement.xml");
#endif
    if ( !fichier.open(QIODevice::WriteOnly) ) {
        qDebug("Impossible de créer le fichier xml pour sauvegarder les données");
        return;
    }
    else    {
        QTextStream textStream(&fichier);
        qDebug() <<"\n Enregistrement dans le fichier";
        textStream <<  doc.toString();
    }

   fichier.close();
}
