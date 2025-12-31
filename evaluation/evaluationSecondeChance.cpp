#include "evaluationSecondeChance.h"

namespace test
{
    evaluationSecondeChance::evaluationSecondeChance(const sujet::questionnaire &q)
        : evaluation{q}, d_positionCourante{0}, d_ordreQuestions{}, d_nbEssais{}, d_enSecondeTentative{false}
    {
        for (int i = 0; i < nbQuestions(); ++i)
        {
            d_ordreQuestions.push_back(i);
            d_nbEssais[i] = 0; // À l'origine tous les essais sont à 0
        }
    }

    const std::unique_ptr<sujet::question> &evaluationSecondeChance::questionCourante() const
    {
        int indiceReel = d_ordreQuestions[d_positionCourante];
        return questionnaireCourant().questionIndice(indiceReel);
    }

    void evaluationSecondeChance::reussiteCourante()
    {
        incrementeBonnesReponses();
        int indiceQuestion = d_ordreQuestions[d_positionCourante];
        ++d_nbEssais[indiceQuestion];
        d_enSecondeTentative = false;
    }

    void evaluationSecondeChance::echecCourant()
    {
        int indiceQuestion = d_ordreQuestions[d_positionCourante];
        ++d_nbEssais[indiceQuestion];
        d_nbEssais[indiceQuestion] == 1 ? d_enSecondeTentative = true : d_enSecondeTentative = false;
    }

    bool evaluationSecondeChance::resteQuestions() const
    {
        return d_positionCourante < d_ordreQuestions.size();
    }

    bool evaluationSecondeChance::afficherBonneReponse() const
    {
        if (d_positionCourante < d_ordreQuestions.size())
        {
            int indiceQuestion = d_ordreQuestions[d_positionCourante];
            return d_nbEssais.at(indiceQuestion) >= 2;
        }
        return false;
    }

    void evaluationSecondeChance::questionSuivante()
    {
        incrementeQuestionsPosees();
        if (!d_enSecondeTentative)
        {
            ++d_positionCourante;
        }
    }

    double evaluationSecondeChance::resultats() const
    {
        if (nbQuestions() == 0) return 0.0;
        return bonnesReponses() * 20.0 / nbQuestions();
    }
}
