#include "gestionnaireEvaluation.h"

namespace test {
    gestionnaireEvaluation::gestionnaireEvaluation()
    {}

    gestionnaireEvaluation::~gestinnaireEvaluation()
    {}

    void gestionnaireEvaluation::commencerEvaluation(questionnaire* quest, std::unique_ptr<evaluation>& eval)
    {
        for (int i{0}; i < quest->d_questions.size(); ++i)
        {

        }
    }
} // test