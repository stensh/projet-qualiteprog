#include <sstream>
#include "doctest.h"
#include "../questionnaire/questionnaire.h"
#include "../questionnaire/questionTexte.h"
#include "../questionnaire/questionNumerique.h"
#include "../questionnaire/questionChoixMultiples.h"
#include "../evaluation/evaluationTest.h"
#include "../evaluation/evaluationSecondeChance.h"
#include "../evaluation/evaluationAdaptative.h"
#include "../evaluation/gestionnaireEvaluation.h"

TEST_CASE("Le gestionnaire d'évaluation fonctionne")
{
    sujet::questionnaire q{""};

    q.ajouteQuestion(
        std::make_unique<sujet::questionTexte>(
            "Capitales",
            "Quelle est la capitale de la France ?",
            "Paris"
        )
    );

    test::gestionnaireEvaluation ge;

    SUBCASE("Les réponses d'une évaluation test fonctionnent")
    {
        test::evaluationTest eval{q};
        std::ostringstream sortie;

        SUBCASE("Une réponse correcte fonctionne")
        {
            std::istringstream entree("Paris\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 1);
            REQUIRE_EQ(eval.questionsPosees(), 1);
        }

        SUBCASE("Une mauvaise réponse fonctionne")
        {
            std::istringstream entree("Mulhouse\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 0);
            REQUIRE_EQ(eval.questionsPosees(), 1);
        }
    }

    SUBCASE("Les réponses d'une évaluation seconde chance fonctionnent")
    {
        test::evaluationSecondeChance eval{q};
        std::ostringstream sortie;

        SUBCASE("Un échec, puis une réussite à la deuxième tentative fonctionne")
        {
            std::istringstream entree("Mulhouse\nParis\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 1);
            REQUIRE_EQ(eval.questionsPosees(), 2);
        }

        SUBCASE("Un double échec fonctionne")
        {
            std::istringstream entree("Mulhouse\nStrasbourg\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 0);
            REQUIRE_EQ(eval.questionsPosees(), 2);
            REQUIRE_UNARY(sortie.str().find("Paris") != std::string::npos); // teste l'affichage en sortie
        }
    }

    SUBCASE("Les réponses d'une évaluation adaptative fonctionnent")
    {
        test::evaluationAdaptative eval{q};
        std::ostringstream sortie;

        SUBCASE("Aucun échec fonctionne")
        {
            std::istringstream entree("Paris\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 1);
            REQUIRE_EQ(eval.questionsPosees(), 1);
        }

        SUBCASE("Un échec puis une réussite fonctionne")
        {
            std::istringstream entree("Mulhouse\nParis\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 1);
            REQUIRE_EQ(eval.questionsPosees(), 2);
        }
    }
    
    SUBCASE("Test avec question numérique")
    {
        sujet::questionnaire qNum{""};
        qNum.ajouteQuestion(std::make_unique<sujet::questionNumerique>("Q1", "Question numerique", 10, 20));
        
        test::evaluationTest eval{qNum};
        std::ostringstream sortie;
        
        SUBCASE("Question numérique avec réponse valide")
        {
            std::istringstream entree("15\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 1);
            REQUIRE_UNARY(sortie.str().find("Bonne réponse") != std::string::npos);
        }
        
        SUBCASE("Question numérique avec réponse invalide")
        {
            std::istringstream entree("25\n");
            test::evaluationTest eval2{qNum};
            ge.commencerEvaluation(eval2, entree, sortie);
            REQUIRE_EQ(eval2.bonnesReponses(), 0);
            REQUIRE_UNARY(sortie.str().find("Mauvaise réponse") != std::string::npos);
        }
    }
    
    SUBCASE("Test avec question à choix multiples")
    {
        sujet::questionnaire qQCM{""};
        qQCM.ajouteQuestion(std::make_unique<sujet::questionChoixMultiples>("Q1", "Question choix multiples\nChoix 1\nChoix 2\nChoix 3\nChoix 4", 2));
        
        test::evaluationTest eval{qQCM};
        std::ostringstream sortie;
        
        SUBCASE("Question à choix multiples avec bonne réponse")
        {
            std::istringstream entree("2\n");
            ge.commencerEvaluation(eval, entree, sortie);
            REQUIRE_EQ(eval.bonnesReponses(), 1);
            REQUIRE_UNARY(sortie.str().find("Bonne réponse") != std::string::npos);
        }
        
        SUBCASE("Question à choix multiples avec mauvaise réponse")
        {
            std::istringstream entree("3\n");
            test::evaluationTest eval2{qQCM};
            ge.commencerEvaluation(eval2, entree, sortie);
            REQUIRE_EQ(eval2.bonnesReponses(), 0);
            REQUIRE_UNARY(sortie.str().find("Mauvaise réponse") != std::string::npos);
        }
    }
    
    SUBCASE("Test de l'affichage des résultats")
    {
        sujet::questionnaire q{""};
        q.ajouteQuestion(std::make_unique<sujet::questionTexte>("Q1", "Question 1", "R1"));
        q.ajouteQuestion(std::make_unique<sujet::questionTexte>("Q2", "Question 2", "R2"));
        
        test::evaluationTest eval{q};
        std::ostringstream sortie;
        std::istringstream entree("R1\nR2\n");
        
        ge.commencerEvaluation(eval, entree, sortie);
        
        std::string sortieStr = sortie.str();
        REQUIRE_UNARY(sortieStr.find("RÉSULTATS") != std::string::npos);
        REQUIRE_UNARY(sortieStr.find("Nombre de questions") != std::string::npos);
        REQUIRE_UNARY(sortieStr.find("Nombre d'essais") != std::string::npos);
        REQUIRE_UNARY(sortieStr.find("Nombre de bonnes réponses") != std::string::npos);
        REQUIRE_UNARY(sortieStr.find("/20") != std::string::npos);
    }
}