#ifndef PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H
#define PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H

#include <vector>
#include <memory>
#include <map>
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
        // Constructeur
        evaluationSecondeChance(const sujet::questionnaire& q);

        // Méthodes surchargées
        const std::unique_ptr<sujet::question>& questionCourante() const override;
        bool resteQuestions() const override;
        bool afficherBonneReponse() const override; // Affichage au bout du deuxième échec
        void questionSuivante() override;
        double resultats() const override;

        // Méthodes propres à la classe
        void marquerReussite(int indice);
        void marquerEchec(int indice);
    private:
        int d_positionCourante; // Position actuelle dans le tableau d'indices
        std::vector<int> d_toutesLesQuestions; // Indices de toutes les questions (du questionnaire et reposées)
        std::map<int, int> d_nbEssais; // Clé entre l'indice de la question et le nombre d'essais
    };
}

#endif //PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H
