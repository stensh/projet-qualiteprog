//
// Created by surab on 11/14/2025.
//

#include "questionChoixMultiples.h"


questionChoixMultiples::questionChoixMultiples(const std::string& intitule,
    const std::string& texte,
    int reponse): question{intitule,texte},d_reponse{reponse}
{}

int questionChoixMultiples::reponse() const
{
    return d_reponse;
}

