#include "apprentissage.h"

namespace revision
{
    apprentissage::apprentissage(const sujet::questionnaire& q, std::ostream &ost)
    {
        commencer(q, ist, ost);
    }

    void apprentissage::commencer(const sujet::questionnaire &q, std::ostream &ost)
    {
        for (int i{0}; i < q.taille(); ++i)
        {
            ost << q.questionIndice(i)->contenu() << std::endl;
            // TODO attendre une action de l'utilisateur
            ost << // quest.questionCourante()->reponse() << std::endl
        }
    }

}