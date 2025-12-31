#include "doctest.h"
#include "../questionnaire/questionnaire.h"
#include "../questionnaire/questionTexte.h"
#include "../evaluation/evaluationTest.h"

TEST_CASE("L'évaluation test fonctionne")
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

    SUBCASE("L'indice courant est correct")
    {
        REQUIRE_EQ(e.questionCourante()->intitule(), "Capitales");
        e.questionSuivante();
        // Après questionSuivante(), resteQuestions() devrait être false
        REQUIRE_UNARY_FALSE(e.resteQuestions());
    }
    
    SUBCASE("Les méthodes reussiteCourante() et echecCourant() fonctionnent")
    {
        SUBCASE("reussiteCourante() incrémente les bonnes réponses")
        {
            REQUIRE_EQ(e.bonnesReponses(), 0);
            e.reussiteCourante();
            REQUIRE_EQ(e.bonnesReponses(), 1);
        }

        SUBCASE("echecCourant() n'incrémente pas les bonnes réponses")
        {
            REQUIRE_EQ(e.bonnesReponses(), 0);
            e.echecCourant();
            REQUIRE_EQ(e.bonnesReponses(), 0);
        }
    }

    SUBCASE("La navigation à travers les questions fonctionne")
    {
        REQUIRE_UNARY(e.resteQuestions());
        e.questionSuivante();
        REQUIRE_UNARY_FALSE(e.resteQuestions());
    }

    SUBCASE("Le calcul des résultats fonctionne")
    {
        SUBCASE("Aucune question posée fonctionne")
        {
            double noteNulle {0.0};
            REQUIRE_EQ(e.resultats(), noteNulle);
        }

        SUBCASE("Toutes les réponses correctes fonctionne")
        {
            double noteParfaite {20.0};
            e.incrementeBonnesReponses();
            e.incrementeQuestionsPosees();
            REQUIRE_EQ(e.resultats(), noteParfaite);
        }

        SUBCASE("Réponses partiellement correctes fonctionne")
        {
            double noteTroisQuart {15.0};
            for (int i{0}; i < 3; ++i) {
                e.incrementeBonnesReponses();
                e.incrementeQuestionsPosees();
            }
            e.incrementeQuestionsPosees();
            REQUIRE_EQ(e.resultats(), noteTroisQuart);
        }

        SUBCASE("Aucune bonne réponse fonctionne")
        {
            double noteNulle {0.0};
            e.incrementeQuestionsPosees();
            REQUIRE_EQ(e.resultats(), noteNulle);
        }
    }

    SUBCASE("Ne jamais afficher les bonnes réponses fonctionne")
    {
        REQUIRE_UNARY_FALSE(e.afficherBonneReponse());
    }
}

