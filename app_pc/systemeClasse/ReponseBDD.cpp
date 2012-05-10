#include "ReponseBDD.h"
<<<<<<< HEAD
=======
#include "Reponse.h"
#include "ListeReponse.h"
#include "Question.h"

ReponseBDD::ReponseBDD() {

}
>>>>>>> 7f1b825f78b331c8508bf15f853ef6dee707e278

void ReponseBDD::listeReponseFromQuestion(Question * quest, bool recursif = true)   {

    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = currentNode.elementsByTagName("reponse");
    int i;
    Reponse * temp;
    for(i=0; i<lstBaliseQuestion.size(); i++) {
        //dÃ©coupage du r devant l'id
        temp = new Reponse(lstBaliseQuestion.at(i).toElement().attribute("id").left(1).toInt());
        temp->setReponse(lstBaliseQuestion.at(i).toElement().attribute("texte"));
        if(i > 0)   {
            quest->getListeReponse()->at(i-1)->setIdRight(temp->getIdentifiant());
            temp->setIdLeft(quest->getListeReponse()->at(i-1)->getIdentifiant());
        }
        quest->ajouterReponse(temp);
        if(recursif) {

        }
    }
}
