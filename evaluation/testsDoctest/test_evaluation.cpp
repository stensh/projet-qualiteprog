#include "doctest.h"
#include "../../questionnaire/questionnaire.h"
#include "../evaluation.h"
#include "../evaluationTest.h"

TEST_CASE("Construction de la classe abstraite evaluation fonctionne") {
        sujet::questionnaire q{"fichierTest.txt"};
        test::evaluationTest e{q};
        REQUIRE_EQ(e.nbQuestions(), 2);
        REQUIRE_EQ(e.bonnesReponses(), 0);
        REQUIRE_EQ(e.questionsPosees(), 0);
}

TEST_CASE("Incrémentation des compteurs fonctionne") {
        sujet::questionnaire q{"fichierTest.txt"};
        test::evaluationTest e{q};
        SUBCASE("Incrémenter les bonnes réponses fonctionne") {
                e.incrementeBonnesReponses();
                REQUIRE_EQ(e.bonnesReponses(), 1);
                e.incrementeBonnesReponses();
                REQUIRE_EQ(e.bonnesReponses(), 2);
        }
        SUBCASE("Incrémenter les questions posées fonctionne") {
                e.incrementeQuestionsPosees();
                REQUIRE_EQ(e.questionsPosees(), 1);
                e.incrementeQuestionsPosees();
                REQUIRE_EQ(e.questionsPosees(), 2);
        }
}

// TODO checker encore que le questionnaire est bien stocké