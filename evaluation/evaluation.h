#ifndef PROJET_QUALITEPROG_EVALUATION_H
#define PROJET_QUALITEPROG_EVALUATION_H

#include "questionnaire/question.h"
#include "questionnaire/questionnaire.h"

namespace test
{
    class evaluation
    {
    public:
        // Constructeur et desctructeur virtuel
        evaluation(const sujet::questionnaire& q);
        virtual ~evaluation() = default;

        // Accesseurs
        int indiceCourant() const;
        int bonnesReponses() const;
        int nbQuestions() const;
        int questionsPosees() const;

        // Modifieurs
        void incrementeBonnesReponses();
        void incrementeQuestionsPosees();
        void incrementeIndiceCourant();
        const std::unique_ptr<sujet::question>& questionCourante() const;

        // Méthodes virtuelles pures
        virtual bool resteQuestions() const = 0;
        virtual bool afficherBonneReponse() const = 0;
        virtual void questionSuivante() = 0;
        virtual double resultats() const = 0; // Donne la note sur 20
    private:
        int d_indiceCourant, d_nbBonnesReponses, d_nbQuestionsPosees; // calculé ?
        const sujet::questionnaire& d_questionnaire; // On utilise une référence constante
    };
}

#endif //PROJET_QUALITEPROG_EVALUATION_H
