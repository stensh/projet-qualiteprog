//
// Created by rquen on 14/11/2025.
//

#ifndef PROJET_QUALITEPROG_QUESTIONTEXT_H
#define PROJET_QUALITEPROG_QUESTIONTEXT_H
#include "question.h"



class questionText : public question
{
    public:
        questionText(const std::string& intitule, std::string texte, const std::string& reponse);

        std::string intitule() const;
        void setIntitile(const std::string& intitile);

        std::string texte() const;
        void setTexte(std::string texte);

        std::string solution() const;
        void setSolution(const std::string& solution);

        std::string reponse() const;    //Renvoie la bonne réponse.
        void setReponse(const std::string& reponse);

    private:
        std::string d_reponse;

};


#endif //PROJET_QUALITEPROG_QUESTIONTEXT_H