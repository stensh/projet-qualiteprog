#include "evaluationTest.h"

namespace test
{
    evaluationTest::evaluationTest(const sujet::questionnaire& q)
        : evaluation{q}
    {}

    bool evaluationTest::afficherBonneReponse() const
    {
        return false;
    }

    bool evaluationTest::resteQuestions() const
    {
        return nbQuestions() - indiceCourant() > 0;
    }

    void evaluationTest::questionSuivante()
    {
        incrementeIndiceCourant();
        incrementeQuestionsPosees();
    }

    double evaluationTest::resultats() const
    {
        return bonnesReponses() * 20 / questionsPosees();
    }
}
