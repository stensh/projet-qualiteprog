#include <random>
#include <chrono>
#include <algorithm>
#include <set>
#include "evaluationAdaptative.h"

namespace test
{
    evaluationAdaptative::evaluationAdaptative(const sujet::questionnaire &q)
        : evaluation{q}, d_nbEssais{0}, d_positionOrdre{0}, d_ordreQuestions{}, d_questionsAjouteesPourReprise{},
        d_phaseReprise{false}, d_terminerApresReprise{false}
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
        // On utilise une seed basée sur le temps pour que le mélange soit aléatoire
    }

    const std::unique_ptr<sujet::question> &evaluationAdaptative::questionCourante() const
    {
        int indiceReel{d_ordreQuestions[d_positionOrdre]}; // retrouve l'indice réel de la question
        return questionnaireCourant().questionIndice(indiceReel);
    }

    void evaluationAdaptative::reussiteCourante()
    {
        incrementeBonnesReponses();
        if (d_phaseReprise && d_positionOrdre < static_cast<int>(d_ordreQuestions.size()))
        {
            int indiceQuestion = d_ordreQuestions[d_positionOrdre];
            d_questionsAjouteesPourReprise.erase(indiceQuestion);
        }
    }

    void evaluationAdaptative::echecCourant()
    {
        if (d_phaseReprise)
        {
            d_terminerApresReprise = true;

            if (d_positionOrdre < d_ordreQuestions.size())
            {
                int indiceQuestion = d_ordreQuestions[d_positionOrdre];
                d_questionsAjouteesPourReprise.erase(indiceQuestion);
            }
        }
        else
        {
            marquerEchec();
        }
    }

    bool evaluationAdaptative::resteQuestions() const
    {
        if (d_terminerApresReprise && d_questionsAjouteesPourReprise.empty())
        {
            return false;
        }
        return d_positionOrdre < d_ordreQuestions.size();
    }

    bool evaluationAdaptative::afficherBonneReponse() const
    {
        return false;
    }

    void evaluationAdaptative::questionSuivante()
    {
        incrementeQuestionsPosees();
        ++d_nbEssais;
        ++d_positionOrdre;
        
        if (!d_phaseReprise && d_positionOrdre >= nbQuestions())
        {
            d_phaseReprise = true;
        }
        
        if (d_terminerApresReprise && d_questionsAjouteesPourReprise.empty() && d_positionOrdre < d_ordreQuestions.size())
        {
            d_ordreQuestions.erase(d_ordreQuestions.begin() + d_positionOrdre, d_ordreQuestions.end());
        }
    }

    double evaluationAdaptative::resultats() const
    {
        if (d_nbEssais == 0) return 0.0;
        return bonnesReponses() * 20.0 / d_nbEssais;
    }

    void evaluationAdaptative::marquerEchec()
    {
        if (d_positionOrdre < static_cast<int>(d_ordreQuestions.size()))
        {
            int indiceQuestion = d_ordreQuestions[d_positionOrdre];
            
            // ajouter la question à la fin seulement si elle n'a pas déjà été ajoutée
            if (d_questionsAjouteesPourReprise.find(indiceQuestion) == d_questionsAjouteesPourReprise.end())
            {
                d_ordreQuestions.push_back(indiceQuestion);
                d_questionsAjouteesPourReprise.insert(indiceQuestion);
            }
        }
    }

}
