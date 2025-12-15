#ifndef PROJET_QUALITEPROG_EVALUATIONTEST_H
#define PROJET_QUALITEPROG_EVALUATIONTEST_H

#include "evaluation.h"

namespace test
{
    class evaluationTest : public evaluation
    {
    public:
        // Constructeur
        evaluationTest(const sujet::questionnaire& q);

        // Méthodes surchargées
        const std::unique_ptr<sujet::question>& questionCourante() const override;
        void reussiteCourante() override;
        void echecCourant() override;
        bool resteQuestions() const override;
        bool afficherBonneReponse() const override;
        void questionSuivante() override;
        double resultats() const override;

    private:
        int d_indiceCourant;
    };
}

#endif //PROJET_QUALITEPROG_EVALUATIONTEST_H
