#include <iostream>
#include "gestionnaireEvaluation.h"

#include "evaluationAdaptative.h"
#include "evaluationSecondeChance.h"
#include "questionnaire/reponse.h"

namespace test
{
    gestionnaireEvaluation::gestionnaireEvaluation()
    {}

    gestionnaireEvaluation::~gestionnaireEvaluation()
    {}

    // TODO séparer la fonction en plusieurs petites
    void gestionnaireEvaluation::commencerEvaluation(std::unique_ptr<evaluation>& eval) const
    {
        // Pointeur vérifiant le type dynamique
        auto* evalSeconde = dynamic_cast<*evaluationSecondeChance>(eval.get());
        auto* evalAdapt = dynamic_cast<*evaluationAdaptative>(eval.get());

        while (eval->resteQuestions())
        {
            std::string donnee("");
            const auto& q = eval->questionCourante();

            std::cout << q->contenu() << std::endl;
            std::cout << "Entrez votre réponse : "; // TODO gérer les accents
            std::getline(std::cin, donnee); // on utilise un getline pour avoir toute la ligne
            reponse rep{donnee};

            // TODO utiliser la classe réponse ici
            if (q->reponseJuste(donnee))
            {
                eval->incrementeBonnesReponses();
                std::cout << "Bonne réponse !" << std::endl;

                if (evalSeconde)
                    evalSeconde->marquerReussite(); // TODO manque l'indice courant
            }
            else
            {
                std::cout << "Mauvaise réponse." << std::endl;

                if (evalSeconde) {
                    evalSeconde->marquerEchec();
                }
                else if (evalAdapt) {
                    evalAdapt->marquerEchec();
                }
            }

            if (eval->afficherBonneReponse())
            {
                std::cout << q->reponse() << std::endl; // TODO fonction virtuelle dans question.h faite par Surab et Quentin
            }

            eval->questionSuivante();
        }
        std::cout << std::endl << "=== RÉSULTATS ===" << std::endl;
        std::cout << "Note finale : " << eval->resultats() << "/20" << std::endl;
        std::cout << "Bonnes réponses : " << eval->bonnesReponses() << '/' << eval->nbQuestions() << std::endl;
    }
}