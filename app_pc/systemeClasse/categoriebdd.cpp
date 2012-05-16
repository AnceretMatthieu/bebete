#include "categoriebdd.h"
#include <QIODevice>

ListeQuestion * CategorieBDD::CreerArbre()
{
    //QFile fichier(QDir::currentPath() + "/donnes_insectes.xml");
    //QFile fichier(QDir::currentPath() + "/test.xml");
    QFile fichier(QDir::currentPath() + "/accueil.xml");
    QDomDocument doc;
    doc.setContent(&fichier);
    BDD::currentNode = doc.elementsByTagName("arbre").at(0);
    //qDebug() << currentNode.nodeName();

    //firstchild = branche
    BDD::currentNode = currentNode.firstChild();
    //qDebug() << currentNode.nodeName();

    Categorie * cat = new Categorie(0);

    listeQuestionWithCategorie(cat, true);

    return cat->getListeQuestion();
}

void CategorieBDD::listeQuestionWithCategorie(Categorie * cat, bool recursif = true)   {

    // récupération de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes(); // ==> renvoi "question"
    //qDebug() << "In listeQuestionWithCategorie(" << cat->getIdentifiant() << ", " << recursif << ")";
    //qDebug() << "nombre de question " << lstBaliseQuestion.size();

    int i;
    Question * temp;
    for(i=0; i<lstBaliseQuestion.size(); i++)  {
        //qDebug() << "Question " << i;
        //découpage du q devant l'id
        temp = new Question(lstBaliseQuestion.at(i).toElement().attribute("id").left(1).toInt());
        temp->setQuestion(lstBaliseQuestion.at(i).toElement().attribute("texte"));
        temp->setVisible(lstBaliseQuestion.at(i).toElement().attribute("visible"));
        //qDebug() << "Visible" << temp->getVisible();
        //qDebug() << "Question " << temp->getIdentifiant() << " : " << temp->getQuestion();

        if(i > 0)   {
             cat->getListeQuestion()->at(i-1)->setIdRight(temp->getIdentifiant());
            temp->setIdLeft( cat->getListeQuestion()->at(i-1)->getIdentifiant());
        }
        BDD::currentNode = lstBaliseQuestion.at(i).toElement();
        if(recursif)
            QuestionBDD::listeReponseFromQuestion(temp, recursif);
        cat->ajouterQuestion(temp);
    }
}

void CategorieBDD::enregistrerArbre(Categorie *racine)
{
     QDomElement arbre = BDD::doc.createElement("arbre");
    doc.appendChild(arbre);

    QDomNode noeud = doc.createProcessingInstruction("xml","version=\"1.0\"");

    doc.insertBefore(noeud,doc.firstChild());

    QDomElement root = doc.createElement("branche");
    root.setAttribute("id", "b"+racine->getIdentifiant());
    root.setAttribute("type", racine->getLabel());
    arbre.appendChild(root);

    ListeQuestion * lq = racine->getListeQuestion();

    //martinestbeau()
    for(int i = 0; i < lq->size(); i++)
    {
        QDomElement quest = doc.createElement("question");
        quest.setAttribute("", "");
        root.appendChild(quest);
        lq->at(i)->getListeReponse();
        //martinesttresbeau()
    }


    QFile file("enregistrement.xml");
    if ( !file.open(QIODevice::WriteOnly) )
    {
        qDebug("Impossible de créer le fichier xml pour sauvegarder les données");
        return;
    }
    else
    {
        QTextStream textStream(&file);
        qDebug() <<"\n Enregistrement dans le fichier";
        textStream <<  doc.toString();

    }

   file.close();
}


//initialisation (doc type et arbre) => 1ere fonction
    //création des noeuds branche (fonction indépendante qui prend en param catégorie)  ==> 2eme fonction
    // cherche liste question (Listequestion de cette catégorie)        ==> 2eme fonction
        //créer balise pour chaque question (dans une autre fonction qui prend en param la liste de question)==> 3eme fonction
        //cherche liste des réponse ==> 3eme fonction
            //(dans une autre fct) traité les réponses  ==> 4eme fonction
            //créer les balises espece, et si nouvelle branche on rapelle ligne 101 ==> 4eme fonction
