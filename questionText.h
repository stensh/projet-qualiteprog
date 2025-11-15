//
// Created by rquen on 14/11/2025.
//

#ifndef PROJET_QUALITEPROG_QUESTIONTEXT_H
#define PROJET_QUALITEPROG_QUESTIONTEXT_H
#include "question.h"



class questionText : public question
{
    public:
        questionText(const std::string& intitule, std::string texte);

        std::string reponse() const;    //Renvoie la bonne réponse.

    private:
        std::string d_reponse;

};


#endif //PROJET_QUALITEPROG_QUESTIONTEXT_H