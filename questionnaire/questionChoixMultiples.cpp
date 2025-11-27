#include "questionChoixMultiples.h"

namespace sujet
{

questionChoixMultiples::questionChoixMultiples(const std::string& intitule, const std::string& texte, int bonneReponse):
    question{intitule,texte}, d_bonneReponse{bonneReponse}
{}

int questionChoixMultiples::reponse() const
{
    return d_bonneReponse;
}

bool questionChoixMultiples::reponseJuste(std::string& rep)const
{
    int reponseInt = std::stoi(rep);
    return reponseInt == reponse();
}

}