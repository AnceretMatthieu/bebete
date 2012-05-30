#include "categoriebdd.h"
#include <QIODevice>

void CategorieBDD::listeQuestionWithCategorie(Categorie * cat, bool recursif = true)   {

    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes(); // ==> renvoi "question"
    //qDebug() << "In listeQuestionWithCategorie(" << cat->getIdentifiant() << ", " << recursif << ")";
    //qDebug() << "nombre de question " << lstBaliseQuestion.size();

    int i;
    Question * temp;
    for(i=0; i<lstBaliseQuestion.size(); i++)  {
        temp = new Question(lstBaliseQuestion.at(i).toElement().attribute("id").left(1).toInt());
        temp->setQuestion(lstBaliseQuestion.at(i).toElement().attribute("texte"));
        temp->setVisible(lstBaliseQuestion.at(i).toElement().attribute("visible"));

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

void CategorieBDD::enregistrerCategorie(Categorie * currentCat) {
    QDomNode memoire = currentNode;
    QDomElement root = doc.createElement("branche");
    root.setAttribute("id", "b"+QString::number(currentCat->getIdentifiant()));
    root.setAttribute("type", currentCat->getLabel());
    currentNode.appendChild(root);

    currentNode = root;

    ListeQuestion *lq = currentCat->getListeQuestion();
    for(int i = 0; i < lq->size(); i++) {
        QuestionBDD::enregistrerQuestion(lq->at(i));
    }
    currentNode = memoire;
}
