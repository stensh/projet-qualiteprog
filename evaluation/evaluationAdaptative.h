#ifndef PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H
#define PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H

#include "evaluation.h"

/**
* Questions posées dans un ordre aléatoire
* Une question avec une mauvaise réponse sera reposée à la fin
*/

namespace test
{
    class evaluationAdaptative : public evaluation
    {
    public:
        evaluationAdaptative(const sujet::questionnaire& q);
        bool resteQuestions() const override;
        bool afficherBonneReponse() const override;
        void questionSuivante() override;
        double resultats() const override;
    private:
        int d_nbEssais;
    };
} // test

#endif //PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H
