#include "ReponseBDD.h"

#include "Reponse.h"
#include "ListeReponse.h"
#include "Question.h"
#include "BDD.h"

ReponseBDD::ReponseBDD() {

}


void ReponseBDD::listeReponseFromQuestion(Question * quest, bool recursif = true)   {
    qDebug() << "listeReponseFromQuestion(" << quest->getIdentifiant() << ", " << recursif << ")";
    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes();
    qDebug() << "Nombre de fils : " << lstBaliseQuestion.size();

    int i;
    Reponse * tempr;
    Media * tempm;
    for(i=0; i<lstBaliseQuestion.size(); i++) {
        QDomNode tempNode = lstBaliseQuestion.at(i);
        if(tempNode.nodeName() == "reponse")    {
            qDebug() << "Reponse " << i;
            tempr = new Reponse(tempNode.toElement().attribute("id").left(1).toInt());
            tempr->setReponse(tempNode.toElement().attribute("texte"));
            quest->ajouterReponse(tempr);

            if(quest->getListeReponse()->size() > 1)   {
                quest->getListeReponse()->at(quest->getListeReponse()->size()-2)->setIdRight(tempr->getIdentifiant());
                tempr->setIdLeft(quest->getListeReponse()->at(quest->getListeReponse()->size()-2)->getIdentifiant());
            }

            if(recursif) {

            }
        }else if(tempNode.nodeName() == "media")  {
            tempm = new Media(tempNode.toElement().attribute("id").left(1).toInt());
            quest->ajouterMedia(tempm);
        }
    }
}
