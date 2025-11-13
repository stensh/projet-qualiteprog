#ifndef PROJET_QUALITEPROG_EVALUATIONTEST_H
#define PROJET_QUALITEPROG_EVALUATIONTEST_H

#include "Evaluation.h"

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