#include "doctest.h"
#include "../../questionnaire/questionnaire.h"
#include "../evaluation.h"
#include "../evaluationTest.h"

TEST_CASE("L'évaluation de base fonctionne") {
    sujet::questionnaire q{"fichierTest.txt"};
    test::evaluationTest e{q};
    SUBCASE("Le constructeur de l'evaluation fonctionne") {
        REQUIRE_EQ(e.nbQuestions(), 1);
        REQUIRE_EQ(e.bonnesReponses(), 0);
        REQUIRE_EQ(e.questionsPosees(), 0);
    }
    SUBCASE("L'incrémentation des compteurs fonctionne") {
        SUBCASE("Incrémenter les bonnes réponses fonctionne") {
            e.incrementeBonnesReponses();
            REQUIRE_EQ(e.bonnesReponses(), 1);
        }
        SUBCASE("Incrémenter les questions posées fonctionne") {
            e.incrementeQuestionsPosees();
            REQUIRE_EQ(e.questionsPosees(), 1);
        }
    }
}

// TODO checker encore que le questionnaire est bien stocké