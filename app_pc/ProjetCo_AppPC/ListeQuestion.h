#ifndef ListeQuestion_h
#define ListeQuestion_h

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

<<<<<<< HEAD
=======
        /**
         *  \fn getElementById(int id)
         *  \brief retourne un élément grâce à son identificateur
         *  \param int id : l'identificateur de l'élément
         *  \return Question*
         */
>>>>>>> 5ebf339b631df3dffe1406581b70ea8315e152c7
        Question * getElementById(int id);

        int getEstVide() { return estVide; }
        void setEstVide(int unBool) { estVide = unBool; }
};

#endif // ListeQuestion_h
