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

int gestionnaireQuestionnaire::chargeQuestionnaire(questionnaire* quest)
{
    std::ifstream fichier(quest->nomFichier());
    if (!fichier.fail())
    {
        std::string balise;
        std::getline(fichier, balise);
        if (balise == ENTETE_FICHIER)
        {
            getline(fichier, balise);
            if (balise == "{")
            {
                while (getline(fichier, balise) && balise != "}")
                {
                    if (balise == "[QN]")
                    {
                        std::unique_ptr<question> qNum = lireQuestionNum(fichier);
                        quest->ajouteQuestion(qNum);
                    }
                    else if (balise == "[QT]")
                    {
                        std::unique_ptr<question> qTXT = lireQuestionTxt(fichier);
                        quest->ajouteQuestion(qTXT);
                    }
                    else if (balise == "[QCM]")
                    {
                        std::unique_ptr<question> qCM = lireQuestionChoixMultiples(fichier);
                        quest->ajouteQuestion(qCM);
                    }
                    else
                    {
                        return 3;   //Problème lecture fichier
                    }
                }
            }
            else
            {
                return 3;   //Problème lecture fichier
            }
        }
        else
        {
            return 2;   //Pas un fichier questionnaire
        }
    }
    else
    {
        return 1;   //Impossible d'ouvrir le fichier ou corrompu
    }
    return 0;
}


}