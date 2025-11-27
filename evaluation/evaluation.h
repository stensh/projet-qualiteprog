#ifndef PROJET_QUALITEPROG_EVALUATION_H
#define PROJET_QUALITEPROG_EVALUATION_H

#include "question.h"
#include "questionnaire.h"

namespace test
{
    class evaluation
    {
    public:
        evaluation();
        virtual ~evaluation() = default;
        virtual void commencer(const questionnaire& quest) const = 0;
        virtual bool resteQuestions() const = 0;
        virtual question questionCourante() const = 0;
        virtual bool afficherBonneReponse() const = 0;
        virtual void questionSuivante() const = 0;
        virtual void afficherResultats() const = 0;
    private:
        int d_nbBonnesReponses;
    };
}

#endif //PROJET_QUALITEPROG_EVALUATION_H