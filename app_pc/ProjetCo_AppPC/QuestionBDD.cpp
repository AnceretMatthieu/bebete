#include "QuestionBDD.h"

void QuestionBDD::listeReponseFromQuestion(Question * quest, bool recursif = true)
{
    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes();

    int i;
    Reponse * tempr;
    Media * tempm;

    for(i=0; i<lstBaliseQuestion.size(); i++) {
        QDomNode tempNode = lstBaliseQuestion.at(i);
        if(tempNode.nodeName() == "reponse")
        {
            tempr = new Reponse(tempNode.toElement().attribute("id").left(1).toInt());
            tempr->setReponse(tempNode.toElement().attribute("texte"));
            quest->ajouterReponse(tempr);

            if(quest->getListeReponse()->size() > 1)
            {
                quest->getListeReponse()->at(quest->getListeReponse()->size()-2)->setIdRight(tempr->getIdentifiant());
                tempr->setIdLeft(quest->getListeReponse()->at(quest->getListeReponse()->size()-2)->getIdentifiant());
            }

            BDD::currentNode = lstBaliseQuestion.at(i).toElement();
            if(recursif) {
                ReponseBDD::listeFromReponse(tempr, recursif);
            }
        }
        else if(tempNode.nodeName() == "media")
        {
            QDomNodeList lstMedia = tempNode.childNodes();
            int j;

            for(j=0; j<lstMedia.size(); j++)
            {
                tempm = new Media(0); // TODO : attention à bien prendre en compte l'ID présent dans le fichier XML
                if(lstMedia.at(j).nodeName() == "video") {
                    tempm->setType(MEDIA_TYPE_VIDEO);
                    tempm->setPath(lstMedia.at(j).toElement().attribute("src"));
                }
                else if(lstMedia.at(j).nodeName() == "audio") {
                    tempm->setType(MEDIA_TYPE_AUDIO);
                    tempm->setPath((lstMedia.at(j).toElement().attribute("src")));
                }
                else if(lstMedia.at(j).nodeName() == "img") {
                    tempm->setType(MEDIA_TYPE_IMAGE);
                    tempm->setPath(lstMedia.at(j).toElement().attribute("src"));
                }
                else if(lstMedia.at(j).nodeName() == "legende") {
                    tempm->setType(MEDIA_TYPE_TEXT);
                    tempm->setPath(lstMedia.at(j).toElement().text());
                }
                quest->ajouterMedia(tempm);
            }
        }
    }
}
