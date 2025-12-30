#include <iostream>
#include <limits>
#include <windows.h>

#include "apprentissage/apprentissage.h"
#include "evaluation/gestionnaireEvaluation.h"
#include "questionnaire/gestionnaireQuestionnaire.h"


void chargerQuestionnaire(sujet::questionnaire& q)
{
    std::cout << "Veuillez rentrer le nom du questionnaire à charger : " << std::endl;
    std::string nomFichier;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nomFichier); //getline pour entré des noms de fichier avec des espaces

    q.modifierNom(nomFichier);
    sujet::gestionnaireQuestionnaire gestQ;
    int code;
    gestQ.chargeQuestionnaire(q,code);
    switch(code)
    {
        case 1: std::cout<<"Le fichier n'a pu être ouvert, il est possible que celui-ci n'existe pas. Essayé un autre fichier :\n";break;
        case 2: std::cout<<"Le fichier n'est pas un fichier questionnaire, essayé un autre fichier :\n";break;
        case 3: std::cout<<"Une erreur est survenu lors de la lecture du fichier, corrigé le fichier ou essayé un autre fichier :\n";break;
    }

}

void apprendreQuestionnaire(const sujet::questionnaire& q)
{
    if (q.taille()>0)
        revision::apprentissage::commencer(q,std::cout,std::cin);
    else
        std::cout<<"Le questionnaire ne contient aucune question\n";
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
    while (std::cin.fail() || n < 1 || n > 4)
    {
        std::cin.clear();   //Réinitialise les flags d'erreur pour permettre les saisies suivantes
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    while (goOn)
    {
        switch (menu())
        {
        case 1:chargerQuestionnaire(quest); break;
        case 2:apprendreQuestionnaire(quest); break;
        case 3: break; //A faire
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