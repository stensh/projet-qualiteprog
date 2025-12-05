#include <istream>
#include "questionnaire/gestionnaireQuestionnaire.h"

namespace sujet
{


std::unique_ptr<questionNumerique> gestionnaireQuestionnaire::lireQuestionNum(std::istream& fichier)
{
    std::string intitule, texte;
    int  limMin, limMax;
    getline(fichier, intitule);
    getline(fichier, texte);
    fichier >> limMin >> limMax ;
    fichier.ignore();   //"lit" le caractère de fin de ligne
    return std::make_unique<questionNumerique>(intitule,texte,limMin,limMax);
}

std::unique_ptr<questionTexte> gestionnaireQuestionnaire::lireQuestionTxt(std::istream& fichier)
{
    std::string intitule, texte, reponse;
    getline(fichier, intitule);
    getline(fichier, texte);
    getline(fichier, reponse);
    return std::make_unique<questionTexte>(intitule,texte,reponse);
}

std::unique_ptr<questionChoixMultiples> gestionnaireQuestionnaire::lireQuestionChoixMultiples(std::istream& fichier)
{
    std::string intitule, texteGet;
    int reponse;
    getline(fichier, intitule);
    getline(fichier, texteGet);
    std::string texte = texteGet;
    for (int i{0}; i<4; ++i)
    {
        getline(fichier, texteGet);
        texte += '\n' + texteGet;
    }
    fichier >> reponse;
    fichier.ignore();
    return std::make_unique<questionChoixMultiples>(intitule,texte,reponse);
}

bool gestionnaireQuestionnaire::valideEntete(std::istream &fichier)
{
    std::string balise;
    std::getline(fichier, balise);
    if (balise != ENTETE_FICHIER)
    {
        return false;
    }
    std::getline(fichier, balise);
    return balise=="{";
}

void gestionnaireQuestionnaire::analyseQuestions(questionnaire &ques, std::istream &fichier, int &code)
{
    std::string balise;
    while (std::getline(fichier,balise) and balise!="}")    //A demander au prof.
    {
        auto question = creeQuestion(balise, fichier);
        if (question!=nullptr)
        {
            ques.ajouteQuestion(std::move(question));
        }
        else
        {
            break;
        }
    }
    if (balise == "}")
        code = 0;
    else
        code = 3;
}

std::unique_ptr<question> gestionnaireQuestionnaire::creeQuestion(const std::string& balise, std::istream &fichier)
{
    if (balise=="[QN]")
    {
        return lireQuestionNum(fichier);
    }
    else if (balise=="[QT]")
    {
        return lireQuestionTxt(fichier);
    }
    else if (balise=="[QCM]")
    {
        return lireQuestionChoixMultiples(fichier);
    }
    return nullptr;
}

void gestionnaireQuestionnaire::chargeQuestionnaire(questionnaire& quest, int &code)
{
    std::ifstream fichier(quest.nomFichier());
    if (!fichier)
    {
        code=1;
    }
    else if (!valideEntete(fichier))
    {
        code=2;
    }
    else
    {
        analyseQuestions(quest, fichier, code);
    }
}


}