#ifndef LEGENDE_H
#define LEGENDE_H

#include <string>
#include "Media.h"

#define LEGENDE 4001

/**
 *  \class Legende
 *  \file Legende.h
 *  \brief classe gerant une l�gende avec sa description
 */
class Legende : public Media {

    private:
        char * content;

    public:
        /**
         * \fn L�gende()
         * \brief constructeur par d�faut
         */
        Legende();

        /**
         *  \fn char* getContent()
         *  \brief retourne le contenu de la l�gende
         *  \return char*
         */
        const char* getContent() {
            return content;
        }

        /**
         *  \fn void setContent(char * unContent)
         *  \brief change le contenu de la l�gende
         */
        void setContent(char * unContent) {
            content = unContent;
        }

        /**
         *  \fn void setTypeLegende()
         *  \brief change le type de l�gende
         */
        void setTypeLegende() {
            this->type = LEGENDE;
        }
};

#endif // LEGENDE_H
