#ifndef LISTEQUESTION_H
#define LISTEQUESTION_H

#include <QVector>

using namespace std;

class Question;

/**
 *  \class ListeQuestion
 *  \file ListeQuestion.h
 *  \brief classe gérant un vecteur de question
 */
class ListeQuestion : public QVector<Question*> {

    private :
        int estVide;

    public:
        /**
         * \fn ListeQuestion()
         * \brief constructeur par défaut
         */
        ListeQuestion();

        /**
         *  \fn getElementById(int id)
         *  \brief retourne un élément grâce à son identificateur
         *  \param int id : l'identificateur de l'élément
         *  \return Question*
         */
        Question * getElementById(int id);

        /**
         * \fn int getEstVide()
         * \brief permet de savoir si la liste est vide ou non
         * \return int : 0 si vide, 1 si non vide
         */
        int getEstVide() { return estVide; }

        /**
         * \fn void setEstVide(int unBool)
         * \brief permet de spécifier si la liste est vide ou non
         */
        void setEstVide(int unBool) { estVide = unBool; }
};

#endif // LISTEQUESTION_H
