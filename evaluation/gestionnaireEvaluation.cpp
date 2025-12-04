#include <iostream>
#include "gestionnaireEvaluation.h"
#include "questionnaire/reponse.h"

namespace test {
    gestionnaireEvaluation::gestionnaireEvaluation()
    {}

    gestionnaireEvaluation::~gestionnaireEvaluation()
    {}

    void gestionnaireEvaluation::commencerEvaluation(questionnaire* quest, std::unique_ptr<evaluation>& eval) const
    {
        while (eval->resteQuestions())
        {
            std::string donnee("");
            auto q = eval->questionCourante();
            std::cout << q.contenu() << std::endl;
            std::cin >> donnee;
            reponse rep{donnee};

            if (q.reponseJuste(rep))
            {
                eval->incrementeBonnesReponses();
            }

            if (eval->afficherBonneReponse())
            {
                std::cout << q.afficherBonnesReponse();
            }

            eval->questionSuivante();
        }
    }
} // test