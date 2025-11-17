//
// Created by rquen on 14/11/2025.
//

#include "questionText.h"

questionTexte::questionTexte(const std::string& intitule, const std::string& texte, const std::string& reponse):
    question{intitule, texte}, d_reponse{reponse}
{}

std::string questionTexte::reponse() const
{
    return d_reponse;
}

