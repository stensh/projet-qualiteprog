//
// Created by surab on 11/14/2025.
//

#ifndef PROJET_QUALITEPROG_QUESTIONCHOIXMULTIPLES_H
#define PROJET_QUALITEPROG_QUESTIONCHOIXMULTIPLES_H

#include <vector>
#include "question.h"


class questionChoixMultiples: public question
{
public:
    questionChoixMultiples(const std::string& intitule,
        const std::string& texte,int reponse); //Ici la reponse stockée est la bonne réponse
    int reponse() const;
private:
    int d_reponse;//La bonne réponse de la question
};


#endif //PROJET_QUALITEPROG_QUESTIONCHOIXMULTIPLES_H