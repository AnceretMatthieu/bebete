#include "QuestionBDD.h"
#include "ListeQuestion.h"
#include "ListeReponse.h"
#include "Question.h"
#include "ReponseBDD.h"
#include "MediaBDD.h"
#include "Categorie.h"

QuestionBDD::QuestionBDD() {

}

ListeQuestion * QuestionBDD::CreerArbre()
{
    QFile fichier(QDir::currentPath() + "/donnes_insectes.xml");
    //QFile fichier(QDir::currentPath() + "/test.xml");

    currentNode.setContent(&fichier);

    Categorie * cat = new Categorie(0);

    listeQuestionWithCategorie(cat, true);

    return cat->getListeQuestion();
}

void QuestionBDD::listeQuestionWithCategorie(Categorie * cat, bool recursif = true)   {

    // récupération de la liste de toutes les questions
    ReponseBDD * repBDD = new ReponseBDD();

    QDomElement root = currentNode.documentElement();
    qDebug() << root.toElement().tagName(); // ==> renvoi "arbre" soit la racine de l'arbre XML

    QDomNode child = root.firstChild();
    qDebug() << child.toElement().tagName(); // ==> renvoi "branche" soit le 1er fils de "arbre"

    QDomNode question = child.firstChild(); // ==> renvoi "question"
    qDebug() << question.toElement().tagName();

    QDomNode reponse = question.firstChild(); // ==> renvoi "reponse"

    while(!reponse.isNull()) {
        QDomElement e = reponse.toElement();
        if(!e.isNull()) {
            qDebug() << e.tagName();
        }
        reponse = reponse.nextSibling();
    }

    question = question.nextSibling();
    qDebug() << question.toElement().tagName();
    reponse = question.firstChild();

    while(!reponse.isNull()) {
        QDomElement e = reponse.toElement();
        if(!e.isNull()) {
            qDebug() << e.tagName();
        }
        reponse = reponse.nextSibling();
    }


    QDomNodeList lstBaliseQuestion = currentNode.toElement().elementsByTagName("arbre");
    qDebug() << lstBaliseQuestion.size();

    int i;
    Question * temp;
    for(i=0; i<lstBaliseQuestion.size(); i++)  {
        //découpage du q devant l'id
        temp = new Question(lstBaliseQuestion.at(i).toElement().attribute("id").left(1).toInt());
        temp->setQuestion(lstBaliseQuestion.at(i).toElement().attribute("texte"));

        if(i > 0)   {
             cat->getListeQuestion()->at(i-1)->setIdRight(temp->getIdentifiant());
            temp->setIdLeft( cat->getListeQuestion()->at(i-1)->getIdentifiant());
        }
        currentNode = lstBaliseQuestion.at(i).toDocument();
        if(recursif)
            repBDD->listeReponseFromQuestion(temp, recursif);
        cat->ajouterQuestion(temp);
    }
}

ListeQuestion * QuestionBDD::parseXML()
{
    QDomDocument document;
    //ListeQuestion* listeQuestion = new ListeQuestion();

   /* QFile fichier(QDir::currentPath() + "/donnes_insectes.xml");
    document.setContent(fichier.readAll());

    QDomElement rootArbre = document.documentElement(); //renvoie la balise racine arbre
    QDomNode branche = rootArbre.firstChild(); //renvoie la balise branche

    //Récuppèration de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = branche.toDocument().elementsByTagName("question");
    int i;
    Question * temp;
    for(i=0; i<lstBaliseQuestion.size(); i++)  {
        //découpage du q devant l'id
        qDebug() << lstBaliseQuestion.at(i).toElement().attribute("id").left(1);
        temp = new Question(lstBaliseQuestion.at(i).toElement().attribute("id").left(1).toInt());
        temp->setQuestion(lstBaliseQuestion.at(i).toElement().attribute("text"));
        listeQuestion->append(temp);
        if(i > 0)   {
            listeQuestion->at(i-1)->setIdRight(temp->getIdentifiant());
            temp->setIdLeft(listeQuestion->at(i-1)->getIdentifiant());
        }
    }*/

    return NULL;
}
