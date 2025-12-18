#include "apprentissage.h"
#include  <iostream>
#include  <limits>
namespace revision
{

    void apprentissage::attendreEntree(std::ostream& ost,std::istream& ist) {
        ost << "\nAppuyez sur Entree pour continuer...";
        ist.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void apprentissage::commencer(const sujet::questionnaire &q, std::ostream &ost,std::istream& ist)
    {
        for (int i{0}; i < q.taille(); ++i)
        {
            attendreEntree(ost,ist);
            ost << q.questionIndice(i)->contenu();
            attendreEntree(ost,ist);
            ost << q.questionIndice(i)->reponse();
        }
        ost <<std::endl<<"Apprentissage terminée";
        attendreEntree(ost,ist);
    }

}