#ifndef PROJET_QUALITEPROG_QUESTIONNAIRE_H
#define PROJET_QUALITEPROG_QUESTIONNAIRE_H

#include <memory>
#include <vector>
#include <fstream>
#include "questionnaire/question.h"


namespace sujet
{

    class questionnaire
    {
    public:
        questionnaire();

        //Constructeur et destructeur
        questionnaire(const std::string& nomFichier);
        ~questionnaire() = default ;

        //Méthode de la classe
        void ajouteQuestion(std::unique_ptr<question> q);
        const std::unique_ptr<question>& questionIndice(int indice) const;    //Renvoie la question demandée indice.
        std::string nomFichier() const;
        int taille() const;

    private:
        std::vector<std::unique_ptr<question>> d_questions; //Stock les différentes questions du questionnaire
        std::string d_nomFichier;
    };
}
#endif //PROJET_QUALITEPROG_QUESTIONNAIRE_H