#include <QtCore/QCoreApplication>
#include <iostream>
#include "ListeMedia.h"
#include "ListeQuestion.h"
#include "ListeReponse.h"
#include "QuestionBDD.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QuestionBDD::parseXML();
    
    return a.exec();
}