#ifndef PROJET_QUALITEPROG_GESTIONNAIREEVALUATION_H
#define PROJET_QUALITEPROG_GESTIONNAIREEVALUATION_H

#inlude<memory>

class questionnaire, evaluation;

namespace test {
    class gestionnaireEvaluation {
        public:
            gestionnaireEvaluation();
            ~gestionnaireEvaluation();
            void commencerEvaluation(questionnaire* quest, std::unique_ptr<evaluation>& eval) const;
    };
}

#endif //PROJET_QUALITEPROG_GESTIONNAIREEVALUATION_H