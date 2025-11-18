//
// Created by surab on 11/14/2025.
//

#include "questionNumerique.h"

//Constructeur
questionNumerique::questionNumerique(const std::string& intitule,const  std::string& texte,int limMin,int limMax):
        question{intitule,texte}
            ,d_limMin{limMin},d_limMax{limMax}
{}

//renvoie la limite minimal
int questionNumerique::limiteMin()const
{
    return d_limMin;
}

void questionNumerique::modifierLimiteMax(int limMax)
{
    d_limMax=limMax;
}

//Renvoie la limite maximal
int questionNumerique::limiteMax()const
{
    return d_limMax;
}

void questionNumerique::modifierLimiteMin(int limMin)
{
    d_limMin=limMin;
}