#ifndef PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H
#define PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H

/**
* Questions posées dans un ordre aléatoire
* Une question avec une mauvaise réponse sera reposée à la fin
*/

namespace test
{
    class evaluationAdaptative
    {
    public:
        evaluationAdaptative();
        double resultats() const override;
    private:
        int d_nbEssais;
    };
} // test

#endif //PROJET_QUALITEPROG_EVALUATIONADAPTATIVE_H
