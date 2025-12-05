#include "evaluation.h"

namespace test
{
    evaluation::evaluation(const sujet::questionnaire& q)
        : d_questionnaire{q}, d_indiceCourant{0}, d_nbBonnesReponses{0}, d_nbQuestionsPosees{0}
    {}

    int evaluation::indiceCourant() const
    {
        return d_indiceCourant;
    }

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

    void evaluation::incrementeIndiceCourant()
    {
        ++d_indiceCourant;
    }

    const std::unique_ptr<sujet::question>& evaluation::questionCourante() const
    {
        return d_questionnaire.questionIndice(d_indiceCourant);
    }
}