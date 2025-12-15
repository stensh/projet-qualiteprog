#include <string>
#include "doctest.h"
#include "../../questionnaire/questionnaire.h"
#include "../../questionnaire/questionTexte.h"
#include "../evaluationAdaptative.h"

TEST_CASE("L'évaluation adaptative fonctionne") {
    sujet::questionnaire q{""};
    q.ajouteQuestion(
        std::make_unique<sujet::questionTexte>(
            "Capitales",
            "Quelle est la capitale de la France ?",
            "Paris"
        )
    );
    test::evaluationAdaptative e{q};

    SUBCASE("Reposer une question échouée fonctionne") {
        const std::string premiere_question = e.questionCourante()->contenu();
        e.marquerEchec();
        e.questionSuivante();
        REQUIRE_UNARY(e.resteQuestions());
        REQUIRE_EQ(e.questionCourante()->contenu(), premiere_question);
    }

    SUBCASE("Le calcul des résultats fonctionne") {

        SUBCASE("Aucun échec fonctionne") {
            double noteParfaite {20.0};
            e.incrementeBonnesReponses();
            e.incrementeQuestionsPosees();
            REQUIRE_EQ(e.resultats(), noteParfaite);
        }

        SUBCASE("Le calcul avec un échec et un deuxième essai réussi fonctionne") {
            double noteParfaite {20.0};
            e.questionSuivante();
            e.marquerEchec();
            e.incrementeBonnesReponses();
            e.questionSuivante();
            REQUIRE_EQ(e.resultats(), noteParfaite); // parti du principe que ça compte comme réussi
        }

        SUBCASE("Le calcul avec double échec fonctionne") {
            double noteNulle {0.0};
            e.marquerEchec();
            e.questionSuivante();
            e.marquerEchec();
            e.questionSuivante();
            REQUIRE_EQ(e.resultats(), noteNulle);
        }
    }
}