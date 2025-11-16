//
// Created by rquen on 14/11/2025.
//

#include "questionText.h"

questionText::questionText(const std::string& intitule, const std::string& texte, const std::string& reponse):
    question{intitule, texte}, d_reponse{reponse}
{}


std::string questionText::intitule() const {
    return d_intitule;
}

std::string questionText::reponse() const
{
    return d_reponse;
}

