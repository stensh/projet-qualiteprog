//
// Created by surab on 11/14/2025.
//

#include "question.h"

question::question(const std::string& intitule, const std::string& texte):d_intitule{intitule} , d_texte{texte}
{}

//Methodes qui renvoie directement l'intitule et le texte de la question
std::string question::renvoieQuestion() const
{
    return d_intitule + '\n' + d_texte;
}

//Pour renvoyer uniquement l'intitule de la question
std::string question::intituleQuestion() const
{
    return d_intitule;
}//Pour renvoyer uniquement le texte de la question
std::string question::texteQuestion() const
{
    return d_texte;
}