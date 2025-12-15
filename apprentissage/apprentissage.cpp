#include "apprentissage.h"
#include  <iostream>
#include  <limits>
namespace revision
{
    void apprentissage::attendreEntree(std::ostream& ost) {
        ost << "\nAppuyez sur Entree pour continuer..." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    apprentissage::apprentissage(const sujet::questionnaire& q, std::ostream &ost)
    {
        commencer(q, ost);
    }

    void apprentissage::commencer(const sujet::questionnaire &q, std::ostream &ost)const
    {
        for (int i{0}; i < q.taille(); ++i)
        {
            ost << q.questionIndice(i)->contenu() << std::endl;
            attendreEntree(ost);
            ost << q.questionIndice(i)->reponse() << std::endl;
            attendreEntree(ost);
        }
    }

}