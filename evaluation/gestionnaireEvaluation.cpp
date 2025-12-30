#include <iostream>
#include "gestionnaireEvaluation.h"
#include "questionnaire/reponse.h"

namespace test
{
    void gestionnaireEvaluation::commencerEvaluation(evaluation& eval) const
    {
        commencerEvaluation(eval, std::cin, std::cout);
    }

    void gestionnaireEvaluation::commencerEvaluation(evaluation& eval, std::istream& ist, std::ostream& ost) const
    {
        while (eval.resteQuestions())
        {
            const auto& q = *eval.questionCourante(); // à revoir
            ost << q.contenu() << std::endl;

            std::string donnee = lireReponse(ist, ost);
            reponse rep{donnee};
            traiterReponse(q, rep);

            rep.valide() ? instructionsReponseValide(eval, ost) : instructionsReponseInvalide(eval, ost);

            afficherCorrectionSecondeChance(eval, q, ost);
            eval.questionSuivante();
        }
        afficherResultats(eval, ost);
    }

    std::string gestionnaireEvaluation::lireReponse(std::istream& ist, std::ostream& ost) const
    {
        std::string donnee("");
        ost << "Entrez votre réponse : ";
        std::getline(ist, donnee);
        return donnee;
    }

    void gestionnaireEvaluation::traiterReponse(const sujet::question& q, reponse &rep) const
    {
        rep.changeValidite(q.reponseJuste(rep.donnee()));
    }

    void gestionnaireEvaluation::instructionsReponseValide(evaluation &eval, std::ostream &ost) const
    {
        ost << "Bonne réponse !" << std::endl;
        eval.reussiteCourante();
    }

    void gestionnaireEvaluation::instructionsReponseInvalide(evaluation& eval, std::ostream& ost) const
    {
        ost << "Mauvaise réponse." << std::endl;
        eval.echecCourant();
    }

    void gestionnaireEvaluation::afficherCorrectionSecondeChance(const evaluation& eval, const sujet::question& q, std::ostream& ost) const
    {
        if (eval.afficherBonneReponse())
        {
            ost << q.reponse() << std::endl; // TODO fonction virtuelle dans question.h faite par Surab et Quentin
        }
    }

    void gestionnaireEvaluation::afficherResultats(evaluation& eval, std::ostream &ost) const
    {
        ost << std::endl << "=== RÉSULTATS ===" << std::endl;
        ost << "Note finale : " << eval.resultats() << "/20" << std::endl;
        ost << "Bonnes réponses : " << eval.bonnesReponses() << '/' << eval.nbQuestions() << std::endl;
    }

}