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
        void commencer() const override;
    };
} // test

#endif //PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H