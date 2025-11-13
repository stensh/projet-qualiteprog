#ifndef PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H
#define PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H

/**
* Questions posées dans un ordre aléatoire
* Une question avec une mauvaise réponse sera reposée à la fin
*/

namespace test
{
    class EvaluationAdaptative
    {
    public:
        EvaluationAdaptative();
        void commencer() const override;
    };
} // test

#endif //PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H