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
        incrementeQuestionsPosees(); // à faire au moment de poser la question, gestionnaireEvaluation ?
    }

    double evaluationTest::resultats() const
    {
        return bonnesReponses() * 20 / questionsPosees(); // note sur 20
    }
}
