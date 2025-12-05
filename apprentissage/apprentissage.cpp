#include <iostream>
#include "apprentissage.h"

namespace revision
{
    void apprentissage::commencer(const sujet::questionnaire &quest)
    {
        for (int i{0}; i < quest.taille(); ++i)
        {
            std::cout << quest.questionIndice(i)->contenu() << std::endl;
            // TODO attendre une action de l'utilisateur
            std::cout << // quest.questionCourante()->reponse() << std::endl
        }
    }

}