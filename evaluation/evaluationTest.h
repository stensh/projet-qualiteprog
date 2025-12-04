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
        evaluationTest(const sujet::questionnaire& q);
        bool resteQuestions() const override;
        bool afficherBonneReponse() const override;
        void questionSuivante() override;
        double resultats() const override;
    };
}

#endif //PROJET_QUALITEPROG_EVALUATIONTEST_H
