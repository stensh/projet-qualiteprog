#include "questionTexte.h"

namespace sujet
{

questionTexte::questionTexte(const std::string& intitule, const std::string& texte, const std::string& reponse):
    question{intitule, texte}, d_reponse{reponse}
{}

std::string questionTexte::reponse() const
{
    return d_reponse;
}

bool questionChoixMultiples::reponseJuste(std::string& reponse)const
{}

}