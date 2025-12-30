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
        int bonnesReponses() const;
        int nbQuestions() const;
        int questionsPosees() const;

        // Modifieurs
        void incrementeBonnesReponses();
        void incrementeQuestionsPosees();

        // Méthodes virtuelles pures
        virtual const std::unique_ptr<sujet::question>& questionCourante() const = 0;
        // virtuelle car on change l'approche de question courante pour chaque type d'évaluation
        virtual void reussiteCourante() = 0;
        virtual void echecCourant() = 0;
        virtual bool resteQuestions() const = 0;
        virtual bool afficherBonneReponse() const = 0;
        virtual void questionSuivante() = 0;
        virtual double resultats() const = 0; // Renvoi la note sur 20

    protected:
        const sujet::questionnaire& questionnaireCourant() const; // accès protégé au questionnaire pour les sous-classes

    private:
        int d_nbBonnesReponses, d_nbQuestionsPosees;
        const sujet::questionnaire& d_questionnaire; // On utilise une référence constante
    };
}

#endif //PROJET_QUALITEPROG_EVALUATION_H