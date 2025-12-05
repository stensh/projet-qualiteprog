#ifndef PROJET_QUALITEPROG_APPRENTISSAGE_H
#define PROJET_QUALITEPROG_APPRENTISSAGE_H

#include "questionnaire/questionnaire.h"

namespace revision
{
    class apprentissage
    {
    public:
        apprentissage() = default;
        ~apprentissage() = default;
        void commencer(const sujet::questionnaire &quest);
    };
}

#endif //PROJET_QUALITEPROG_APPRENTISSAGE_H
