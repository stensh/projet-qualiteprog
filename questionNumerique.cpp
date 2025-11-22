#include "questionNumerique.h"

namespace sujet
{
//Constructeur
questionNumerique::questionNumerique(const std::string& intitule,const  std::string& texte,int limMin,int limMax):
    question{intitule,texte}, d_limMin{limMin}, d_limMax{limMax}
{}
//renvoie la limite minimal
int questionNumerique::limiteMin()const
{
    return d_limMin;
}
//Renvoie la limite maximal
int questionNumerique::limiteMax()const
{
    return d_limMax;
}
bool questionNumerique::reponseJuste(std::string& reponse)const
{}
}