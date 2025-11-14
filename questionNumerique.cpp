//
// Created by surab on 11/14/2025.
//

#include "questionNumerique.h"

//Constructeur
questionNumerique::questionNumerique(std::string intitule, std::string texte, int reponse):question{intitule,texte},
            d_reponse{reponse}
{}
//renvoie de la bonne reponse de la question numerique
 int questionNumerique::reponse() const
{
    return d_reponse;
}
