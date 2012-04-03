#include "Question.h"
#include "Categorie.h"

int Categorie::getIdentifiant() {
    return id;
}

QString Categorie::getLabel()    {
    return Label;
}

void Categorie::setLabel(QString lab) {
    Label = lab;
}
