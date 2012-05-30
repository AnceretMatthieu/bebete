#ifndef ListeQuestion_h
#define ListeQuestion_h

#include <QVector>

using namespace std;

class Question;

/**
 *  \class ListeQuestion
 *  \file ListeQuestion.h
 *  \brief classe g�rant un vecteur de question
 */
class ListeQuestion : public QVector<Question*> {

    private :
        int estVide;

    public:
        /**
         * \fn ListeQuestion()
         * \brief constructeur par d�faut
         */
        ListeQuestion();

        /**
         *  \fn getElementById(int id)
         *  \brief retourne un �l�ment gr�ce � son identificateur
         *  \param int id : l'identificateur de l'�l�ment
         *  \return Question*
         */
        Question * getElementById(int id);

        int getEstVide() { return estVide; }
        void setEstVide(int unBool) { estVide = unBool; }
};

#endif // ListeQuestion_h
