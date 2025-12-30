#include <string>
#include "../evaluation/testsDoctest/doctest.h"
#include "../questionnaire/questionnaire.h"
#include "../evaluation/evaluationSecondeChance.h"

TEST_CASE("L'évaluation seconde chance focntionne")
{
  sujet::questionnaire q{"fichierTest.txt"};
  test::evaluationSecondeChance e{q};
  SUBCASE("Reposer une question échoué fonctionne")
  {
    const std::string premiere_question = e.questionCourante()->contenu();
    e.marquerEchec();
    e.questionSuivante();
    REQUIRE_UNARY(e.resteQuestions());
    REQUIRE_EQ(e.questionCourante()->contenu(), premiere_question);
    REQUIRE_UNARY_FALSE(e.afficherBonneReponse());
  }
  SUBCASE("Le calcul des résultats fontionne")
  {
    SUBCASE("Aucun échec fonctionne"){
      double noteParfaite{20.0};
      e.incrementeBonnesReponses();
      e.incrementeQuestionsPosees();
      e.questionSuivante();
      REQUIRE_EQ(e.resultats(), noteParfaite);
    }
    SUBCASE("Le calcule avec un échec et un deuxième essai réussi fonctionne")
    {
      double notePasParfaite{15.0};
      e.marquerEchec();
      e.questionSuivante();
      e.incrementeBonnesReponses();
      e.questionSuivante();
      REQUIRE_EQ(e.resultats(), notePasParfaite);
    } 
    SUBCASE("Le calcule avec double échec fonctionne")
    {
      double noteNulle{0.0};
      e.marquerEchec();
      e.questionSuivante();
      e.marquerEchec();
      REQUIRE_UNARY(e.afficherBonneReponse());
      e.questionSuivante();
      REQUIRE_EQ(e.resultats(), noteNulle);
    }
  }
}
