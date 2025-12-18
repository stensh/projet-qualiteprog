#include <sstream>
#include "../evaluation/testsDoctest/doctest.h"
#include "../questionnaire/questionnaire.h"
#include "../questionnaire/questionTexte.h"
#include "../evaluation/evaluationTest.h"
#include "../evaluation/evaluationSecondeChance.h"
#include "../evaluation/evaluationAdaptative.h"
#include "../evaluation/gestionnaireEvaluation.h"

TEST_CASE("Le gestionnaire d'évaluation fonctionne") {
    sujet::questionnaire q{""};
    q.ajouteQuestion(
        std::make_unique<sujet::questionTexte>(
            "Capitales",
            "Quelle est la capitale de la France ?",
            "Paris"
        )
    );
    test::gestionnaireEvaluation ge;

    SUBCASE("Les réponses d'une évaluation test fonctionnent") {
        test::evaluationTest eval{q};
        std::ostringstream sortie;

        SUBCASE("Une réponse correcte fonctionne") {
            std::istringstream entree("Paris\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 1);
            REQUIRE_EQ(eval.questionsPosees(), 1);
        }

        SUBCASE("Une mauvaise réponse fonctionne") {
            std::istringstream entree("Mulhouse\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 0);
            REQUIRE_EQ(eval.questionsPosees(), 1);
        }
    }

    SUBCASE("Les réponses d'une évaluation seconde chance fonctionnent") {
        test::evaluationSecondeChance eval{q};
        std::ostringstream sortie;

        SUBCASE("Un échec, puis une réussite à la deuxième tentative fonctionne") {
            std::istringstream entree("Mulhouse\nParis\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 1);
            REQUIRE_EQ(eval.questionsPosees(), 2);
        }

        SUBCASE("Un double échec fonctionne") {
            std::istringstream entree("Mulhouse\nStrasbourg\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 0);
            REQUIRE_EQ(eval.questionsPosees(), 2);
            REQUIRE_UNARY(sortie.str().find("Paris") != std::string::npos); // teste l'affichage en sortie
        }
    }

    SUBCASE("Les réponses d'une évaluation adaptative fonctionnent") {
        test::evaluationAdaptative eval{q};
        std::ostringstream sortie;

        SUBCASE("Aucun échec fonctionne") {
            std::istringstream entree("Paris\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 1);
            REQUIRE_EQ(eval.questionsPosees(), 1);
        }

        SUBCASE("Un échec puis une réussite fonctionne") {
            std::istringstream entree("Mulhouse\nParis\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 1);
            REQUIRE_EQ(eval.questionsPosees(), 2);
        }
    }
}