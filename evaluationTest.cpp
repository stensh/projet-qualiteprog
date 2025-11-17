#include "evaluationTest.h"

namespace test
{
    evaluationTest::evaluationTest();


    void evaluation::commencer(const int /*Questionnaire&*/ q) const override
    {
        
    } 

  bool resteQuestions() const override
  {
    return d_index<static_cast<int>(d_questionsRestante.size());
  }
              
  int /*plutôt Question*/ & questionCourante() override
  {
    return *d_question[d_index];
  }
  
  void questionSuivante() override
  {
    d_index ++;
  }
  
  void afficherResultats();
} // test
