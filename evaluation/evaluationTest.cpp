#include "evaluationTest.h"

namespace test
{
    evaluationTest::evaluationTest();

    bool evaluationTest::afficherBonneReponse() const
    {
        return false;
    }

  bool evaluationTest::resteQuestions() const override
  {
    return d_index<static_cast<int>(d_questionsRestante.size());
  }

  void evaluationTest::questionSuivante() override
  {
    d_index ++;
  }
  
  double evaluationTest::resultats() const
{
    return d_nbBonnesReponses * 1.0;
} // test
