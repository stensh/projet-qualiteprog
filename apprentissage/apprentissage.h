#ifndef PROJET_QUALITEPROG_APPRENTISSAGE_H
#define PROJET_QUALITEPROG_APPRENTISSAGE_H

#include "questionnaire/questionnaire.h"

namespace revision
{
    class apprentissage
    {
    public:
        apprentissage(const sujet::questionnaire& q, std::ostream& ost);
        ~apprentissage() = default;
        void commencer(const sujet::questionnaire &q, std::ostream &ost);
    };
}

#endif //PROJET_QUALITEPROG_APPRENTISSAGE_H
