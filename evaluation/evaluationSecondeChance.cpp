#include "evaluationSecondeChance.h"

namespace test
{
    evaluationSecondeChance::evaluationSecondeChance(const sujet::questionnaire &q)
        : evaluation{q}, d_reposees{}, d_tentativesQuestion{}, d_indiceListe{0}
    {
        for (int i = 0; i < nbQuestions(); ++i)
        {
            d_reposees.push_back(questionCourante());
            // TODO problème pour remplir le tableau ici (pourquoi on le remplit ?)
            d_tentativesQuestion[i] = 0;
            // TODO à quoi sert le map concrètement ?
        }
    }

    bool evaluationSecondeChance::resteQuestions() const
    {
        return nbQuestions() + d_reposees.size() - questionsPosees() > 0;
        // TODO revoir la logique (d_reposees contient uniquement les questions à reposer)
    }

    bool evaluationSecondeChance::afficherBonneReponse() const
    {
        if (d_indiceListe < d_reposees.size())
        {
            int indiceQuestion = d_reposees[d_indiceListe];
            auto it = d_tentativesQuestion.find(indiceQuestion);
            return it != d_tentativesQuestion.end() && it->second >= 2;
        }
        return false;
        // TODO revoir la logique
    }

    void evaluationSecondeChance::questionSuivante()
    {
        incrementeQuestionsPosees();
        ++d_indiceListe;
        incrementeIndiceCourant();
        // TODO à revoir niveau logique
    }

    double evaluationSecondeChance::resultats() const
    {
        if (nbQuestions() == 0) return 0.0;
        return bonnesReponses() * 20 / nbQuestions();
    }

    void evaluationSecondeChance::marquerEchec(int indice)
    {
        ++d_tentativesQuestion[indice];

        if (d_tentativesQuestion[indice] == 1)
        {
            d_reposees.push_back(questionCourante()); // TODO revoir la logique
        }
    }
}
