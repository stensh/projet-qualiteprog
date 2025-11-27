#include "evaluationTest.h"

namespace test
{
    evaluationTest::evaluationTest();


  bool resteQuestions() const override
  {
    return d_index<static_cast<int>(d_questionsRestante.size());
  }

  void questionSuivante() override
  {
    d_index ++;
  }
  
  void afficherResultats();
} // test
