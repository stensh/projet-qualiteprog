#include "doctest.h"
#include "../questionnaire/questionnaire.h"
#include "../questionnaire/questionTexte.h"
#include "../evaluation/evaluation.h"
#include "../evaluation/evaluationTest.h"

TEST_CASE("L'évaluation de base fonctionne")
{
    sujet::questionnaire q{""};

    q.ajouteQuestion(
        std::make_unique<sujet::questionTexte>(
            "Capitales",
            "Quelle est la capitale de la France ?",
            "Paris"
        )
    );

    test::evaluationTest e{q};

    SUBCASE("Le constructeur de l'evaluation fonctionne")
    {
        REQUIRE_EQ(e.nbQuestions(), 1);
        REQUIRE_EQ(e.bonnesReponses(), 0);
        REQUIRE_EQ(e.questionsPosees(), 0);
    }

    SUBCASE("L'incrémentation des compteurs fonctionne")
    {
        SUBCASE("Incrémenter les bonnes réponses fonctionne")
        {
            e.incrementeBonnesReponses();
            REQUIRE_EQ(e.bonnesReponses(), 1);
        }

        SUBCASE("Incrémenter les questions posées fonctionne")
        {
            e.incrementeQuestionsPosees();
            REQUIRE_EQ(e.questionsPosees(), 1);
        }
    }
}