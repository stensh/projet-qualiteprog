#include <iostream>
#include <limits>
#include <windows.h>

#include "apprentissage/apprentissage.h"
#include "evaluation/evaluationTest.h"
#include "evaluation/evaluationAdaptative.h"
#include "evaluation/gestionnaireEvaluation.h"
#include "evaluation/evaluationSecondeChance.h"
#include "questionnaire/gestionnaireQuestionnaire.h"


void chargerQuestionnaire(sujet::questionnaire& q)
{
    std::cout << "Veuillez rentrer le nom du questionnaire à charger : "<<std::endl;
    std::string nomFichier;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nomFichier); //getline pour entré des noms de fichier avec des espaces

    q.modifierNom(nomFichier);
    sujet::gestionnaireQuestionnaire gestQ;
    int code;
    gestQ.chargeQuestionnaire(q,code);
    switch(code)
    {
        case 1: std::cout<<"Le fichier n'a pas pu être ouvert, il est possible que celui-ci n'existe pas. Essayez avec un autre fichier :"<<std::endl;
            break;
        case 2: std::cout<<"Le fichier n'est pas un fichier questionnaire, essayez avec un autre fichier :"<<std::endl;
            break;
        case 3: std::cout<<"Une erreur est survenu lors de la lecture du fichier, corrigé le fichier ou essayé un autre fichier :"<<std::endl;
            break;
    }
}

void apprendreQuestionnaire(const sujet::questionnaire& q)
{
    if (q.taille()>0)
        revision::apprentissage::commencer(q,std::cout,std::cin);
    else
        std::cout<<"Le questionnaire ne contient aucune question."<<std::endl;
}

int menuEvaluation()
{
    std::cout<<"Veuillez choisir un type d'évaluation : "<<std::endl;
    std::cout<<"1. Évaluation test"<<std::endl;
    std::cout<<"2. Évaluation seconde chance"<<std::endl;
    std::cout<<"3. Évaluation adaptative"<<std::endl;
    std::cout<<"4. Retour au menu principal"<<std::endl;

    int n;
    std::cin>>n;
    while (std::cin.fail() || n<1 || n>4)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"L'option saisie n'est pas valide, veuillez reessayer :"<<std::endl;
        std::cin>>n;
    }
    return n;
}

void commencerEvaluation(const sujet::questionnaire& q)
{
    if (q.taille() == 0)
    {
        std::cout<<"Le questionnaire ne contient aucune question."<<std::endl;
        return;
    }

    int choix = menuEvaluation();
    if (choix == 4)
        return;

    // Ignorer le '\n' restant après la lecture du choix
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    test::gestionnaireEvaluation gestEval;
    
    switch (choix)
    {
        case 1:
        {
            test::evaluationTest eval{q};
            gestEval.commencerEvaluation(eval);
            break;
        }
        case 2:
        {
            test::evaluationSecondeChance eval{q};
            gestEval.commencerEvaluation(eval);
            break;
        }
        case 3:
        {
            test::evaluationAdaptative eval{q};
            gestEval.commencerEvaluation(eval);
            break;
        }
    }
}

int menuPrincipal()
{
    std::cout<<"Veuillez choisir une option : "<<std::endl;
    std::cout<<"1. Charger un questionnaire"<<std::endl;
    std::cout<<"2. Apprendre un questionnaire"<<std::endl;
    std::cout<<"3. Commencer une évaluation"<<std::endl;
    std::cout<<"4. Quitter"<<std::endl;

    int n;
    std::cin>>n;
    // Faire ce genre de validations en Doctests
    while (std::cin.fail() || n<1 || n>4)
    {
        std::cin.clear();   //Réinitialise les flags d'erreur pour permettre les saisies suivantes
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"L'option saisie n'est pas valide, veuillez reesayer :"<<std::endl;
        std::cin>>n;
    }
    return n;
}

void run()
{
    std::cout<<"Bienvenue dans le programme de gestion de questionnaires !"<<std::endl;
    sujet::questionnaire quest{""};
    bool goOn = true;
    while (goOn)
    {
        switch (menuPrincipal())
        {
        case 1:chargerQuestionnaire(quest); break;
        case 2:apprendreQuestionnaire(quest); break;
        case 3:commencerEvaluation(quest); break;
        default: goOn=false;
        }
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    run();
    return 0;
}