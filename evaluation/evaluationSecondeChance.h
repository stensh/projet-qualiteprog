#ifndef PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H
#define PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H

#include <vector>
#include <memory>
#include "evaluation.h"

class question;

/**
* On repose la question une deuxième fois si elle n'est pas réussie du premier coup
* Si on échoue encore, on affiche la bonne réponse
*/

namespace test
{
    class evaluationSecondeChance
    {
    public:
        evaluationSecondeChance();
        bool afficherBonneReponse() const override;
        double resultats() const override;
        void questionSuivante() override;
    private:
        bool d_secondeChance, d_nbEssais; // booléen pour indiquer si la seconde chance a été utilisée ou pas
        std::vector<std::unique_ptr<question>> d_reposees;
    };
} // test

#endif //PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H
