#include "BDD.h"
#include "categoriebdd.h"

QDomNode BDD::currentNode;
QDomNode * BDD::currentNodeWrite;
QDomDocument BDD::doc;
int BDD::lastId = 0;

ListeQuestion * BDD::CreerArbre(QString filePath)
{
    QFile fichier(filePath);

    doc.setContent(&fichier);
    BDD::currentNode = doc.elementsByTagName("arbre").at(0);

    //firstchild = branche
    currentNode = currentNode.firstChild();

    Categorie * cat = new Categorie(0);
    lastId = 0;

    CategorieBDD::listeQuestionWithCategorie(cat, true);

    return cat->getListeQuestion();
}

int BDD::enregistrerArbre(Categorie *racine, QString filePath)
{
    BDD::doc = QDomDocument("");

    QDomNode noeud = doc.createProcessingInstruction("xml", "version=\"1.0\"");
    doc.appendChild(noeud);

    QDomElement arbre = doc.createElement("arbre");
    doc.appendChild(arbre);

    currentNodeWrite = &arbre;

    CategorieBDD::enregistrerCategorie(racine);

    QFile fichier(filePath);

    if (!fichier.open(QIODevice::WriteOnly))
    {
        return -1; // erreur dans l'enregistrement
    }
    else
    {
        QTextStream textStream(&fichier);
        doc.save(textStream, 5);
    }

   fichier.close();
   return 0; // enregistrement OK
}
