#ifndef LEGENDE_H
#define LEGENDE_H

#include <string>
#include "Media.h"

#define LEGENDE 4001

/**
 *  \class Legende
 *  \file Legende.h
 *  \brief classe gerant une légende avec sa description
 */
class Legende : public Media {

    private:
        char * content;

    public:
        /**
         * \fn Légende()
         * \brief constructeur par défaut
         */
        Legende();

        /**
         *  \fn char* getContent()
         *  \brief retourne le contenu de la légende
         *  \return char*
         */
        const char* getContent() {
            return content;
        }

        /**
         *  \fn void setContent(char * unContent)
         *  \brief change le contenu de la légende
         */
        void setContent(char * unContent) {
            content = unContent;
        }

        /**
         *  \fn void setTypeLegende()
         *  \brief change le type de légende
         */
        void setTypeLegende() {
            this->type = LEGENDE;
        }
};

#endif // LEGENDE_H
