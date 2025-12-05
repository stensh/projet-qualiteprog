#include "questionnaire.h"
#include "gestionnaireQuestionnaire.h"

namespace sujet
{
    questionnaire::questionnaire(std::string& nomFichier):
        d_questions{}, d_nomFichier{nomFichier}
    {}

    void questionnaire::ajouteQuestion(std::unique_ptr<question> q)
    {
        d_questions.push_back(std::move(q));
    }

    const std::unique_ptr<question>& questionnaire::questionIndice(int indice) const
    {
        return d_questions[indice];
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
