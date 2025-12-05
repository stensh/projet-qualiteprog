#include "questionnaire/question.h"

namespace sujet
{

question::question(const std::string& intitule, const std::string& texte):
    d_intitule{intitule} , d_texte{texte}
{}

//Methodes qui renvoie directement l'intitule et le texte de la question
std::string question::contenu() const
{
    return d_intitule + '\n' + d_texte;
}

//Pour renvoyer uniquement l'intitule de la question
std::string question::intitule() const
{
    return d_intitule;
}

//Pour renvoyer uniquement le texte de la question
std::string question::texte() const
{
    return d_texte;
}

}