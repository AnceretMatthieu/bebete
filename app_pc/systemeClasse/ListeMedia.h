#ifndef ListeMedia_h
#define ListeMedia_h

#include <QVector>
#include <QString>

using namespace std;

class Media;

class ListeMedia : public QVector<Media*> {

    public:
        ListeMedia();

        Media * getElementById(int id);
        Media * getElementByPath(QString path);
};

#endif // ListeMedia_h
