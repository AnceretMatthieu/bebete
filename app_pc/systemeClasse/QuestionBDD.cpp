#include "QuestionBDD.h"
#include "ListeQuestion.h"
#include "Question.h"

ListeQuestion * QuestionBDD::CreerArbre()
{
<<<<<<< HEAD
    ListeQuestion* listeQuestion;
    return listeQuestion;
=======
    return NULL;
>>>>>>> 44f800937f554b6988c07070239092664a9d7168
}

ListeQuestion * QuestionBDD::parseXML(QByteArray oneQByteArray)
{
    /*QDomDocument document;

    QFile fichier("donnees_insectes.xml");
    document.setContent(fichier.readAll());

    QDomNodeList listeDeQuestion = document.elementsByTagName("arbre");

    ListeQuestion* listeQuestion;


    for (int i = 0; i<listeDeQuestion.size();i++)
    {
        QDomElement libelle = listeDeQuestion.at(i).firstChildElement("texte");
      //QDomElement media = listeDeQuestion.at(i).firstChildElement("media");

        //trouveru n moyen pour repartir que depuis la question et pas depuis le début du fichier
        QDomNodeList listeDeReponse = document.elementsByTagName("reponse");
        for (int j = 0; i<listeDeReponse.size();j++)
        {
            QDomElement texte = listeDeReponse.at(i).firstChildElement("texte");

            Question* uneQuestion = new Question(libelle.text(),);
            listeQuestion.append(uneQuestion);


<<<<<<< HEAD
    return listeQuestion;
=======
<<<<<<< HEAD
      }
       return listeQuestion;*/
=======

>>>>>>> cb7579a9876a2f7ce952f15d30d750270b925fd3
>>>>>>> 44f800937f554b6988c07070239092664a9d7168

}
