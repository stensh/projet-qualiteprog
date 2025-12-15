#ifndef PROJET_QUALITEPROG_GESTIONNAIREEVALUATION_H
#define PROJET_QUALITEPROG_GESTIONNAIREEVALUATION_H

#include "evaluation.h"
#include "questionnaire/questionnaire.h"
#include "questionnaire/question.h"
#include "questionnaire/reponse.h"

namespace test
{
    class gestionnaireEvaluation
    {
    public:
        gestionnaireEvaluation() = default;
        ~gestionnaireEvaluation() = default;
        void commencerEvaluation(evaluation& eval) const;
        void commencerEvaluation(evaluation& eval, std::istream& ist, std::ostream& ost) const;
    private:
        std::string lireReponse(std::istream& ist, std::ostream& ost) const;
        void traiterReponse(const sujet::question& q, reponse& rep) const;
        void instructionsReponseValide(evaluation& eval, std::ostream& ost) const;
        void instructionsReponseInvalide(evaluation& eval, std::ostream& ost) const;
        void afficherCorrectionSecondeChance(const evaluation& eval, const sujet::question& q, std::ostream& ost) const;
        void afficherResultats(evaluation& eval, std::ostream& ost) const;
    };
}

#endif //PROJET_QUALITEPROG_GESTIONNAIREEVALUATION_H