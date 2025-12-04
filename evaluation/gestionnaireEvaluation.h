#ifndef PROJET_QUALITEPROG_GESTIONNAIREEVALUATION_H
#define PROJET_QUALITEPROG_GESTIONNAIREEVALUATION_H

#include <memory>
#include "evaluation.h"
#include "questionnaire/questionnaire.h"

namespace test {
    class gestionnaireEvaluation {
        public:
            gestionnaireEvaluation();
            ~gestionnaireEvaluation();
            void commencerEvaluation(sujet::questionnaire* quest, std::unique_ptr<evaluation>& eval) const;
    };
}

#endif //PROJET_QUALITEPROG_GESTIONNAIREEVALUATION_H