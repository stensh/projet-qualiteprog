#ifndef PROJET_QUALITEPROG_APPRENTISSAGE_H
#define PROJET_QUALITEPROG_APPRENTISSAGE_H


#include "questionnaire/questionnaire.h"

namespace revision
{
    class apprentissage
    {
    public:
        apprentissage() = delete ;
        void static commencer(const sujet::questionnaire &q, std::ostream &ost,std::istream& ist );
    private:
        void static attendreEntree(std::ostream& ost,std::istream& ist);
    };
}

#endif //PROJET_QUALITEPROG_APPRENTISSAGE_H
