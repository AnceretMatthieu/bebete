#ifndef ListeMedia_h
#define ListeMedia_h

#include <vector>
#include "Media.h"

class ListeMedia : public std::vector {

 public:

    Media getElementById(int id);

    Media getElementByPath(char * path);
};

#endif // ListeMedia_h
