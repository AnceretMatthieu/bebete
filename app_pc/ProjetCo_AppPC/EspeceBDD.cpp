#include "EspeceBDD.h"

void EspeceBDD::enregistrerEspece(Espece * esp) {
    QDomNode * memoire = currentNodeWrite;
    QDomElement domesp = doc.createElement("resultat");
    domesp.setAttribute("id", "res"+QString::number(esp->getIdentifiant()));
    currentNodeWrite->appendChild(domesp);

    QDomElement nom = doc.createElement("nom");
    QDomText txtnom = doc.createTextNode(esp->getNom());
    nom.appendChild(txtnom);
    domesp.appendChild(nom);

    QDomElement type = doc.createElement("type");
    QDomText txttype = doc.createTextNode(esp->getType());
    type.appendChild(txttype);
    domesp.appendChild(type);

    QDomElement regimeAlimentaire = doc.createElement("regimeAlimentaire");
    QDomText txtregime = doc.createTextNode(esp->getRegimeAlimentaire());
    regimeAlimentaire.appendChild(txtregime);
    domesp.appendChild(regimeAlimentaire);

    QDomElement informations = doc.createElement("informations");
    QDomText txtinfo = doc.createTextNode(esp->getInformation());
    informations.appendChild(txtinfo);
    domesp.appendChild(informations);

    ListeMedia * lm = esp->getListeMedia();
    if(lm->size() > 0)  {
        QDomElement dommed = doc.createElement("media");
        domesp.appendChild(dommed);
        currentNodeWrite = &dommed;
        qDebug() << currentNodeWrite->nodeName();
    }

    for(int i = 0; i < lm->size(); i++)   {
        MediaBDD::enregistrerMedia(lm->at(i));
    }
    currentNodeWrite = memoire;
}
