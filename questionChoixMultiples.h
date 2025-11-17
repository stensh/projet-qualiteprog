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
        const std::string& texte, int reponse);  //Ici la reponse passé en paramètre est le numéro de la bonne réponse.
        int reponse() const;    //Renvoie le numéro de la réponse.
        void modifierReponse(int reponse); //Dans le cas où on veut pouvoir modifier la reponse
    private:
        int d_reponse;  //Le numéro de la bonne réponse à la question.
};


#endif //PROJET_QUALITEPROG_QUESTIONCHOIXMULTIPLES_H