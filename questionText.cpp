//
// Created by rquen on 14/11/2025.
//

#include "questionText.h"

questionText::questionText(const std::string& intitule, const std::string& texte, const std::string& reponse):
    question{intitule, texte}, d_reponse{reponse}
{}


void questionText::renvoieReponse() const
{
    return d_reponse;
}

