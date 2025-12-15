#ifndef PROJET_QUALITEPROG_GESTIONNAIREEVALUATION_H
#define PROJET_QUALITEPROG_GESTIONNAIREEVALUATION_H

#include <memory>
#include "evaluation.h"
#include "questionnaire/questionnaire.h"
#include "questionnaire/question.h"
#include "questionnaire/reponse.h"

namespace test
{
    class gestionnaireEvaluation
    {
    public:
        gestionnaireEvaluation(); // = default ? ou des choses à faire ?
        ~gestionnaireEvaluation();
        void commencerEvaluation(std::unique_ptr<evaluation> eval) const;
        void commencerEvaluation(std::unique_ptr<evaluation> eval, std::istream& ist, std::ostream& ost) const;
    private:
        std::string lireReponse(std::istream& ist, std::ostream& ost) const;
        void traiterReponse(const std::unique_ptr<sujet::question> q, reponse& rep) const;
        void afficherCorrectionSecondeChance(std::unique_ptr<evaluation> eval, std::unique_ptr<sujet::question> q, std::ostream& ost) const;
        void afficherResultats(std::unique_ptr<evaluation> eval, std::ostream& ost) const;
    };
}

#endif //PROJET_QUALITEPROG_GESTIONNAIREEVALUATION_H