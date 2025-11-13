#ifndef PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H
#define PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H

#include "Evaluation.h"

namespace test
{
    class EvaluationSecondeChance
    {
    public:
        EvaluationSecondeChance();
        void commencer() const override;
    };
} // test

#endif //PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H