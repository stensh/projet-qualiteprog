#include "apprentissage.h"
#include  <iostream>
#include  <limits>
namespace revision
{

    void apprentissage::attendreEntreeQuestion(std::ostream& ost,std::istream& ist)
    {
        ost << "\nAppuyez sur Entrée pour passer à la question suivante...\n";
        ist.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void apprentissage::attendreEntreeReponse(std::ostream& ost,std::istream& ist)
    {
        ost << "\nAppuyez sur Entrée pour afficher la réponse...";
        ist.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void apprentissage::commencer(const sujet::questionnaire &q, std::ostream &ost,std::istream& ist)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Vider le buffer initial
        for (int i{0}; i < q.taille(); ++i)
        {
            ost << q.questionIndice(i)->contenu();
            attendreEntreeReponse(ost,ist);
            ost << q.questionIndice(i)->reponse();
            if (i < q.taille() - 1)  // Seulement si ce n'est pas la dernière question
                attendreEntreeQuestion(ost,ist);
        }
        ost<<std::endl<<std::endl<< "Apprentissage terminé\nAppuyez sur Entrée pour revenir au menu...";
        ist.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}