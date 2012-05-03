#include "QuestionBDD.h"
#include "ListeQuestion.h"
#include "Question.h"
#include <QDebug>
#include <QDir>

ListeQuestion * QuestionBDD::CreerArbre()
{
    ListeQuestion* listeQuestion;
    return listeQuestion;
}

ListeQuestion * QuestionBDD::parseXML()
{
    QDomDocument document;
    ListeQuestion* listeQuestion;

    QFile fichier(QDir::currentPath() + "donnes_insectes.xml");
    qDebug() << QDir::currentPath();
    document.setContent(fichier.readAll());

    QDomNode arbre = document.elementsByTagName("arbre").at(0);
    QDomNode branche = arbre.toDocument().elementsByTagName("branche").at(0);
    qDebug() << arbre.toDocument().elementsByTagName("branche").size();

    //QDomNodeList question = branche.toDocument().elementsByTagName("question");

    //for (int i=0)

/*
    for (int i = 0; i<listeDeQuestion.size();i++)
    {
        QDomElement libelle = listeDeQuestion.at(i).firstChildElement("texte");
      //QDomElement media = listeDeQuestion.at(i).firstChildElement("media");

        //trouveru n moyen pour repartir que depuis la question et pas depuis le début du fichier
        QDomNodeList listeDeReponse = document.elementsByTagName("reponse");
        for (int j = 0; i<listeDeReponse.size();j++)
        {
            QDomElement texte = listeDeReponse.at(i).firstChildElement("texte");

            //Question* uneQuestion = new Question(libelle.text(),);
            listeQuestion.append(uneQuestion);


     */

    return listeQuestion;

    /*{
        unsigned int i = 0;
        QString strIdPlacemark;
        QString strCategorie;
        QString strName;
        QString strCoord;
        QString strLong;
        QString strLat;

        QDomNodeList tab;
        QDomNodeList tabPoint;
        QDomElement placemark;
        QDomElement point;
        QDomNode n;
        QDomElement racine = doc.documentElement(); // renvoie la balise racine ==> kml
        QDomNode noeud = racine.firstChild(); // renvoie la balise "Document"
        noeud = noeud.firstChild(); // renvoie la balise "Placemark"

        QVector<POI> listePois;

        Lecture du fichier XML
        while(!noeud.isNull())
        {
            placemark = noeud.toElement(); // conversion du noeud en élément pour utiliser les méthodes tagName() et attribute()

            if (placemark.tagName() == "Placemark") // on vérifie la présence de la balise "Placemark"
            {
                strIdPlacemark = placemark.attribute("id");
                tab = placemark.childNodes(); // crée un tableau des enfants de "Placemark"

                for(i = 0; i < tab.length(); i++)
                {
                    // pour chaque enfant, on extrait la donnée et on concatène
                    n = tab.item(i);

                    // on gère le cas de l'élément "Point"
                    point = n.toElement();

                    if(point.tagName() == "Point") {
                        tabPoint = point.childNodes();
                        n = tabPoint.item(0); // renvoie la balise "coordinates"
                        strCoord = n.firstChild().toText().data(); // contenu de la balise "coordinates"

                        QStringList latAndLong = strCoord.split(","); // on sépare la longitude et la latitude
                        strLong = latAndLong.at(0);
                        strLat = latAndLong.at(1);
                    }
                    else {
                        if(n.toElement().tagName() == "categorie") {
                            strCategorie = n.firstChild().toText().data();
                        }
                        else if(n.toElement().tagName() == "nom") {
                            strName = n.firstChild().toText().data();
                        }
                        else {
                            // autre balise...
                        }
                    }
                }

                // une fois que l'on a tous nos renseignements, on crée un objet "POI"
                POI * unPoi = new POI(strIdPlacemark, strCategorie, strName, "", "", strLong.toFloat(), strLat.toFloat());
                // on ajoute cet objet POI dans le vecteur
                listePois.append(*unPoi);
            }
            noeud = noeud.nextSibling(); // on passe au "Placemark" suivante
        }

        std::cout << "Traitement du fichier XML terminé !" << std::endl;

        return listePois;
    }*/
}
