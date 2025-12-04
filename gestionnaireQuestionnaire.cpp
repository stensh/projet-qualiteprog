#include <fstream>
#include "gestionnaireQuestionnaire.h"

namespace sujet
{

gestionnaireQuestionnaire::gestionnaireQuestionnaire()
{}

gestionnaireQuestionnaire::~gestionnaireQuestionnaire()
{}


std::unique_ptr<questionNumerique> gestionnaireQuestionnaire::lireQuestionNum(std::ifstream& fichier)
{
    std::string intitule, texte;
    int  limMin, limMax;
    getline(fichier, intitule);
    getline(fichier, texte);
    fichier >> limMin >> limMax ;
    fichier.ignore();   //"lit" le caractère de fin de ligne
    return std::make_unique<questionNumerique>(intitule,texte,limMin,limMax);
}

std::unique_ptr<questionTexte> gestionnaireQuestionnaire::lireQuestionTxt(std::ifstream& fichier)
{
    std::string intitule, texte, reponse;
    getline(fichier, intitule);
    getline(fichier, texte);
    getline(fichier, reponse);
    return std::make_unique<questionTexte>(intitule,texte,reponse);
}

std::unique_ptr<questionChoixMultiples> gestionnaireQuestionnaire::lireQuestionChoixMultiples(std::ifstream& fichier)
{
    std::string intitule, texte, texteGet;
    int reponse;
    getline(fichier, intitule);
    getline(fichier, texteGet);
    texte = texteGet;
    for (int i{0}; i<4; ++i)
    {
        getline(fichier, texteGet);
        texte += '\n' + texteGet;
    }
    fichier >> reponse;
    fichier.ignore();
    return std::make_unique<questionChoixMultiples>(intitule,texte,reponse);
}

bool gestionnaireQuestionnaire::valideEntete(std::ifstream &fichier)
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

int gestionnaireQuestionnaire::analyseQuestions(questionnaire *ques, std::ifstream &fichier)
{
    std::string balise;
    while (std::getline(fichier,balise) and balise!="}")
    {
        auto question = creeQuestion(balise, fichier);
        if (question==nullptr)
        {
            return 3;
        }
        ques->ajouteQuestion(std::move(question));
    }
    return 0;
}

std::unique_ptr<question> gestionnaireQuestionnaire::creeQuestion(const std::string& balise, std::ifstream &fichier)
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

int gestionnaireQuestionnaire::chargeQuestionnaire(questionnaire* quest)
{
    std::ifstream fichier(quest->nomFichier());
    if (!fichier)
    {
        return 1;
    }
    if (!valideEntete(fichier))
    {
        return 2;
    }
    return analyseQuestions(quest, fichier);
}


}