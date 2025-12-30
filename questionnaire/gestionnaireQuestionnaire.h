#ifndef PROJET_GESTIONNAIREQUESTIONNAIRE_H
#define PROJET_GESTIONNAIREQUESTIONNAIRE_H

#include <memory>
#include <fstream>
#include "questionnaire/questionTexte.h"
#include "questionnaire/questionNumerique.h"
#include "questionnaire/questionChoixMultiples.h"
#include "questionnaire/questionnaire.h"


namespace sujet {


class gestionnaireQuestionnaire
{
    public:
        gestionnaireQuestionnaire() = default;
        ~gestionnaireQuestionnaire() = default;

        /*
        * @param code = 0 si le fichier a été lu
        * @param code = 1 si le fichier n'a pu être ouvert
        * @param code = 2 si le fichier n'est pas un fichier questionnaire
        * @param code = 3 si une erreur est survenu lors de la lecture du fichier
        */
        void chargeQuestionnaire(questionnaire& quest, int& code);
        bool valideEntete(std::istream& fichier);
        void analyseQuestions (questionnaire& ques, std::istream& fichier, int& code);

        std::unique_ptr<question> creeQuestion(const std::string& balise, std::istream& fichier);

        std::unique_ptr<questionNumerique> lireQuestionNum(std::istream& fichier);
        std::unique_ptr<questionTexte> lireQuestionTxt(std::istream& fichier);
        std::unique_ptr<questionChoixMultiples> lireQuestionChoixMultiples(std::istream& fichier);

        void vider(questionnaire& quest) const;


    private:
        inline static const std::string ENTETE_FICHIER = "CECI EST UN QUESTIONNAIRE";   //A REVOIR

};


}

#endif //PROJET_GESTIONNAIREQUESTIONNAIRE_H