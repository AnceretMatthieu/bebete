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
                tempm = new Media(0); // TODO : il faut récupérer l'ID présent dans le fichier XML ; il faudra probablement changer le type "int" par "QString"
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
            /*
                <nom>nom</nom>
                <type>MEL1</type>
                <regimeAlimentaire>Prédateur</regimeAlimentaire>
                <informations>infos</informations>
            */
            QDomNodeList toto = tempNode.childNodes();
            for(int p = 0; p < toto.size(); p++ )
            {
                if(toto.at(p).nodeName() == "nom")
                    tempe->setNom(toto.at(p).toElement().text());
                else if(toto.at(p).nodeName() == "type")
                    tempe->setType(toto.at(p).toElement().text());
                else if (toto.at(p).nodeName() == "regimeAlimentaire")
                    tempe->setRegimeAlimentaire(toto.at(p).toElement().text());
                else if (toto.at(p).nodeName() == "informations")
                    tempe->setInformation(toto.at(p).toElement().text());
            }

            rep->setTypeSuiv(TYPE_ESPECE);
            rep->setSuiv(tempe);
        }
    }
}
