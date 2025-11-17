#ifndef PROJET_QUALITEPROG_EVALUATIONTEST_H
#define PROJET_QUALITEPROG_EVALUATIONTEST_H

#include "evaluation.h"

/**
* Chaque question est posée dans l'ordre, sans afficher les bonnes réponses
*/

namespace test
{
    class evaluationTest : public evaluation
    {
    public:
        evaluationTest();
        void commencer(const int /*Questionnaire&*/ q) const override;
        bool resteQuestions() const override;
        int /*plutôt Question*/ & questionCourante() override;
        void questionSuivante() override;
        void afficherResultats();
    };
} // test

#endif //PROJET_QUALITEPROG_EVALUATIONTEST_H
