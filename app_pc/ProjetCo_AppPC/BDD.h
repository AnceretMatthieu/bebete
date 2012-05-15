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

        /*virtual bool insert();
        virtual bool update();
        virtual bool delete();*/

        //QDomDocument currentNode;
         static QDomNode currentNode;
};

#endif // BDD_h
