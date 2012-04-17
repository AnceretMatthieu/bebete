#include "QuestionBDD.h"
#include "ListeQuestion.h"
#include "Question.h"

ListeQuestion *QuestionBDD::CreerArbre()
{

}

ListeQuestion *QuestionBDD::parseXML(QByteArray oneQByteArray)
{
    QDomDocument document;

    QFile fichier("C:/Users/Marty/Desktop/Nouveau/Doc/S8/Projet Insecte/Git/XML/structure_xml");
    document.setContent(fichier.readAll());

    QDomNodeList listeDeQuestion = document.elementsByTagName("arbre");


    for (int i = 0; i<listeDeQuestion.size();i++)
    {
       /* QDomElement libelle = listeDeQuestion.at(i).firstChildElement("texte");
      //QDomElement media = listeDeQuestion.at(i).firstChildElement("media");

        //trouveru n moyen pour repartir que depuis la question et pas depuis le début du fichier
        QDomNodeList listeDeReponse = document.elementsByTagName("reponse");
        for (int j = 0; i<listeDeReponse.size();j++)
        {
            QDomElement texte = listeDeReponse.at(i).firstChildElement("texte");

            Question* uneQuestion = new Question(libelle.text(),);
            listeQuestion.append(uneQuestion);
            */

      }

       return listeQuestion;

}
