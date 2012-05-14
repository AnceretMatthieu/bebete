#include "QuestionBDD.h"

QuestionBDD::QuestionBDD() {

}

ListeQuestion * QuestionBDD::CreerArbre()
{
    //QFile fichier(QDir::currentPath() + "/donnes_insectes.xml");
    //QFile fichier(QDir::currentPath() + "/test.xml");
    QFile fichier(QDir::currentPath() + "/accueil.xml");
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

void QuestionBDD::listeQuestionWithCategorie(Categorie * cat, bool recursif = true)   {

    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes(); // ==> renvoi "question"
    qDebug() << "In listeQuestionWithCategorie(" << cat->getIdentifiant() << ", " << recursif << ")";
    qDebug() << "nombre de question " << lstBaliseQuestion.size();

    int i;
    Question * temp;
    for(i=0; i<lstBaliseQuestion.size(); i++)  {
        qDebug() << "Question " << i;
        //découpage du q devant l'id
        temp = new Question(lstBaliseQuestion.at(i).toElement().attribute("id").left(1).toInt());
        temp->setQuestion(lstBaliseQuestion.at(i).toElement().attribute("texte"));

        qDebug() << "Question " << temp->getIdentifiant() << " : " << temp->getQuestion();

        if(i > 0)   {
             cat->getListeQuestion()->at(i-1)->setIdRight(temp->getIdentifiant());
            temp->setIdLeft( cat->getListeQuestion()->at(i-1)->getIdentifiant());
        }
        BDD::currentNode = lstBaliseQuestion.at(i).toElement();
        if(recursif)
            ReponseBDD::listeReponseFromQuestion(temp, recursif);
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
