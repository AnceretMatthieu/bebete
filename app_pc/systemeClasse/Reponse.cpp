#include "Reponse.h"
#include "ListeMedia.h"
#include "Media.h"
#include "Question.h"
#include "Espece.h"

int Reponse::getIdentifiant()   {
    return id;
}

QString Reponse::getReponse()    {
}

void Reponse::AjouterMedia(Media * media) {
}

void Reponse::SupprimerMedia(int id)    {
}

Question * Reponse::getQuestionSuiv()   {
}

Question * Reponse::getQuestionPrec()   {
}

ListeMedia * Reponse::getListeIllustration()    {
}

void Reponse::setReponse(QString rep) {
}

void Reponse::setQuestionSuiv(Question *question)   {
}

void Reponse::setQuestionPrec(Question *question)   {
}

void Reponse::ajouterMedia(Media *med)  {
}

void Reponse::supprimerMedia(Media *med)    {
}
