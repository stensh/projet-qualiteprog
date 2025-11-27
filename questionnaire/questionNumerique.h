#ifndef PROJET_QUALITEPROG_QUESTIONNUMERIQUE_H
#define PROJET_QUALITEPROG_QUESTIONNUMERIQUE_H

#include <string>
#include "question.h"

namespace sujet
{

class questionNumerique: public question
{
    public:
        questionNumerique(const std::string& intitule,const std::string& texte,int limMin,int limMax);

        int limiteMin() const ;//Renvoie la limite minimale de la réponse
        int limiteMax() const ;//Renvoie la limite maximale de la réponse
        bool reponseJuste(std::string& reponse) const override;

    private:
        int  d_limMin, d_limMax;
};

}
#endif //PROJET_QUALITEPROG_QUESTIONNUMERIQUE_H