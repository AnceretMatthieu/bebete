#ifndef ListeMedia_h
#define ListeMedia_h

#include <vector>
#include "Media.h"

using namespace std;
//template<class Media>;
class ListeMedia {//: public std::vector<Media*> {

 public:
    ListeMedia();
    Media * getElementById(int id);
    Media * getElementByPath(char * path);
};

#endif // ListeMedia_h
