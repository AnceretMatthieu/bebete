#ifndef Question_h
#define Question_h

#include <QVector>
#include <QString>

class ListeReponse;
class ListeMedia;
class Media;
class Reponse;
class Categorie;

/**
 *  \class Question
 *  \file Question.h
 *  \brief classe gérant une question avec sa description
 */
class Question {

    private:
       int id;
       int idleft;
       int idright;
       QString texte;
       QString visible;

       ListeReponse * listeReponse;
       ListeMedia * listeMedia;
       Categorie *myCategorie;

    public:

       /**
        * \fn Question(int id)
        * \brief constructeur
        * \param int id : l'identifiant unique de la question � instancier
        */
        Question(int id);

        /**
         * \fn Question(question *)
         * \brief constructeur
         * \param Question * : Pour faire une question
         */
        Question(Question *);

        /**
         *  \fn int getIdentifiant()
         *  \brief retourne l'identifiant de la question
         *  \return int id
         */
        int getIdentifiant() { return id; }

        /**
         *  \fn int getQuestion()
         *  \brief retourne le texte de la question
         *  \return QString texte
         */
        QString getQuestion() { return texte; }

        /**
         *  \fn int getVisible()
         *  \brief retourne la visibilit� de la question
         *  \return QString visible
         */
        QString getVisible() { return visible; }

        /**
         *  \fn void setVisible(QString visible)
         *  \brief change la visibilit�
         *  \param QString visible : le nouveau nom pour la visibilit�
         */
        void setVisible(QString visible) {this->visible = visible;}

        /**
         *  \fn void setIdLeft(int id)
         *  \brief change l'Id de celui de gauche
         *  \param int id
         */
        void setIdLeft(int id)  {idleft = id;}

        /**
         *  \fn void setIdRight(int id)
         *  \brief change l'Id de celui de droite
         *  \param int id
         */
        void setIdRight(int id)  {idright = id;}

        /**
         *  \fn int getIdLeft()
         *  \brief r�cup�re l'Id de celui de gauche
         *  \return int idleft
         */
        int getIdLeft()  {return idleft;}

        /**
         *  \fn int getIdRight()
         *  \brief r�cup�re l'Id de celui de droite
         *  \return int idright
         */
        int getIdRight()  {return idright;}

        /**
         *  \fn void setCat(Categorie *c)
         *  \brief change le nom de la categorie
         *  \param Categorie * c : Le nouveau nom pour la cat�gorie
         */
        void setCat(Categorie * c)  { myCategorie = c;}

        /**
         *  \fn Categorie * getCat()
         *  \brief retourne la cat�gorie
         *  \return Categorie * myCategorie
         */
        Categorie * getCat()    { return myCategorie; }

        /**
         *  \fn void setQuestion(QString question)
         *  \brief change le nom de la question
         *  \param QString question : le nouveau nom de la question
         *  \return void
         */
        void setQuestion(QString question) {texte = question;}

        /**
         *  \fn void ajouterReponse(Reponse * rep)
         *  \brief Ajoute une r�ponse dans la liste des reponses
         *  \param Reponse * rep : la r�ponse �  ajouter
         */
        void ajouterReponse(Reponse * rep);

        /**
         *  \fn void supprimerReponse(Reponse * rep)
         *  \brief supprime une r�ponse dans la liste des r�ponses
         *  \param Reponse * rep : la r�ponse � supprimer
         */
        void supprimerReponse(Reponse * rep);

        /**
         *  \fn ListeReponse * getListeReponse()
         *  \brief retourne la liste des r�ponses de la question
         *  \return ListeReponse *
         */
        ListeReponse* getListeReponse()  {return listeReponse;}

        /**
         *  \fn void ajouterMedia(Media * med);
         *  \brief ajoute un média pour illustrer la r�ponse
         *  \param Media * med : le nouveau média
         */
        void ajouterMedia(Media * med);

        /**
         *  \fn void supprimerMedia(Media * med)
         *  \brief supprime le média des r�ponses
         *  \param Media * med : le média a supprimé
         */
        void supprimerMedia(Media * med);

        /**
         *  \fn ListeMedia * getListeMedia()
         *  \brief retourne la liste des médias de la r�ponse
         *  \return ListeMedia *
         */
        ListeMedia * getListeMedia()    {return listeMedia;}
};

#endif // Question_h
