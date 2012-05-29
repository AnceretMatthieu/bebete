#include "ReponseBDD.h"
#include "Categorie.h"
#include "Reponse.h"
#include "ListeReponse.h"
#include "Question.h"
#include "Espece.h"
#include "BDD.h"
#include "EspeceBDD.h"
#include "categoriebdd.h"
#include "MediaBDD.h"
#include "CategorieBDD.h"
#include "EspeceBDD.h"

void ReponseBDD::listeFromReponse(Reponse * rep, bool recursif) {
    //qDebug() << "listeFromReponse(" << rep->getIdentifiant() << ", " << recursif << ")";
    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes();
    //qDebug() << "Nombre de fils : " << lstBaliseQuestion.size();

    Media * tempm;
    Categorie * tempc;
    Espece * tempe;
    int i;
    for(i=0; i<lstBaliseQuestion.size(); i++) {
        QDomNode tempNode = lstBaliseQuestion.at(i);
        if(tempNode.nodeName() == "branche")
        {
            tempc = new Categorie(tempNode.toElement().attribute("id").left(1).toInt());
            tempc->setLabel(tempNode.toElement().attribute("type"));
            //qDebug() << "Categorie" << tempc->getLabel();
            rep->setSuiv(tempc);
            rep->setTypeSuiv(TYPE_CATEGORIE);

            BDD::currentNode = lstBaliseQuestion.at(i).toElement();
            if(recursif)
                CategorieBDD::listeQuestionWithCategorie(tempc, recursif);

        }
        else if(tempNode.nodeName() == "media")
        {
            QDomNodeList lstMedia = tempNode.childNodes();
            //qDebug() << "MediaReponse" << i << ": nombre de noeud" << lstMedia.size();
            int j;
            for(j=0; j<lstMedia.size(); j++)
            {
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
                //qDebug() << "Media<" << tempm->getType() << "> :" << tempm->getPath();
                rep->ajouterMedia(tempm);
             }
        }
        else if(tempNode.nodeName() == "resultat")
        {
            tempe = new Espece(tempNode.toElement().attribute("id").left(3).toInt());

            QDomNodeList toto = tempNode.childNodes();
            for(int p = 0; p < toto.size(); p++ )   {
                if(toto.at(p).nodeName() == "nom")
                    tempe->setNom(toto.at(p).toElement().text());
                else if(toto.at(p).nodeName() == "type")
                    tempe->setType(toto.at(p).toElement().text());
                else if (toto.at(p).nodeName() == "regimeAlimentaire")
                    tempe->setRegimeAlimentaire(toto.at(p).toElement().text());
                else if (toto.at(p).nodeName() == "informations")
                    tempe->setInformation(toto.at(p).toElement().text());
                else if (toto.at(p).nodeName() == "media"){

                QDomNodeList lstMedia =  toto.at(p).childNodes();
                //qDebug() << "MediaReponse" << i << ": nombre de noeud" << lstMedia.size();
                int j;
                for(j=0; j<lstMedia.size(); j++)
                {
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
                    //qDebug() << "Media<" << tempm->getType() << "> :" << tempm->getPath();
                    tempe->ajouterMedia(tempm);
                 }
                }
            }
            //qDebug() << "nom" << tempe->getNom();
            //qDebug() << "type" << tempe->getType();
            //qDebug() << "regime alimentaire" << tempe->getRegimeAlimentaire();
            //qDebug() << "informations" << tempe->getInformation();

            rep->setSuiv(tempe);
            rep->setTypeSuiv(TYPE_ESPECE);
        }
    }
}

void ReponseBDD::enregistrerReponse(Reponse * rep)  {
    QDomNode memoire = currentNode;
    QDomElement reponse = doc.createElement("reponse");
    reponse.setAttribute("id", "r"+QString::number(rep->getIdentifiant()));
    reponse.setAttribute("texte", rep->getReponse());
    currentNode.appendChild(reponse);
    currentNode = reponse;
    ListeMedia * lm = rep->getListeIllustration();
    if(lm->size() > 0)  {
        QDomElement dommed = doc.createElement("media");
        currentNode.appendChild(dommed);
        currentNode = dommed;

    }
    for(int i = 0; i < lm->size(); i++)   {
        MediaBDD::enregistrerMedia(lm->at(i));
    }
    currentNode = reponse;
    if(rep->getTypeSuiv() == TYPE_CATEGORIE)    {
        CategorieBDD::enregistrerCategorie((Categorie*)rep->getSuiv());
    }
    else if(rep->getTypeSuiv() == TYPE_ESPECE)    {
        EspeceBDD::enregistrerEspece((Espece*)rep->getSuiv());
    }
    else    {
        //grosse erreur de malade
    }

    currentNode = memoire;
}
