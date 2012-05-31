#include "BDD.h"
#include "categoriebdd.h"

QDomNode BDD::currentNode;
QDomDocument BDD::doc;

ListeQuestion * BDD::CreerArbre(QString filePath)
{
    QFile fichier(filePath);

    doc.setContent(&fichier);
    BDD::currentNode = doc.elementsByTagName("arbre").at(0);

    //firstchild = branche
    currentNode = currentNode.firstChild();

    Categorie * cat = new Categorie(0);

    CategorieBDD::listeQuestionWithCategorie(cat, true);

    return cat->getListeQuestion();
}

void BDD::enregistrerArbre(Categorie *racine, QString filePath)
{
    doc.clear();
    QDomNode noeud = doc.createProcessingInstruction("xml", "version=\"1.0\"");
    doc.appendChild(noeud);

    QDomElement arbre = doc.createElement("arbre");
    doc.appendChild(arbre);

    currentNode = arbre;

    CategorieBDD::enregistrerCategorie(racine);

    QFile fichier(filePath);

    if ( !fichier.open(QIODevice::WriteOnly) ) {
        qDebug("Impossible de créer le fichier xml pour sauvegarder les données");
        return;
    }
    else    {
        QTextStream textStream(&fichier);
        qDebug() <<"\n Enregistrement dans le fichier";
        textStream <<  doc.toString();
        qDebug() <<"\n Enregistrement dans le fichier OK";
    }

   fichier.close();
}
