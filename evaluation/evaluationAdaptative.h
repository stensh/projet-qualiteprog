#ifndef PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H
#define PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H

#include <set>
#include "evaluation.h"

/**
* Questions posées dans un ordre aléatoire
* Une question avec une mauvaise réponse sera reposée à la fin
*/

namespace test
{
    class evaluationAdaptative : public evaluation
    {
    public:
        // Constructeur
        evaluationAdaptative(const sujet::questionnaire& q);

        // Méthodes surchargées
        const std::unique_ptr<sujet::question>& questionCourante() const override;
        void reussiteCourante() override;
        void echecCourant() override;
        bool resteQuestions() const override;
        bool afficherBonneReponse() const override;
        void questionSuivante() override;
        double resultats() const override;

        // Méthodes propres à la classe
        void marquerEchec();

        void incrementeNbEssais();

    private:
        int d_nbEssais, d_positionOrdre;
        std::vector<int> d_ordreQuestions;
        std::set<int> d_questionsAjouteesPourReprise; // Questions déjà ajoutées pour reprise
        bool d_phaseReprise; // Indique si on est dans la phase de reprise des questions échouées
        bool d_terminerApresReprise; // Indique qu'on doit terminer après avoir reposé toutes les questions

        void melangerQuestions(); // Mélanger l'ordre des questions
    };
}

#endif //PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H
