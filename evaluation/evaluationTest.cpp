#include "evaluationTest.h"

namespace test
{
    evaluationTest::evaluationTest(const sujet::questionnaire& q)
        : evaluation{q}, d_indiceCourant{0}
    {}

    const std::unique_ptr<sujet::question> &evaluationTest::questionCourante() const
    {
        return questionnaire().questionIndice(d_indiceCourant);
    }

    bool evaluationTest::afficherBonneReponse() const
    {
        return false;
    }

    bool evaluationTest::resteQuestions() const
    {
        return d_indiceCourant < nbQuestions();
    }

    void evaluationTest::questionSuivante()
    {
        incrementeQuestionsPosees();
        ++d_indiceCourant;
    }

    double evaluationTest::resultats() const
    {
        if (questionsPosees() == 0) // TODO est-ce qu'on fait ce test ici ou ailleurs serait mieux ?
            return 0.0;
        return bonnesReponses() * 20.0 / questionsPosees();
    }
}
