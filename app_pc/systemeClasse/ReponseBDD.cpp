#include "ReponseBDD.h"
#include "Reponse.h"
#include "ListeReponse.h"
#include "Question.h"



void ReponseBDD::listeReponseFromQuestion(Question * quest, bool recursif = true)   {

    //Récuppèration de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = currentNode->elementsByTagName("reponse");
    int i;
    Reponse * temp;
    for(i=0; i<lstBaliseQuestion.size(); i++)  {
        //découpage du r devant l'id
        temp = new Reponse(lstBaliseQuestion.at(i).toElement().attribute("id").left(1).toInt());
        temp->setReponse(lstBaliseQuestion.at(i).toElement().attribute("texte"));
        if(i > 0)   {
            quest->getListeReponse()->at(i-1)->setIdRight(temp->getIdentifiant());
            temp->setIdLeft(quest->getListeReponse()->at(i-1)->getIdentifiant());
        }
        quest->ajouterReponse(temp);
        if(recursif)    {

        }
    }
}
