//
// Created by surab on 11/14/2025.

#ifndef PROJET_QUALITEPROG_QUESTIONNUMERIQUE_H
#define PROJET_QUALITEPROG_QUESTIONNUMERIQUE_H
#include <string>
#include "question.h"

class questionNumerique: public question
{
public:
    questionNumerique(const std::string& intitule,const std::string& texte,int limMin,int limMax);

    int limiteMin() const ;//Renvoie la limite minimale de la réponse
    void modifierLimiteMin(int limMin);//Modifier la limite maximale

    int limiteMax() const ;//Renvoie la limite maximale de la réponse
    void modifierLimiteMax(int limMax);//Modifier la limite maximale
private:
    int  d_limMin, d_limMax;
};


#endif //PROJET_QUALITEPROG_QUESTIONNUMERIQUE_H