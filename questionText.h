//
// Created by rquen on 14/11/2025.
//

#ifndef PROJET_QUALITEPROG_QUESTIONTEXT_H
#define PROJET_QUALITEPROG_QUESTIONTEXT_H

#include "question.h"

class questionTexte : public question
{
    public:
        questionTexte(const std::string& intitule, const std::string& texte, const std::string& reponse);

        std::string reponse() const;    //Renvoie la bonne réponse.

    private:
        std::string d_reponse;

};


#endif //PROJET_QUALITEPROG_QUESTIONTEXT_H