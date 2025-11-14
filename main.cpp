#include <iostream>
#include <vector>
#include <cmath>

void run()
{
    std::cout << "Bienvenue dans le programme de gestion de questionnaires !" << std::endl;
    std::cout << "Veuillez choisir une option : " << std::endl;
    std::cout << "1. Creer un questionnaire" << std::endl;
    std::cout << "2. Apprendre un questionnaire" << std::endl;
    std::cout << "3. Commencer une évaluation" << std::endl;

    int n;
    std::cin >> n;

    // Faire ce genre de validations en Doctests
    while (n < 1 || n > 3)
    {
        std::cout << "L'option saisie n'est pas valide, veuillez reesayer : " << std::endl;
        std::cin >> n;
    }
}

int main()
{
    std::cout << "Test de compilation" << std::endl;
    return 0;
}