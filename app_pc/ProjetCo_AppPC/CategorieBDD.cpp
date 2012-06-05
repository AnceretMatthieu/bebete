#include "categoriebdd.h"
#include <QIODevice>

void CategorieBDD::listeQuestionWithCategorie(Categorie * cat, bool recursif = true)   {

    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes(); // ==> renvoi "question"

    int i;
    Question * temp;
    for(i=0; i<lstBaliseQuestion.size(); i++)  {

        //découpage du q devant l'id
        QString s3 = lstBaliseQuestion.at(i).toElement().attribute("id", QString("0"));
        temp = new Question(s3.toInt());
        if(s3.toInt() > BDD::lastId)
            BDD::lastId = s3.toInt();
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

void CategorieBDD::enregistrerCategorie(Categorie * currentCat) {
    QDomNode * memoire = currentNodeWrite;
    QDomElement root = doc.createElement("branche");
    QString id = QString::number(currentCat->getIdentifiant());
    root.setAttribute("id", id);
    root.setAttribute("type", currentCat->getLabel());
    if(currentCat->getIdentifiant() > BDD::lastId)
        BDD::lastId = currentCat->getIdentifiant();

    currentNodeWrite->appendChild(root);

    currentNodeWrite = &root;

    ListeQuestion *lq = currentCat->getListeQuestion();
    for(int i = 0; i < lq->size(); i++) {
        QuestionBDD::enregistrerQuestion(lq->at(i));
    }
    currentNodeWrite = memoire;
}
