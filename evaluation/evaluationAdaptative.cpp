#include <random>
#include "evaluationAdaptative.h"

namespace test
{
    evaluationAdaptative::evaluationAdaptative(const sujet::questionnaire &q)
        : evaluation{q}, d_ordreQuestions{}, d_positionOrdre{0}, d_nbEssais{0}
    {
        melangerQuestions();
    }

    void evaluationAdaptative::melangerQuestions()
    {
        for (int i = 0; i < nbQuestions(); ++i)
        {
            d_ordreQuestions.push_back(i);
        }

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(d_ordreQuestions.begin(), d_ordreQuestions.end(), g);
        // TODO est-ce que le mélange est vraiment aléatoire à chaque itération ?
    }

    bool evaluationAdaptative::resteQuestions() const
    {
        return d_positionOrdre < d_ordreQuestions.size();
    }

    bool evaluationAdaptative::afficherBonneReponse() const
    {
        // TODO lire l'énoncé
    }

    void evaluationAdaptative::questionSuivante()
    {
        incrementeQuestionsPosees();
        ++d_nbEssais;
        ++d_positionOrdre;
    }

    double evaluationAdaptative::resultats() const
    {
        if (d_nbEssais == 0) return 0.0;
        return bonnesReponses() * 20 / d_nbEssais;
    }


    void evaluationAdaptative::marquerEchec()
    {
        if (d_positionOrdre < d_ordreQuestions.size())
        {
            d_ordreQuestions.push_back(d_ordreQuestions[d_positionOrdre]);
        }
    }

}