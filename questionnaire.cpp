//
// Created by rquen on 14/11/2025.
//

#include "questionnaire.h"
#include <iostream>

const std::string ENTETE_FICHIER{"CECI EST UN QUESTIONNAIRE"};

questionnaire::questionnaire(std::string& nomQuestionnaire):
    d_questions{}
{
    chargeQuestionnaire(nomQuestionnaire);
}

std::unique_ptr<questionNumerique> questionnaire::lireQuestionNum(std::ifstream& fichier)
{
    std::string intitule, texte;
    int  limMin, limMax;
    getline(fichier, intitule);
    getline(fichier, texte);
    fichier >> limMin >> limMax ;
    fichier.ignore();   //"lit" le caractère de fin de ligne
    auto qNum{std::make_unique<questionNumerique>(intitule,texte,limMin,limMax)};
    return qNum;
}

std::unique_ptr<questionTexte> questionnaire::lireQuestionTxt(std::ifstream& fichier)
{
    std::string intitule, texte, reponse;
    getline(fichier, intitule);
    getline(fichier, texte);
    getline(fichier, reponse);
    auto qTXT{std::make_unique<questionTexte>(intitule,texte,reponse)};
    return qTXT;
}

std::unique_ptr<questionChoixMultiples> questionnaire::lireQuestionChoixMultiples(std::ifstream& fichier)
{
    std::string intitule, texte, texteGet;
    int reponse;
    getline(fichier, intitule);
    getline(fichier, texteGet);
    texte = texteGet;
    getline(fichier, texteGet);
    texte += '\n' + texteGet;
    getline(fichier, texteGet);
    texte += '\n' + texteGet;
    getline(fichier, texteGet);
    texte += '\n' + texteGet;
    getline(fichier, texteGet);
    texte += '\n' + texteGet;
    fichier >> reponse;
    fichier.ignore();
    auto qcm{std::make_unique<questionChoixMultiples>(intitule,texte,reponse)};
    return qcm;
}


int questionnaire::chargeQuestionnaire(const std::string& questionnaire)
{
    std::ifstream fichier(questionnaire);
    if (!fichier.fail())
    {
        std::string lecture;
        std::getline(fichier, lecture);
        if (lecture == ENTETE_FICHIER)
        {
            char carac;
            fichier.get(carac);
            if (carac == '{')
            {
                fichier.get(carac); // Lit le premier '\n'
                while (fichier.get(carac) && carac != '}')
                {
                    if (carac == '\'')
                    {
                        fichier.get(carac); //Lit '\n' après '\''
                        std::unique_ptr<questionNumerique> qNum = lireQuestionNum(fichier);
                        d_questions.push_back(std::move(qNum));
                    }
                    else if (carac == '<')
                    {
                        fichier.get(carac);//Lit '\n' après '<'
                        std::unique_ptr<questionTexte> qTXT = lireQuestionTxt(fichier);
                        d_questions.push_back(std::move(qTXT));
                    }
                    else if (carac == '/')
                    {
                        fichier.get(carac);
                        std::unique_ptr<questionChoixMultiples> qCM = lireQuestionChoixMultiples(fichier);
                        d_questions.push_back(std::move(qCM));
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

question questionnaire::questionCourante(int indice) const
{
    return *d_questions[indice];
}