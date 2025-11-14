//
// Created by surab on 11/14/2025.
//

#include "questionNumerique.h"

//Constructeur
questionNumerique::questionNumerique(std::string intitule, std::string texte, int reponse,int limMin,int limMax):
        question{intitule,texte},
            d_reponse{reponse},d_limMin{limMin},d_limMax{limMax}
{}
//renvoie de la bonne reponse de la question numerique
 int questionNumerique::reponse() const
{
    return d_reponse;
}

//renvoie la limite minimal
int questionNumerique::limiteMin()const
{
    return d_limMin;
}

//Renvoie la limite maximal
int questionNumerique::limiteMax()const
{
    return d_limMax;
}