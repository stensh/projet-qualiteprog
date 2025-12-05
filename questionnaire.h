#ifndef PROJET_QUALITEPROG_QUESTIONNAIRE_H
#define PROJET_QUALITEPROG_QUESTIONNAIRE_H

#include <memory>
#include <vector>
#include <fstream>
#include "question.h"


namespace sujet
{

class questionnaire
{
    public:
        questionnaire(const std::string& nomFichier);
        ~questionnaire() = default ;


        question& questionCourante(int indice) const;    //Renvoie la question demandée indice.

        void ajouteQuestion(std::unique_ptr<question> q);
        std::string nomFichier() const;
        int nombreQuestions() const;

    private:
        std::vector<std::unique_ptr<question>> d_questions; //Stock les différentes questions du questionnaire
        std::string d_nomFichier;


};

}
#endif //PROJET_QUALITEPROG_QUESTIONNAIRE_H