#ifndef Legende_h
#define Legende_h

#include <string>
#include "Media.h"
#define LEGENDE 4001

class Legende : public Media {
private:
    char * content;
public:
    Legende();
    void setContent(const char * content);
    const char* getContent()    {return content;}
    void setTypeLegende()   {this->Type = LEGENDE;}
};

#endif // Legende_h
