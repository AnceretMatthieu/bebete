#include "ReponseBDD.h"
#include "Categorie.h"
#include "Reponse.h"
#include "ListeReponse.h"
#include "Question.h"
#include "Espece.h"
#include "BDD.h"
#include "categoriebdd.h"

void ReponseBDD::listeFromReponse(Reponse * rep, bool recursif)
{
    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes();

    Media * tempm;
    Categorie * tempc;
    Espece * tempe;

    for(int i = 0; i < lstBaliseQuestion.size(); i++)
    {
        QDomNode tempNode = lstBaliseQuestion.at(i);
        if(tempNode.nodeName() == "branche")
        {
            tempc = new Categorie(tempNode.toElement().attribute("id").left(1).toInt());
            tempc->setLabel(tempNode.toElement().attribute("type"));

            rep->setTypeSuiv(TYPE_CATEGORIE);
            rep->setSuiv(tempc);

            BDD::currentNode = lstBaliseQuestion.at(i).toElement();
            if(recursif)
            {
                CategorieBDD::listeQuestionWithCategorie(tempc, recursif);
            }
        }
        else if(tempNode.nodeName() == "media")
        {
            QDomNodeList lstMedia = tempNode.childNodes();

            for(int j = 0; j < lstMedia.size(); j++)
            {
                tempm = new Media(0);
                if(lstMedia.at(j).nodeName() == "video") {
                    tempm->setType(MEDIA_TYPE_VIDEO);
                    tempm->setPath(lstMedia.at(j).toElement().attribute("src"));
                }
                else if(lstMedia.at(j).nodeName() == "audio") {
                     tempm->setType(MEDIA_TYPE_AUDIO);
                     tempm->setPath(lstMedia.at(j).toElement().attribute("src"));
                }
                else if(lstMedia.at(j).nodeName() == "img") {
                     tempm->setType(MEDIA_TYPE_IMAGE);
                     tempm->setPath(lstMedia.at(j).toElement().attribute("src"));
                }
                else if(lstMedia.at(j).nodeName() == "legende") {
                     tempm->setType(MEDIA_TYPE_TEXT);
                     tempm->setPath(lstMedia.at(j).toElement().text());
                }
                rep->ajouterMedia(tempm);
             }
        }
        else if(tempNode.nodeName() == "resultat")
        {
            tempe = new Espece(tempNode.toElement().attribute("id").left(3).toInt());

            QDomNodeList lstResultat = tempNode.childNodes();
            for(int p = 0; p < lstResultat.size(); p++ )
            {
                if(lstResultat.at(p).nodeName() == "nom")
                    tempe->setNom(lstResultat.at(p).toElement().text());
                else if(lstResultat.at(p).nodeName() == "type")
                    tempe->setType(lstResultat.at(p).toElement().text());
                else if (lstResultat.at(p).nodeName() == "regimeAlimentaire")
                    tempe->setRegimeAlimentaire(lstResultat.at(p).toElement().text());
                else if (lstResultat.at(p).nodeName() == "informations")
                    tempe->setInformation(lstResultat.at(p).toElement().text());
            }

            rep->setTypeSuiv(TYPE_ESPECE);
            rep->setSuiv(tempe);
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
        QMessageBox::warning(0, "Erreur", "Erreur dans la fonction ReponseBDD:enregistrerReponse");
    }

    currentNode = memoire;
}

