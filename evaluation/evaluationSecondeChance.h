#ifndef PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H
#define PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H

#include <vector>
#include <memory>
#include "evaluation.h"

/**
* On repose la question une deuxième fois si elle n'est pas réussie du premier coup
* Si on échoue encore, on affiche la bonne réponse
*/

namespace test
{
    class evaluationSecondeChance : public evaluation
    {
    public:
        evaluationSecondeChance(const sujet::questionnaire& q);

        bool resteQuestions() const override;
        bool afficherBonneReponse() const override;
        void questionSuivante() override;
        double resultats() const override;
    private:
        bool d_secondeChance, d_nbEssais; // booléen pour indiquer si la seconde chance a été utilisée ou pas
        std::vector<std::unique_ptr<sujet::question>> d_reposees;
    };
}

#endif //PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H
