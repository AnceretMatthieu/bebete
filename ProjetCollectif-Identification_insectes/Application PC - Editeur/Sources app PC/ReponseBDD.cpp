#include "ReponseBDD.h"
#include "Categorie.h"
#include "Reponse.h"
#include "ListeReponse.h"
#include "Question.h"
#include "Espece.h"
#include "BDD.h"
#include "EspeceBDD.h"
#include "MediaBDD.h"
#include "CategorieBDD.h"
#include "EspeceBDD.h"

void ReponseBDD::listeFromReponse(Reponse * rep, bool recursif) {
    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes();

    Media * tempm;
    Categorie * tempc;
    Espece * tempe;
    for(int i = 0; i < lstBaliseQuestion.size(); i++) {
        QDomNode tempNode = lstBaliseQuestion.at(i);
        if(tempNode.nodeName() == "branche")
        {
            tempc = new Categorie(tempNode.toElement().attribute("id").toInt());
            tempc->setLabel(tempNode.toElement().attribute("type", QString("")));
            if(BDD::lastId > tempNode.toElement().attribute("id").toInt())
                BDD::lastId = tempNode.toElement().attribute("id").toInt();
            rep->setSuiv(tempc);
            rep->setTypeSuiv(TYPE_CATEGORIE);

            rep->setPrec(rep);

            BDD::currentNode = lstBaliseQuestion.at(i).toElement();
            if(recursif)
                CategorieBDD::listeQuestionWithCategorie(tempc, recursif);

        }
        else if(tempNode.nodeName() == "media")
        {
            QDomNodeList lstMedia = tempNode.childNodes();
            for(int j = 0; j < lstMedia.size(); j++) {
                tempm = new Media(lstMedia.at(j).toElement().attribute("id").toInt());
                if(BDD::lastId > lstMedia.at(j).toElement().attribute("id").toInt())
                    BDD::lastId = lstMedia.at(j).toElement().attribute("id").toInt();

                if(lstMedia.at(j).nodeName() == "video")    {
                    tempm->setType(MEDIA_TYPE_VIDEO);
                    tempm->setPath(lstMedia.at(j).toElement().attribute("src", QString("")));
                }
                else if(lstMedia.at(j).nodeName() == "img")    {
                     tempm->setType(MEDIA_TYPE_IMAGE);
                     tempm->setPath(lstMedia.at(j).toElement().attribute("src", QString("")));
                }
                else if(lstMedia.at(j).nodeName() == "legende")    {
                     tempm->setType(MEDIA_TYPE_TEXT);
                     tempm->setPath(lstMedia.at(j).toElement().text());
                }
                rep->ajouterMedia(tempm);
             }
        }
        else if(tempNode.nodeName() == "resultat")
        {
            tempe = new Espece(tempNode.toElement().attribute("id").toInt());
            if(BDD::lastId > tempNode.toElement().attribute("id").toInt())
                BDD::lastId = tempNode.toElement().attribute("id").toInt();
            QDomNodeList toto = tempNode.childNodes();
            for(int p = 0; p < toto.size(); p++ ) {
                if(toto.at(p).nodeName() == "nom") {
                    QString str = toto.at(p).toElement().text();
                    if(str.size() == 0) // ce test permet d'éviter les problèmes dans le cas où la balise est vide
                        tempe->setNom(QString(""));
                    else
                        tempe->setNom(str);
                }
                else if(toto.at(p).nodeName() == "type") {
                    QString str = toto.at(p).toElement().text();
                    if(str.size() == 0)
                        tempe->setType(QString(""));
                    else
                        tempe->setType(str);
                }
                else if (toto.at(p).nodeName() == "regimeAlimentaire") {
                    QString str = toto.at(p).toElement().text();
                    if(str.size() == 0)
                        tempe->setRegimeAlimentaire(QString(""));
                    else
                        tempe->setRegimeAlimentaire(str);
                }
                else if (toto.at(p).nodeName() == "informations") {
                    QString str = toto.at(p).toElement().text();
                    if(str.size() == 0)
                        tempe->setInformation(QString(""));
                    else
                        tempe->setInformation(str);
                }
                else if (toto.at(p).nodeName() == "media") {
                    QDomNodeList lstMedia =  toto.at(p).childNodes();
                    for(int j = 0; j < lstMedia.size(); j++)
                    {
                        tempm = new Media(lstMedia.at(j).toElement().attribute("id").toInt());
                        if(BDD::lastId > lstMedia.at(j).toElement().attribute("id").toInt())
                            BDD::lastId = lstMedia.at(j).toElement().attribute("id").toInt();
                        if(lstMedia.at(j).nodeName() == "video") {
                            tempm->setType(MEDIA_TYPE_VIDEO);
                            tempm->setPath(lstMedia.at(j).toElement().attribute("src", QString("")));
                        }
                        else if(lstMedia.at(j).nodeName() == "img") {
                             tempm->setType(MEDIA_TYPE_IMAGE);
                             tempm->setPath(lstMedia.at(j).toElement().attribute("src", QString("")));
                        }
                        else if(lstMedia.at(j).nodeName() == "legende") {
                             tempm->setType(MEDIA_TYPE_TEXT);
                             tempm->setPath(lstMedia.at(j).toElement().text());
                        }
                        tempe->ajouterMedia(tempm);
                    }
                }
            }
            rep->setSuiv(tempe);
            rep->setTypeSuiv(TYPE_ESPECE);
        }
    }
}

void ReponseBDD::enregistrerReponse(Reponse * rep)  {
    QDomNode * memoire = currentNodeWrite;
    QDomElement reponse = doc.createElement("reponse");
    reponse.setAttribute("id", QString::number(rep->getIdentifiant()));
    reponse.setAttribute("texte", rep->getReponse());

    currentNodeWrite->appendChild(reponse);
    currentNodeWrite = &reponse;
    ListeMedia * lm = rep->getListeIllustration();
    if(lm->size() > 0)  {
        QDomElement dommed = doc.createElement("media");
        currentNodeWrite->appendChild(dommed);
        currentNodeWrite = &dommed;

    }
    for(int i = 0; i < lm->size(); i++)   {
        MediaBDD::enregistrerMedia(lm->at(i));
    }
    currentNodeWrite = &reponse;
    if(rep->getTypeSuiv() == TYPE_CATEGORIE)    {
        CategorieBDD::enregistrerCategorie((Categorie*)rep->getSuiv());
    }
    else if(rep->getTypeSuiv() == TYPE_ESPECE)    {
        EspeceBDD::enregistrerEspece((Espece*)rep->getSuiv());
    }
    else    {

    }

    currentNodeWrite = memoire;
}
