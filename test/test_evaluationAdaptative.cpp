#include <string>
#include <vector>
#include <algorithm>
#include "doctest.h"
#include "../questionnaire/questionnaire.h"
#include "../questionnaire/questionTexte.h"
#include "../evaluation/evaluationAdaptative.h"

TEST_CASE("L'évaluation adaptative fonctionne")
{
    sujet::questionnaire q{""};

    q.ajouteQuestion(
        std::make_unique<sujet::questionTexte>(
            "Capitales",
            "Quelle est la capitale de la France ?",
            "Paris"
        )
    );

    test::evaluationAdaptative e{q};

    SUBCASE("Reposer une question échouée fonctionne")
    {
        const std::string premiere_question = e.questionCourante()->contenu();
        e.marquerEchec();
        e.questionSuivante();
        REQUIRE_UNARY(e.resteQuestions());
        REQUIRE_EQ(e.questionCourante()->contenu(), premiere_question);
    }

    SUBCASE("Le calcul des résultats fonctionne")
    {
        SUBCASE("Aucun échec fonctionne")
        {
            double noteParfaite {20.0};
            e.incrementeBonnesReponses();
            e.incrementeQuestionsPosees();
            e.incrementeNbEssais();
            REQUIRE_EQ(e.resultats(), noteParfaite);
        }

        SUBCASE("Le calcul avec un échec et un deuxième essai réussi fonctionne")
        {
            double noteMoyenne {10.0};
            e.questionSuivante();
            e.marquerEchec();
            e.incrementeBonnesReponses();
            e.questionSuivante();
            REQUIRE_EQ(e.resultats(), noteMoyenne);
        }

        SUBCASE("Le calcul avec double échec fonctionne")
        {
            double noteNulle {0.0};
            e.marquerEchec();
            e.questionSuivante();
            e.marquerEchec();
            e.questionSuivante();
            REQUIRE_EQ(e.resultats(), noteNulle);
        }

        SUBCASE("La logique de réussite/échec fonctionne")
        {
            SUBCASE("reussiteCourante() incrémente les bonnes réponses")
            {
                REQUIRE_EQ(e.bonnesReponses(), 0);
                e.reussiteCourante();
                REQUIRE_EQ(e.bonnesReponses(), 1);
            }

            SUBCASE("echecCourant() marque l'échec sans incrémenter les bonnes réponses")
            {
                REQUIRE_EQ(e.bonnesReponses(), 0);
                e.echecCourant();
                REQUIRE_EQ(e.bonnesReponses(), 0);
            }
        }

        SUBCASE("Marquer l'échec fonctionne")
        {
            const std::string premiere_question = e.questionCourante()->contenu();
            e.marquerEchec();
            e.questionSuivante();
            // Après un échec, la question devrait être reposée à la fin
            REQUIRE_UNARY(e.resteQuestions());
            // On devrait retrouver la même question à la fin
            e.questionSuivante();
            REQUIRE_EQ(e.questionCourante()->contenu(), premiere_question);
        }

        SUBCASE("Le mélange aléatoire fonctionne")
        {
            sujet::questionnaire q2{""};
            q2.ajouteQuestion(std::make_unique<sujet::questionTexte>("Q1", "Question 1", "R1"));
            q2.ajouteQuestion(std::make_unique<sujet::questionTexte>("Q2", "Question 2", "R2"));
            q2.ajouteQuestion(std::make_unique<sujet::questionTexte>("Q3", "Question 3", "R3"));

            test::evaluationAdaptative e2{q2};
            std::vector<std::string> intitules;
            while (e2.resteQuestions())
            {
                intitules.push_back(e2.questionCourante()->intitule());
                e2.questionSuivante();
            }
            REQUIRE_EQ(intitules.size(), 3);

            REQUIRE_UNARY(std::find(intitules.begin(), intitules.end(), "Q1") != intitules.end());
            REQUIRE_UNARY(std::find(intitules.begin(), intitules.end(), "Q2") != intitules.end());
            REQUIRE_UNARY(std::find(intitules.begin(), intitules.end(), "Q3") != intitules.end());
        }
    }
}