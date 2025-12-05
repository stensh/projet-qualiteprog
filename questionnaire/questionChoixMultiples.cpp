#include "questionnaire/questionChoixMultiples.h"

namespace sujet
{

questionChoixMultiples::questionChoixMultiples(const std::string& intitule, const std::string& texte, int bonneReponse):
    question{intitule,texte}, d_bonneReponse{bonneReponse}
{}

std::string questionChoixMultiples::reponse() const
{
    return std::to_string(d_bonneReponse);
}

bool questionChoixMultiples::reponseJuste(const std::string& rep)const
{
    int reponseInt = std::stoi(rep);
    return reponseInt == d_bonneReponse;
}

}