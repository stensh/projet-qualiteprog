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
        const std::string& texte,const std::vector<int>& reponses); //Ici les reponses stockées sont les bonnes réponses
    std::vector<int> reponses() const;
private:
    std::vector<int> d_reponses;
};


#endif //PROJET_QUALITEPROG_QUESTIONCHOIXMULTIPLES_H