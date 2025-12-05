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
        bool resteQuestions() const override;
        bool afficherBonneReponse() const override; // Affichage au bout du deuxième échec
        void questionSuivante() override;
        double resultats() const override;

        // Méthodes propres à la classe
        void marquerEchec(int indice);
    private:
        int d_indiceListe; // position actuelle dans la liste des questions (même chose que d_indiceCourant dans question.h ?)
        bool d_secondeChance, d_nbEssais; // booléen pour indiquer si la seconde chance a été utilisée ou pas
        std::vector<std::unique_ptr<sujet::question>> d_reposees;
        std::map<int, int> d_tentativesQuestion; // Nombre de tentatives par question
        // TODO revoir le type du map (question est une classe abstraite)
    };
}

#endif //PROJET_QUALITEPROG_EVALUATIONSECONDECHANCE_H
