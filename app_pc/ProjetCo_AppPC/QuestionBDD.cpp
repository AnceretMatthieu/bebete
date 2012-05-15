#include "QuestionBDD.h"

void QuestionBDD::listeReponseFromQuestion(Question * quest, bool recursif = true)   {
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

            BDD::currentNode = lstBaliseQuestion.at(i).toElement();
            if(recursif) {
                ReponseBDD::listeFromReponse(tempr, recursif);
            }
        }else if(tempNode.nodeName() == "media")  {
            QDomNodeList lstMedia = tempNode.childNodes();
            qDebug() << "Media" << i << ": nombre de noeud" << lstMedia.size();
            int j;
            for(j=0; j<lstMedia.size(); j++) {
                tempm = new Media(0);
                if(lstMedia.at(j).nodeName() == "video")    {
                    tempm->setType(MEDIA_TYPE_VIDEO);
                    tempm->setPath(lstMedia.at(j).toElement().attribute("src"));
                }else if(lstMedia.at(j).nodeName() == "img")    {
                    tempm->setType(MEDIA_TYPE_IMAGE);
                    tempm->setPath(lstMedia.at(j).toElement().attribute("src"));
                }else if(lstMedia.at(j).nodeName() == "legende")    {
                    tempm->setType(MEDIA_TYPE_TEXT);
                    tempm->setPath(lstMedia.at(j).toElement().text());
                }
                qDebug() << "Media<" << tempm->getType() << "> :" << tempm->getPath();
                quest->ajouterMedia(tempm);
            }
        }
    }
}

