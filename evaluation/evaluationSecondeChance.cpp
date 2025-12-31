#include "evaluationSecondeChance.h"

namespace test
{
    evaluationSecondeChance::evaluationSecondeChance(const sujet::questionnaire &q)
        : evaluation{q}, d_positionCourante{0}, d_toutesLesQuestions{}, d_nbEssais{}
    {
        for (int i = 0; i < nbQuestions(); ++i)
        {
            d_toutesLesQuestions.push_back(i);
            d_nbEssais[i] = 0; // À l'origine tous les essais sont à 0
        }
    }

    const std::unique_ptr<sujet::question> &evaluationSecondeChance::questionCourante() const
    {
        int indiceReel = d_toutesLesQuestions[d_positionCourante];
        return questionnaireCourant().questionIndice(indiceReel);
    }

    void evaluationSecondeChance::reussiteCourante()
    {
        incrementeBonnesReponses();
        marquerReussite();
    }

    void evaluationSecondeChance::echecCourant()
    {
        marquerEchec();
    }

    bool evaluationSecondeChance::resteQuestions() const
    {
        return d_positionCourante < d_toutesLesQuestions.size();
    }

    bool evaluationSecondeChance::afficherBonneReponse() const
    {
        if (d_positionCourante < d_toutesLesQuestions.size())
        {
            int indiceQuestion = d_toutesLesQuestions[d_positionCourante];
            return d_nbEssais.at(indiceQuestion) >= 2;
        }
        return false;
    }

    void evaluationSecondeChance::questionSuivante()
    {
        incrementeQuestionsPosees();
        ++d_positionCourante;
    }

    double evaluationSecondeChance::resultats() const
    {
        if (nbQuestions() == 0) return 0.0;
        return bonnesReponses() * 20.0 / nbQuestions();
    }

    void evaluationSecondeChance::marquerReussite()
    {
        int indiceQuestion = d_toutesLesQuestions[d_positionCourante];
        ++d_nbEssais[indiceQuestion];
    }

    void evaluationSecondeChance::marquerEchec()
    {
        int indiceQuestion = d_toutesLesQuestions[d_positionCourante];
        ++d_nbEssais[indiceQuestion];

        if (d_nbEssais[indiceQuestion] == 1)
        {
            d_toutesLesQuestions.push_back(indiceQuestion);
        }
    }
}
