#ifndef PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H
#define PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H

#include "evaluation.h"

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
    private:
        bool d_secondeChance, d_nbEssais; // booléen pour indiquer si la seconde chance a été utilisée ou pas
    };
} // test

#endif //PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H