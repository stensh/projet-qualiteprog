//
// Created by rquen on 14/11/2025.
//

#ifndef PROJET_QUALITEPROG_QUESTIONNAIRE_H
#define PROJET_QUALITEPROG_QUESTIONNAIRE_H

#include <memory>
#include <vector>
#include <fstream>
#include "question.h"
#include "questionText.h"
#include "questionNumerique.h"
#include "questionChoixMultiples.h"

class questionnaire
{
    public:
        questionnaire(std::string& nomQuestionnaire);
        ~questionnaire();

        int chargeQuestionnaire(const std::string& questionnaire);  //0 si le fichier a été lu
                                    //1 si le fichier n'a pu être ouvert
                                    //2 si le fichier n'est pas un fichier questionnaire
                                    //3 si une erreur est survenu lors de la lecture du fichier


        question questionCourante(int indice) const;    //Renvoie la question demandée indice.

    private:
        std::vector<std::unique_ptr<question>> d_questions; //Stock les différentes question du questionnaire

        std::unique_ptr<questionNumerique> lireQuestionNum(std::ifstream& fichier);
        std::unique_ptr<questionTexte> lireQuestionTxt(std::ifstream& fichier);
        std::unique_ptr<questionChoixMultiples> lireQuestionChoixMultiples(std::ifstream& fichier);

};


#endif //PROJET_QUALITEPROG_QUESTIONNAIRE_H