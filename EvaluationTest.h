#ifndef PROJET_QUALITEPROG_EVALUATIONTEST_H
#define PROJET_QUALITEPROG_EVALUATIONTEST_H

#include "Evaluation.h"

/**
* Chaque question est posée dans l'ordre, sans afficher les bonnes réponses
*/

namespace test
{
    class EvaluationTest : public Evaluation
    {
    public:
        EvaluationTest();
        void commencer() const override;
    };
} // test

#endif //PROJET_QUALITEPROG_EVALUATIONTEST_H