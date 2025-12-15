#include "questionnaire/questionnaire.h"
#include "questionnaire/gestionnaireQuestionnaire.h"

namespace sujet
{
    questionnaire::questionnaire():
        d_nomFichier{}, d_questions{}
    {}

    questionnaire::questionnaire(const std::string& nomFichier):
        d_questions{}, d_nomFichier{nomFichier}
    {}

    const std::unique_ptr<question>& questionnaire::questionIndice(int indice) const
    {
        return d_questions[indice];
    }

    void questionnaire::ajouteQuestion(std::unique_ptr<question> q)
    {
        d_questions.push_back(std::move(q));
    }

    std::string questionnaire::nomFichier() const
    {
        return d_nomFichier;
    }

    int questionnaire::taille() const
    {
        return d_questions.size();
    }



}
