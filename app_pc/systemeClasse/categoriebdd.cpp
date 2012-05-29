#include "categoriebdd.h"
#include <QIODevice>

ListeQuestion * CategorieBDD::CreerArbre()
{
#ifdef Q_OS_MACX
    QDir dir(QDir::currentPath());
    dir.cd("../../..");
    QFile fichier(dir.path() + "/accueil.xml");
#else
    QFile fichier(QDir::currentPath() + "/accueil.xml");
#endif
    doc.setContent(&fichier);
    BDD::currentNode = doc.elementsByTagName("arbre").at(0);

    //firstchild = branche
    currentNode = currentNode.firstChild();

    Categorie * cat = new Categorie(0);

    listeQuestionWithCategorie(cat, true);

    return cat->getListeQuestion();
}

void CategorieBDD::listeQuestionWithCategorie(Categorie * cat, bool recursif = true)   {

    // r�cup�ration de la liste de toutes les questions
    QDomNodeList lstBaliseQuestion = BDD::currentNode.childNodes(); // ==> renvoi "question"
    //qDebug() << "In listeQuestionWithCategorie(" << cat->getIdentifiant() << ", " << recursif << ")";
    //qDebug() << "nombre de question " << lstBaliseQuestion.size();

    int i;
    Question * temp;
    for(i=0; i<lstBaliseQuestion.size(); i++)  {
        //qDebug() << "Question " << i;
        //d�coupage du q devant l'id
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
    doc.clear();
    QDomNode noeud = doc.createProcessingInstruction("xml","version=\"1.0\"");
    doc.appendChild(noeud);

    QDomElement arbre = doc.createElement("arbre");
    doc.appendChild(arbre);

    currentNode = arbre;

    enregistrerCategorie(racine);

#ifdef Q_OS_MACX
    QDir dir(QDir::currentPath());
    dir.cd("../../..");
    QFile fichier(dir.path() + "/enregistrement.xml");
#else
    QFile fichier(QDir::currentPath() + "/enregistrement.xml");
#endif
    if ( !fichier.open(QIODevice::WriteOnly) ) {
        qDebug("Impossible de cr�er le fichier xml pour sauvegarder les donn�es");
        return;
    }
    else    {
        QTextStream textStream(&fichier);
        qDebug() <<"\n Enregistrement dans le fichier";
        textStream <<  doc.toString();
    }

   fichier.close();
}

void CategorieBDD::enregistrerCategorie(Categorie * currentCat) {
    QDomNode memoire = currentNode;
    QDomElement root = doc.createElement("branche");
    root.setAttribute("id", "b"+QString::number(currentCat->getIdentifiant()));
    root.setAttribute("type", currentCat->getLabel());
    currentNode.appendChild(root);

    currentNode = root;

    ListeQuestion *lq = currentCat->getListeQuestion();
    for(int i = 0; i < lq->size(); i++) {
        QuestionBDD::enregistrerQuestion(lq->at(i));
    }
    currentNode = memoire;
}


//initialisation (doc type et arbre) => 1ere fonction
    //cr�ation des noeuds branche (fonction ind�pendante qui prend en param cat�gorie)  ==> 2eme fonction
    // cherche liste question (Listequestion de cette cat�gorie)        ==> 2eme fonction
        //cr�er balise pour chaque question (dans une autre fonction qui prend en param la liste de question)==> 3eme fonction
        //cherche liste des r�ponse ==> 3eme fonction
            //(dans une autre fct) trait� les r�ponses  ==> 4eme fonction
            //cr�er les balises espece, et si nouvelle branche on rapelle ligne 101 ==> 4eme fonction
