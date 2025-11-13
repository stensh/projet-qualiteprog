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
    private:
        int d_score, d_nbEssais;
    };
} // test

#endif //PROJET_QUALITEPROG_EVALUATION_H