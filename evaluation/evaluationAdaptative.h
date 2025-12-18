#ifndef PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H
#define PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H

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

    private:
        int d_nbEssais, d_positionOrdre;
        std::vector<int> d_ordreQuestions;

        void melangerQuestions(); // Mélanger l'ordre des questions
    };
}

#endif //PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H
