#ifndef Categorie_h
#define Categorie_h

#include <QVector>
#include <QString>
#include "ListeQuestion.h"

using namespace std;

class Question;
class ListeQuestion;

/**
 *  \file Categorie.h
 *  \class Categorie
 *  \brief Class gérant une catégorie d'insecte, elle possède un nom, un identifiant unique et une liste de question permettant de trouver d'autre insecte
 */
class Categorie {

    private:
        int id;
        QString label;
        ListeQuestion * myQuestion;

    public:
        /**
         *  \fn Categorie(int identifiant)
         *  \brief constructeur
         */
        Categorie(int identifiant);

        /**
         *  \fn int getIdentifiant()
         *  \brief retourne l'identifiant de la catégorie
         *  \return int
         */
        int getIdentifiant() { return id; }

        /**
         *  \fn QString getLabel()
         *  \brief retourne le nom de la catégorie
         *  \return QString
         */
        QString getLabel() { return label; }

        /**
         *  \fn void setLabel(QString unLabel)
         *  \brief change le nom de la catégorie
         *  \param QString unLabel : le nouveau nom de la catégorie
         *  \return void
         */
        void setLabel(QString unLabel) { label = unLabel; }

        /**
         *  \fn void ajouterQuestion(Question * rep)
         *  \brief Ajoute une Question dans la liste des questions
         *  \param Question * rep : la question à ajouter
         */
        void ajouterQuestion(Question * rep);

        /**
         *  \fn void supprimerQuestion(Question * rep)
         *  \brief Supprime une Question dans la liste des questions
         *  \param Question * rep : la question à supprimer
         */
        void supprimerQuestion(Question * rep);

        /**
         *  \fn ListeQuestion * getListeQuestion()
         *  \brief retourne la liste des questions de la catégorie
         *  \return ListeQuestion *
         */
        ListeQuestion * getListeQuestion()  {return myQuestion;}
};

#endif // Categorie_h
