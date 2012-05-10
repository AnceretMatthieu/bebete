#include <QtCore/QCoreApplication>
#include <iostream>
#include "ListeMedia.h"
#include "ListeQuestion.h"
#include "ListeReponse.h"
#include "QuestionBDD.h"
#include "BDD.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QuestionBDD * o = new QuestionBDD();
    o->CreerArbre();
    

    return a.exec();
}
