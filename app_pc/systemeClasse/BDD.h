#ifndef BDD_h
#define BDD_h
#include <QByteArray>
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QDir>

class BDD {

    public:
        virtual bool insert();
        virtual bool update();
        //virtual bool delete();
    protected:
        static QDomDocument * currentNode;
};

#endif // BDD_h
