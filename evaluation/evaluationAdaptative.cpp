#include <random>
#include <chrono>
#include <algorithm>
#include <set>
#include "evaluationAdaptative.h"

namespace test
{
    evaluationAdaptative::evaluationAdaptative(const sujet::questionnaire &q)
        : evaluation{q}, d_nbEssais{0}, d_positionOrdre{0}, d_ordreQuestions{}, d_questionsAjouteesPourReprise{}, d_phaseReprise{false}
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
        return questionnaireCourant().questionIndice(indiceReel);
    }

    void evaluationAdaptative::reussiteCourante()
    {
        incrementeBonnesReponses();
        // Si on était en phase de reprise et qu'on réussit, on retire la question du set
        if (d_phaseReprise && d_positionOrdre < static_cast<int>(d_ordreQuestions.size()))
        {
            int indiceQuestion = d_ordreQuestions[d_positionOrdre];
            d_questionsAjouteesPourReprise.erase(indiceQuestion);
        }
    }

    void evaluationAdaptative::echecCourant()
    {
        // Si on est en phase de reprise et qu'on échoue, on termine l'évaluation
        if (d_phaseReprise)
        {
            // Vider l'ordre des questions restantes pour que resteQuestions() retourne false
            d_ordreQuestions.erase(d_ordreQuestions.begin() + d_positionOrdre, d_ordreQuestions.end());
        }
        else
        {
            marquerEchec();
        }
    }

    bool evaluationAdaptative::resteQuestions() const
    {
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
        
        // Si toutes les questions initiales ont été posées on passe en phase de reprise
        if (!d_phaseReprise && d_positionOrdre >= nbQuestions())
        {
            d_phaseReprise = true;
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
            
            // Ajouter la question à la fin seulement si elle n'a pas déjà été ajoutée
            if (d_questionsAjouteesPourReprise.find(indiceQuestion) == d_questionsAjouteesPourReprise.end())
            {
                d_ordreQuestions.push_back(indiceQuestion);
                d_questionsAjouteesPourReprise.insert(indiceQuestion);
            }
        }
    }

}
