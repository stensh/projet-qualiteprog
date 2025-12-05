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

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // heure actuelle convertie en nombre
        std::shuffle(d_ordreQuestions.begin(), d_ordreQuestions.end(),
                     std::default_random_engine(seed));
        // On utilise un seed basé sur le temps pour que le mélange soit aléatoire
    }

    const std::unique_ptr<sujet::question> &evaluationAdaptative::questionCourante() const
    {
        int indiceReel{d_ordreQuestions[d_positionOrdre]}; // retrouve l'indice réel de la question
        return questionnaire().questionIndice(indiceReel);
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

    double evaluationAdaptative::resultats() const // TODO mettre ça dans une fonction commune non ?
    {
        if (d_nbEssais == 0) return 0.0;
        return bonnesReponses() * 20.0 / d_nbEssais;
    }


    void evaluationAdaptative::marquerEchec()
    {
        d_ordreQuestions.push_back(d_ordreQuestions[d_positionOrdre]);
    }

}