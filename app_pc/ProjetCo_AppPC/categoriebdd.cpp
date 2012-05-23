#include "categoriebdd.h"

ListeQuestion * CategorieBDD::CreerArbre(QString unFilePath)
{
    //QFile fichier(QDir::currentPath() + "/accueil.xml");
    QFile fichier(unFilePath);

    QDomDocument doc;
    doc.setContent(&fichier);
    BDD::currentNode = doc.elementsByTagName("arbre").at(0);
    qDebug() << currentNode.nodeName();

    //firstchild = branche
    BDD::currentNode = currentNode.firstChild();
    qDebug() << currentNode.nodeName();

    Categorie * cat = new Categorie(0);

    listeQuestionWithCategorie(cat, true);

    return cat->getListeQuestion();
}

void CategorieBDD::listeQuestionWithCategorie(Categorie * cat, bool recursif = true)   {

    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes(); // ==> renvoi "question"

    int i;
    Question * temp;
    for(i=0; i<lstBaliseQuestion.size(); i++)  {
        //découpage du q devant l'id
        temp = new Question(lstBaliseQuestion.at(i).toElement().attribute("id").left(1).toInt());
        temp->setQuestion(lstBaliseQuestion.at(i).toElement().attribute("texte"));
        temp->setVisible(lstBaliseQuestion.at(i).toElement().attribute("visible"));

        if(i > 0)
        {
            cat->getListeQuestion()->at(i-1)->setIdRight(temp->getIdentifiant());
            temp->setIdLeft( cat->getListeQuestion()->at(i-1)->getIdentifiant());
        }
        BDD::currentNode = lstBaliseQuestion.at(i).toElement();
        if(recursif)
        {
            QuestionBDD::listeReponseFromQuestion(temp, recursif);
        }
        cat->ajouterQuestion(temp);
    }
}
