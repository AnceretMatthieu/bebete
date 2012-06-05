#include "categoriebdd.h"
#include <QIODevice>

void CategorieBDD::listeQuestionWithCategorie(Categorie * cat, bool recursif = true)   {

    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes(); // ==> renvoi "question"

    int i;
    Question * temp;
    for(i=0; i<lstBaliseQuestion.size(); i++)  {

        //découpage du q devant l'id
        temp = new Question(0);
        QString s = lstBaliseQuestion.at(i).toElement().attribute("texte", QString(""));
        if(s.size() != 0)
            temp->setQuestion(s);
        QString s1 = lstBaliseQuestion.at(i).toElement().attribute("visible", QString(""));
        if(s1.size() != 0)
            temp->setVisible(s1);

        if(i > 0)   {
             cat->getListeQuestion()->at(i-1)->setIdRight(temp->getIdentifiant());
            temp->setIdLeft( cat->getListeQuestion()->at(i-1)->getIdentifiant());
        }
        BDD::currentNode = lstBaliseQuestion.at(i).toElement();
        if(recursif)
            QuestionBDD::listeReponseFromQuestion(temp, recursif);
        cat->ajouterQuestion(temp);
    }
}

void CategorieBDD::enregistrerArbre(Categorie *racine, QString filePath)
{
    doc.clear();
    QDomNode noeud = doc.createProcessingInstruction("xml", "version=\"1.0\"");
    doc.appendChild(noeud);

    QDomElement arbre = doc.createElement("arbre");
    doc.appendChild(arbre);

    currentNode = arbre;

    QFile fichier(filePath);

    if (!fichier.open(QIODevice::WriteOnly)) {
        qDebug("Impossible de créer le fichier xml pour sauvegarder les données");
        return;
    }
    else {
        QTextStream textStream(&fichier);

        enregistrerCategorie(racine);

        qDebug() << "Enregistrement dans le fichier";
        textStream << doc.toString();
    }

    fichier.close();
}

void CategorieBDD::enregistrerCategorie(Categorie * currentCat) {
    QDomNode * memoire = currentNodeWrite;
    QDomElement root = doc.createElement("branche");
    root.setAttribute("id", "b0");
    root.setAttribute("type", currentCat->getLabel());
    currentNodeWrite->appendChild(root);

    currentNodeWrite = &root;

    ListeQuestion *lq = currentCat->getListeQuestion();
    for(int i = 0; i < lq->size(); i++) {
        QuestionBDD::enregistrerQuestion(lq->at(i));
    }
    currentNodeWrite = memoire;
}
