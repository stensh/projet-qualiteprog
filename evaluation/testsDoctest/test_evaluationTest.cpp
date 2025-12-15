#include "doctest.h"
#include "../../questionnaire/questionnaire.h"
#include "../evaluationTest.h"

TEST_CASE("L'évaluation test fonctionne") {
    sujet::questionnaire q{"fichierTest.txt"};
    test::evaluationTest e{q};
    SUBCASE("L'indice courant est correct") {
        // TODO tests sur l'indice courant (différence constructeur avec la classe de base)
    }
    SUBCASE("La navigation à travers les questions fonctionne") {
        REQUIRE_UNARY(e.resteQuestions());
        e.questionSuivante();
        REQUIRE_UNARY_FALSE(e.resteQuestions());
    }
    SUBCASE("Le calcul des résultats fonctionne") {

        SUBCASE("Aucune question posée fonctionne") {
            double noteNulle {0.0};
            REQUIRE_EQ(e.resultats(), noteNulle);
        }
        SUBCASE("Toutes les réponses correctes fonctionne") {
            double noteParfaite {20.0};
            e.incrementeBonnesReponses();
            e.incrementeQuestionsPosees();
            REQUIRE_EQ(e.resultats(), noteParfaite);
        }
        SUBCASE("Réponses partiellement correctes fonctionne") {
            double noteTroisQuart {75.0};
            for (int i{0}; i < 3; ++i) {
                e.incrementeBonnesReponses();
                e.incrementeQuestionsPosees();
            }
            e.incrementeQuestionsPosees();
            REQUIRE_EQ(e.resultats(), noteTroisQuart);
        }
        SUBCASE("Aucune bonne réponse fonctionne") {
            double noteNulle {0.0};
            e.incrementeQuestionsPosees();
            REQUIRE_EQ(e.resultats(), noteNulle);
        }
    }
    SUBCASE("Ne jamais afficher les bonnes réponses fonctionne") {
        REQUIRE_UNARY_FALSE(e.afficherBonneReponse());
    }
}

