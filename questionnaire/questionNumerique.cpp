#include <stdexcept>
#include "questionnaire/questionNumerique.h"

namespace sujet
{
//Constructeur
questionNumerique::questionNumerique(const std::string& intitule,const  std::string& texte,int limMin,int limMax):
    question{intitule,texte}, d_limiteMin{limMin}, d_limiteMax{limMax}
{}
//renvoie la limite minimal
int questionNumerique::limiteMin()const
{
    return d_limiteMin;
}
//Renvoie la limite maximal
int questionNumerique::limiteMax()const
{
    return d_limiteMax;
}

std::string questionNumerique::reponse() const
{
    return "entre " + std::to_string(limiteMin()) + " et " + std::to_string(limiteMax());
}

bool questionNumerique::reponseJuste(const std::string& reponse)const
{
    try
    {
        int reponseInt = std::stoi(reponse);
        return reponseInt >= limiteMin() && reponseInt <= limiteMax();
    }
    catch (const std::invalid_argument&)
    {
        return false;   // La chaîne ne peut pas être convertie en nombre
    }
    catch (const std::out_of_range&)
    {
        return false;   //Le nombre dépasse la limite d'un int
    }
}
}
