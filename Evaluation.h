#ifndef PROJET_QUALITEPROG_EVALUATION_H
#define PROJET_QUALITEPROG_EVALUATION_H

namespace test
{
    class Evaluation
    {
    public:
        Evaluation();
        virtual ~Evaluation() = default;
        virtual void commencer() const = 0;
        virtual bool resteQuestions() const = 0;
        virtual int /* plutôt Question */ questionCourante() const = 0;
        virtual bool afficherBonneReponse() const = 0;
        virtual void questionSuivante() const = 0;
        virtual void afficherResultats() const = 0;
    private:
        int d_nbBonnesReponses, d_nbEssais;
    };
} // test

#endif //PROJET_QUALITEPROG_EVALUATION_H