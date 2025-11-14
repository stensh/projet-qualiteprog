//
// Created by surab on 11/14/2025.
//

#include "question.h"

question::question(std::string intitule, std::string texte):d_intitule{intitule} , d_texte{texte}
{}
void question::afficherQuestion()
{
    std::cout << d_intitule << " : " << d_texte << std::endl;
}
