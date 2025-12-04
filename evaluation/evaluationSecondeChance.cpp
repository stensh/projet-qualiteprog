#include "evaluationSecondeChance.h"

namespace test
{
    evaluationSecondeChance::evaluationSecondeChance(const sujet::questionnaire &q)
        : evaluation{q}
    {}

    bool evaluationSecondeChance::resteQuestions() const
    {
        return nbQuestions() + d_reposees.size() - questionsPosees() > 0;
    }

    bool evaluationSecondeChance::afficherBonneReponse() const
    {
        // comment gérer la seconde chance pour chaque question ? tableau de booléens ?
    }

    void evaluationSecondeChance::questionSuivante()
    {
        if (d_secondeChance)
        {
            d_reposees.push_back(std::move(questionCourante()));
        }

        incrementeIndiceCourant();
        incrementeQuestionsPosees(); // à faire au moment de poser la question, gestionnaireEvaluation ?
    }

    double evaluationSecondeChance::resultats() const
    {
        return 5;
    }
}
