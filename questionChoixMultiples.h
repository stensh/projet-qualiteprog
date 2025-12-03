#ifndef PROJET_QUALITEPROG_QUESTIONCHOIXMULTIPLES_H
#define PROJET_QUALITEPROG_QUESTIONCHOIXMULTIPLES_H

#include "question.h"

namespace sujet
{

class questionChoixMultiples: public question
{
    public:
        questionChoixMultiples(const std::string& intitule, const std::string& texte, int bonneReponse);  //Ici la reponse passé en paramètre est le numéro de la bonne réponse.

        std::string reponse() const override;    //Renvoie le numéro de la réponse.
        bool reponseJuste(const std::string& reponse) const override;  //Indique si la réponse passé en paramètre est juste.

    private:
        int d_bonneReponse;  //Le numéro de la bonne réponse à la question.
};

}
#endif //PROJET_QUALITEPROG_QUESTIONCHOIXMULTIPLES_H