#include "ReponseBDD.h"

#include "Reponse.h"
#include "ListeReponse.h"
#include "Question.h"
#include "BDD.h"

void ReponseBDD::listeFromReponse(Reponse * rep, bool recursif) {
    qDebug() << "listeFromReponse(" << rep->getIdentifiant() << ", " << recursif << ")";
    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes();
    qDebug() << "Nombre de fils : " << lstBaliseQuestion.size();

    int i;
    for(i=0; i<lstBaliseQuestion.size(); i++) {
        QDomNode tempNode = lstBaliseQuestion.at(i);
        if(tempNode.nodeName() == "branche")    {

        }else if(tempNode.nodeName() == "media")  {

        }
    }
}
