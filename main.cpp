#include <iostream>
#include "apprentissage/apprentissage.h"
#include "evaluation/gestionnaireEvaluation.h"
#include "questionnaire/gestionnaireQuestionnaire.h"
#include <windows.h>


void chargerQuestionnaire(sujet::questionnaire& q,int& code)
{
    std::cout << "Veuillez rentrer le nom du questionnaire à charger : " << std::endl;
    std::string nomFichier;
    std::cin >> nomFichier;

    q.modifierNom(nomFichier);
    sujet::gestionnaireQuestionnaire gestQ;
    gestQ.chargeQuestionnaire(q,code);
}

void apprendreQuestionnaire(const sujet::questionnaire& q)
{
    revision::apprentissage::commencer(q,std::cout,std::cin);
}

int menu()
{
    std::cout << "Veuillez choisir une option : " << std::endl;
    std::cout << "1. Charger un questionnaire" << std::endl;
    std::cout << "2. Apprendre un questionnaire" << std::endl;
    std::cout << "3. Commencer une évaluation" << std::endl;
    std::cout << "4. Quitter" << std::endl;

    int n;
    std::cin >> n;
    // Faire ce genre de validations en Doctests
    while (n < 1 || n > 4)
    {
        std::cout << "L'option saisie n'est pas valide, veuillez reesayer : " << std::endl;
        std::cin >> n;
    }
    return n;
}
void run()
{
    std::cout << "Bienvenue dans le programme de gestion de questionnaires !" << std::endl;
    sujet::questionnaire quest{""};
    bool goOn = true;
    int code;
    while (goOn)
    {
        switch (menu())
        {
        case 1:chargerQuestionnaire(quest,code); break;
        case 2:apprendreQuestionnaire(quest); break;
        case 3:/* Afficher une liste des différentes évaluations*/ break;
        default: goOn=false;
        }
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Test de compilation" << std::endl;
    run();
    return 0;
}