#include "questionnaire.h"
#include "gestionnaireQuestionnaire.h"

namespace sujet
{


questionnaire::questionnaire(const std::string& nomFichier):
    d_questions{}, d_nomFichier{nomFichier}
{}

question& questionnaire::questionCourante(int indice) const
{
    return *d_questions[indice];
}

void questionnaire::ajouteQuestion(std::unique_ptr<question> q)
{
    d_questions.push_back(std::move(q));
}

std::string questionnaire::nomFichier() const
{
    return d_nomFichier;
}
int questionnaire::nombreQuestions() const
{
    return d_questions.size();
}



}
