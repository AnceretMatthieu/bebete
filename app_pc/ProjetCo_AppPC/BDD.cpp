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

void BDD::enregistrerArbre(Categorie *racine, QString filePath)
{
    BDD::doc = QDomDocument("");

    QDomNode noeud = doc.createProcessingInstruction("xml", "version=\"1.0\"");
    doc.appendChild(noeud);

    QDomElement arbre = doc.createElement("arbre");
    doc.appendChild(arbre);

    currentNodeWrite = &arbre;

    CategorieBDD::enregistrerCategorie(racine);

    QFile fichier(filePath);

    if ( !fichier.open(QIODevice::WriteOnly) )
    {
        qDebug("Impossible de créer le fichier XML pour sauvegarder les données");
        return;
    }
    else
    {
        QTextStream textStream(&fichier);
        qDebug() << "Enregistrement dans le fichier";

        doc.save(textStream, 5);

        qDebug() << "Enregistrement dans le fichier OK";
    }

   fichier.close();
}
