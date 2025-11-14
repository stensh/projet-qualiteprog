//
// Created by rquen on 14/11/2025.
//

#ifndef PROJET_QUALITEPROG_QUESTIONNAIRE_H
#define PROJET_QUALITEPROG_QUESTIONNAIRE_H

#include <memory>
#include <vector>
#include "question.h"

class questionnaire
{
    public:
        questionnaire();
        ~questionnaire();

    private:
        std::vector<std::unique_ptr<question>> d_questionnaire;
};


#endif //PROJET_QUALITEPROG_QUESTIONNAIRE_H