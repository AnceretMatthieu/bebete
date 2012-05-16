#ifndef Legende_h
#define Legende_h

#include <string>
#include "Media.h"
#include "string.h"
#define LEGENDE 4001


class Legende : public Media {

    private:
        char * content;

    public:
        Legende();

        const char* getContent() {
            return content;
        }

        void setContent(char * unContent) {
            content = unContent;
        }

        void setTypeLegende() {
            this->type = LEGENDE;
        }
};

#endif // Legende_h
