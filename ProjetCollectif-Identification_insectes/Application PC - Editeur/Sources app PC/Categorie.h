#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QVector>
#include <QString>
#include "ListeQuestion.h"
#include "Reponse.h"

using namespace std;

class Question;
class ListeQuestion;
class Reponse;

/**
 *  \file Categorie.h
 *  \class Categorie
 *  \brief Class gerant une categorie d'insecte, elle possede un nom, un identifiant unique et une liste de question permettant de trouver d'autre insecte
 */
class Categorie {

    private:
        int id;
        QString label;
        ListeQuestion * myQuestion;
        Reponse * myReponsePere;

    public:
        /**
         *  \fn Categorie(int identifiant)
         *  \brief constructeur
         */
        Categorie(int identifiant);

        /**
         *  \fn int getIdentifiant()
         *  \brief retourne l'identifiant de la categorie
         *  \return int
         */
        int getIdentifiant() { return id; }

        /**
         *  \fn QString getLabel()
         *  \brief retourne le nom de la categorie
         *  \return QString
         */
        QString getLabel() { return label; }

        /**
         *  \fn void setReponse(Reponse * pere)
         *  \brief change le père de la catégorie
         *  \return void
         */
        void setReponse(Reponse * pere) { myReponsePere = pere; }

        /**
         *  \fn void setLabel(QString unLabel)
         *  \brief change le nom de la categorie
         *  \param QString unLabel : le nouveau nom de la categorie
         *  \return void
         */
        void setLabel(QString unLabel) { label = unLabel; }

        /**
         *  \fn void ajouterQuestion(Question * rep)
         *  \brief Ajoute une Question dans la liste des questions
         *  \param Question * rep : la question a ajouter
         */
        void ajouterQuestion(Question * rep);

        /**
         *  \fn void supprimerQuestion(Question * rep)
         *  \brief Supprime une Question dans la liste des questions
         *  \param Question * rep : la question a supprimer
         */
        void supprimerQuestion(Question * rep);

        /**
         *  \fn ListeQuestion * getListeQuestion()
         *  \brief retourne la liste des questions de la categorie
         *  \return ListeQuestion *
         */
        ListeQuestion * getListeQuestion()  {return myQuestion;}
};

#endif // CATEGORIE_H
