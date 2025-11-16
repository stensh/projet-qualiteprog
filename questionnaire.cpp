//
// Created by rquen on 14/11/2025.
//

#include "questionnaire.h"

#include <iostream>

using std::cout;
using std::cin;

const std::string EN_TETE_FICHIER{"CECI EST UN QUESTIONNAIRE"};

questionnaire::questionnaire():
    d_questionnaire{}
{}

std::unique_ptr<questionNumerique> questionnaire::lireQuestionNum(std::ifstream& fichier)
{
    std::unique_ptr<questionNumerique> qn;
    getline(fichier, qn->d_intitule);
    getline(fichier, qn->d_texte);
    fichier >> qn->d_limMin >> qn->d_limMax >> qn->d_reponse;
    fichier.ignore();   //"lit" le caractère de fin de ligne
    return qn;
}

std::unique_ptr<questionText> questionnaire::lireQuestionTxt(std::ifstream& fichier)
{
    std::unique_ptr<questionText> qt;
    getline(fichier, qt->d_intitule);
    getline(fichier, qt->d_texte);
    getline(fichier, qt->d_reponse);
    return qt;
}

std::unique_ptr<questionChoixMultiples> questionnaire::lireQuestionChoixMultiples(std::ifstream& fichier)
{
    std::unique_ptr<questionChoixMultiples> qcm;
    getline(fichier, qcm->d_intitule);
    std::string txt;
    getline(fichier, txt);
    qcm->d_texte = txt;
    getline(fichier, txt);
    qcm->d_texte += '\n' + txt;
    getline(fichier, txt);
    qcm->d_texte += '\n' + txt;
    getline(fichier, txt);
    qcm->d_texte += '\n' + txt;
    getline(fichier, txt);
    qcm->d_texte += '\n' + txt;
    fichier >> qcm->d_reponse;
    fichier.ignore();
    return qcm;
}


int questionnaire::chargeQuestionnaire()
{
    std::ifstream fichier("questionnaire.txt");
    if (!fichier.fail())
    {
        std::string lecture;
        std::getline(fichier, lecture);
        if (lecture == EN_TETE_FICHIER)
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
                        std::unique_ptr<questionNumerique> qn = lireQuestionNum(fichier);
                        d_questionnaire.push_back(std::move(qn));
                    }
                    else if (carac == '<')
                    {
                        fichier.get(carac);//Lit '\n' après '<'
                        std::unique_ptr<questionText> qtx = lireQuestionTxt(fichier);
                        d_questionnaire.push_back(std::move(qtx));
                    }
                    else if (carac == '/')
                    {
                        fichier.get(carac);
                        std::unique_ptr<questionChoixMultiples> qch = lireQuestionChoixMultiples(fichier);
                        d_questionnaire.push_back(std::move(qch));
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
