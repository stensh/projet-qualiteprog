//
// Created by rquen on 14/11/2025.
//

#include "questionnaire.h"

#include <iostream>
#include <ostream>

question::question(std::string intitule, std::string texte):d_intitule{intitule} , d_texte{texte}
{}
void question::afficherQuestion()
{
    std::cout << d_intitule << " : " << d_texte << std::endl;
}
