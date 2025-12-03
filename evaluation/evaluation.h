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
        question questionCourante() const; // à définir
        virtual bool resteQuestions() const = 0;
        virtual void incrementeBonnesReponses();
        virtual bool afficherBonneReponse() const = 0;
        virtual void questionSuivante() const = 0;
        virtual double resultats() const = 0;
    private:
        int d_nbBonnesReponses, d_nbQuestionsPosees;
    };
}

#endif //PROJET_QUALITEPROG_EVALUATION_H
