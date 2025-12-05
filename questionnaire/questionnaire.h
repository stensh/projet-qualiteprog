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
        // Constructeur et desctructeur
        questionnaire(std::string& nomFichier);
        ~questionnaire() = default;

        // Méthodes de la classe
        void ajouteQuestion(std::unique_ptr<question> q);
        const std::unique_ptr<question>& questionIndice(int indice) const; // référence constante pour accès en lecture
        std::string nomFichier() const;
        int taille() const;

    private:
        std::vector<std::unique_ptr<question>> d_questions; //Stock les différentes question du questionnaire
        std::string d_nomFichier;
    };
}
#endif //PROJET_QUALITEPROG_QUESTIONNAIRE_H