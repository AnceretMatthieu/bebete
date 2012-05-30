#ifndef BDD_h
#define BDD_h

#include <QByteArray>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QDir>

class BDD {

    public:
        BDD();

         static QDomNode currentNode;
         static QDomDocument doc;
};

#endif // BDD_h
