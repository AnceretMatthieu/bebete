#ifndef Legende_h
#define Legende_h

#include <string>
#include "Media.h"
#include "string.h"
#define LEGENDE 4001

/**
 *  \class Legende
 *  \file Legende.h
 *  \brief classe gérant une l�gende avec ça description
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

#endif // Legende_h
