#include <string>
#include "doctest.h"
#include "../questionnaire/questionnaire.h"
#include "../questionnaire/questionTexte.h"
#include "../evaluation/evaluationSecondeChance.h"

TEST_CASE("L'évaluation seconde chance fonctionne")
{
  sujet::questionnaire q{""};

  q.ajouteQuestion(
      std::make_unique<sujet::questionTexte>(
          "Capitales",
          "Quelle est la capitale de la France ?",
          "Paris"
      )
  );

  test::evaluationSecondeChance e{q};

  SUBCASE("Reposer une question échouée fonctionne")
  {
    const std::string premiere_question = e.questionCourante()->contenu();
    e.echecCourant();
    e.questionSuivante();
    REQUIRE_UNARY(e.resteQuestions());
    REQUIRE_EQ(e.questionCourante()->contenu(), premiere_question);
    REQUIRE_UNARY_FALSE(e.afficherBonneReponse());
  }

  SUBCASE("Le calcul des résultats fontionne")
  {
    SUBCASE("Aucun échec fonctionne")
    {
      double noteParfaite{20.0};
      e.incrementeBonnesReponses();
      e.incrementeQuestionsPosees();
      e.questionSuivante();
      REQUIRE_EQ(e.resultats(), noteParfaite);
    }

    SUBCASE("Le calcule avec un échec et un deuxième essai réussi fonctionne")
    {
      double notePasParfaite{15.0};
      e.echecCourant();
      e.questionSuivante();
      e.reussiteCourante();
      e.questionSuivante();
      REQUIRE_EQ(e.resultats(), notePasParfaite);
    }

    SUBCASE("Le calcule avec double échec fonctionne")
    {
      double noteNulle{0.0};
      e.echecCourant();
      e.questionSuivante();
      e.echecCourant();
      REQUIRE_UNARY(e.afficherBonneReponse());
      e.questionSuivante();
      REQUIRE_EQ(e.resultats(), noteNulle);
    }

    SUBCASE("Marquer la réussite ou l'échec fonctionne")
    {
      SUBCASE("Incrémenter les bonnes réponses et marque la réussite fonctionne")
      {
        REQUIRE_EQ(e.bonnesReponses(), 0);
        e.reussiteCourante();
        REQUIRE_EQ(e.bonnesReponses(), 1);
      }

      SUBCASE("Marquer l'échec sans incrémenter les bonnes réponses fonctionne")
      {
        REQUIRE_EQ(e.bonnesReponses(), 0);
        e.echecCourant();
        REQUIRE_EQ(e.bonnesReponses(), 0);
      }
    }

    SUBCASE("La logique de réussite fonctionne")
    {
      e.reussiteCourante();
      e.questionSuivante();
      // Après une réussite, on passe à la question suivante (ou on termine si c'était la dernière)
      // Pour une seule question, après réussite et questionSuivante, il ne reste plus de questions
      REQUIRE_UNARY_FALSE(e.resteQuestions());
    }

    SUBCASE("La logique d'échec fonctionne")
    {
      const std::string question_avant = e.questionCourante()->contenu();
      e.echecCourant();
      e.questionSuivante();
      // Après un premier échec, la question doit être reposée (on reste sur la même)
      REQUIRE_UNARY(e.resteQuestions());
      REQUIRE_EQ(e.questionCourante()->contenu(), question_avant);
    }
  }
}
