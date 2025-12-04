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
        questionnaire(std::string& nomFichier);
        ~questionnaire();


        std::unique_ptr<question> questionCourante(int indice) const;
        int taille() const;

        void ajouteQuestion(std::unique_ptr<question>& q);
        std::string nomFichier() const;

    private:
        std::vector<std::unique_ptr<question>> d_questions; //Stock les différentes question du questionnaire
        std::string d_nomFichier;


};

}
#endif //PROJET_QUALITEPROG_QUESTIONNAIRE_H