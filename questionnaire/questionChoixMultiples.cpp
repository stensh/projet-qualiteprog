#include <stdexcept>
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
    try
    {
        int reponseInt = std::stoi(rep);
        return reponseInt == d_bonneReponse;
    }
    catch(const std::invalid_argument& )
    {
        return false;   //La chaine ne peut pas être convertie en nombre
    }
    catch(const std::out_of_range& )
    {
        return false;   //Le nombre dépasse la limite d'un int
    }
}

}
