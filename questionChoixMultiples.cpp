//
// Created by surab on 11/14/2025.
//

#include "questionChoixMultiples.h"


questionChoixMultiples::questionChoixMultiples(const std::string& intitule,
    const std::string& texte,
    const std::vector<int>& reponses): question{intitule,texte},d_reponses{reponses}
{}

std::vector<int> questionChoixMultiples::reponses() const
{
    return d_reponses;
}

