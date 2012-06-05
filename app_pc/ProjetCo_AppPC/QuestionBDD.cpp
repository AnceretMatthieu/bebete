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
            tempr = new Reponse(tempNode.toElement().attribute("id", QString("r0")).left(1).toInt());
            QString s = tempNode.toElement().attribute("texte", QString(""));
            if(s.size() != 0)
                tempr->setReponse(s);
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
                    QString s1 = lstMedia.at(j).toElement().attribute("src", QString(""));
                    if(s1.size() != 0)
                        tempm->setPath(s1);
                }
                else if(lstMedia.at(j).nodeName() == "audio") {
                    tempm->setType(MEDIA_TYPE_AUDIO);
                    QString s2 = lstMedia.at(j).toElement().attribute("src", QString(""));
                    if(s2.size())
                        tempm->setPath(s2);
                }
                else if(lstMedia.at(j).nodeName() == "img") {
                    tempm->setType(MEDIA_TYPE_IMAGE);
                    QString s3 = lstMedia.at(j).toElement().attribute("src", QString(""));
                    if(s3.size() != 0)
                        tempm->setPath(s3);
                }
                else if(lstMedia.at(j).nodeName() == "legende") {
                    tempm->setType(MEDIA_TYPE_TEXT);
                    QString s4 = lstMedia.at(j).toElement().text();
                    if(s4.size() != 0)
                        tempm->setPath(s4);
                }
                quest->ajouterMedia(tempm);
            }
        }
    }
}

void QuestionBDD::enregistrerQuestion(Question * quest) {
    QDomNode * memoire = currentNodeWrite;
    QDomElement question = doc.createElement("question");
    question.setAttribute("id", "q0");
    question.setAttribute("texte", quest->getQuestion());
    question.setAttribute("visible", quest->getVisible());
    qDebug() << "q"+QString::number(quest->getIdentifiant()) +" "+quest->getQuestion() + " " +quest->getVisible();
    currentNodeWrite->appendChild(question);

    currentNodeWrite = &question;

    ListeMedia * lm = quest->getListeMedia();
    if(lm->size() > 0)  {
        QDomElement dommed = doc.createElement("media");
        currentNodeWrite->appendChild(dommed);
        currentNodeWrite = &dommed;

        }
    for(int i = 0; i < lm->size(); i++)   {
        MediaBDD::enregistrerMedia(lm->at(i));
    }
    currentNodeWrite = &question;
    ListeReponse * lr = quest->getListeReponse();
    for(int i = 0; i < lr->size(); i++)   {
        ReponseBDD::enregistrerReponse(lr->at(i));
    }
    currentNodeWrite = memoire;
}
