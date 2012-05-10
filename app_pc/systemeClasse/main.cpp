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

<<<<<<< HEAD
=======
    QuestionBDD * o = new QuestionBDD();
    o->CreerArbre();
    
>>>>>>> 7f1b825f78b331c8508bf15f853ef6dee707e278
    return a.exec();
}
