#ifndef ListeMedia_h
#define ListeMedia_h

#include <vector>
#include <QString>

using namespace std;

class Media;

class ListeMedia : public std::vector<Media*> {

    public:
        ListeMedia();

        Media * getElementById(int id);
        Media * getElementByPath(QString path);
};

#endif // ListeMedia_h
