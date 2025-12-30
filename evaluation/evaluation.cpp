#include "evaluation.h"

namespace test
{
    evaluation::evaluation(const sujet::questionnaire& q)
        : d_questionnaire{q}, d_nbBonnesReponses{0}, d_nbQuestionsPosees{0}
    {}

    int evaluation::bonnesReponses() const
    {
        return d_nbBonnesReponses;
    }

    int evaluation::nbQuestions() const
    {
        return d_questionnaire.taille();
    }

    int evaluation::questionsPosees() const
    {
        return d_nbQuestionsPosees;
    }

    void evaluation::incrementeBonnesReponses()
    {
        ++d_nbBonnesReponses;
    }

    void evaluation::incrementeQuestionsPosees()
    {
        ++d_nbQuestionsPosees;
    }

    const sujet::questionnaire &evaluation::questionnaireCourant() const
    {
        return d_questionnaire;
    }

}