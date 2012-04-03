#ifndef ListeMedia_h
#define ListeMedia_h

#include <vector>
#include <QString>

class Media;
using namespace std;

class ListeMedia : public std::vector<Media*> {

 public:
    ListeMedia();
    Media * getElementById(int id);
    Media * getElementByPath(QString path);
};

#endif // ListeMedia_h
