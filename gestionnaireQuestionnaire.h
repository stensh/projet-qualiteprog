#ifndef PROJET_GESTIONNAIREQUESTIONNAIRE_H
#define PROJET_GESTIONNAIREQUESTIONNAIRE_H

#include <memory>
#include <fstream>
#include "questionTexte.h"
#include "questionNumerique.h"
#include "questionChoixMultiples.h"
#include "questionnaire.h"


namespace sujet {


class gestionnaireQuestionnaire
{
    public:
        gestionnaireQuestionnaire();
        ~gestionnaireQuestionnaire();

        /**
        * @return 0 si le fichier a été lu
        * @return 1 si le fichier n'a pu être ouvert
        * @return 2 si le fichier n'est pas un fichier questionnaire
        * @return 3 si une erreur est survenu lors de la lecture du fichier
        */
        int chargeQuestionnaire(questionnaire& quest);
        bool valideEntete(std::ifstream& fichier);
        int analyseQuestions (questionnaire& ques, std::ifstream& fichier);

        std::unique_ptr<question> creeQuestion(const std::string& balise, std::ifstream& fichier);
        std::unique_ptr<questionNumerique> lireQuestionNum(std::ifstream& fichier);
        std::unique_ptr<questionTexte> lireQuestionTxt(std::ifstream& fichier);
        std::unique_ptr<questionChoixMultiples> lireQuestionChoixMultiples(std::ifstream& fichier);


    private:
        inline static const std::string ENTETE_FICHIER = "CECI EST UN QUESTIONNAIRE";   //A REVOIR

};


}

#endif //PROJET_GESTIONNAIREQUESTIONNAIRE_H