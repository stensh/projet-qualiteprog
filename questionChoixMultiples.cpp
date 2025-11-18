//
// Created by surab on 11/14/2025.
//

#include "questionChoixMultiples.h"


questionChoixMultiples::questionChoixMultiples(const std::string& intitule,
    const std::string& texte,
    int bonneReponse): question{intitule,texte}, d_bonneReponse{bonneReponse}
{}

int questionChoixMultiples::bonneReponse()const
{
    return d_bonneReponse;
}

void questionChoixMultiples::modifierReponse(int reponse)
{
    d_bonneReponse = reponse;
}