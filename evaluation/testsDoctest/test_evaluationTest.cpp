#include "doctest.h"
#include "../../questionnaire/questionnaire.h"
#include "../evaluationTest.h"

// TODO on re-teste le constructeur ?

TEST_CASE("La navigation à travers les questions fonctionne") {
    sujet::questionnaire q{"fichierTest.txt"};
    test::evaluationTest e{q};

    REQUIRE_UNARY(e.resteQuestions());
    REQUIRE_EQ(e.questionCourante()->contenu(), "Question 1");

    e.questionSuivante();
    REQUIRE_UNARY(e.resteQuestions());
    REQUIRE_EQ(e.questionCourante()->contenu(), "Question 2");

    e.questionSuivante();
    REQUIRE_UNARY(e.resteQuestions());
    REQUIRE_EQ(e.questionCourante()->contenu(), "Question 3");

    e.questionSuivante();
    REQUIRE_UNARY_FALSE(e.resteQuestions());
}

TEST_CASE("Le calcul des résultats fonctionne") {
    sujet::questionnaire q{"fichierTest.txt"};
    test::evaluationTest e{q};
    SUBCASE("Aucune question posée fonctionne") {
        REQUIRE_EQ(e.resultats(), 0.0);
    }
    SUBCASE("Toutes les réponses correctes fonctionne") {
        for (int i{0}; i < 4; ++i) {
            e.incrementeBonnesReponses();
            e.incrementeQuestionsPosees();
        }
        REQUIRE_EQ(e.resultats(), 20.0);
    }
    SUBCASE("Réponses partiellement correctes fonctionne") {
        for (int i{0}; i < 3; ++i) {
            e.incrementeBonnesReponses();
            e.incrementeQuestionsPosees();
        }
        e.incrementeQuestionsPosees();
        REQUIRE_EQ(e.resultats(), 75.0);
    }
    SUBCASE("Aucune bonne réponse fonctionne") {
        for (int i{0}; i < 3; ++i) {
            e.incrementeQuestionsPosees();
        }
        REQUIRE_EQ(e.resultats(), 0.0);
    }
}

TEST_CASE("Ne jamais afficher les bonnes réponses fonctionne") {
    sujet::questionnaire q{"fichierTest.txt"};
    test::evaluationTest e{q};
    REQUIRE_UNARY_FALSE(e.afficherBonneReponse());
}