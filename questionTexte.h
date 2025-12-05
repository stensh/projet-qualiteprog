#ifndef PROJET_QUALITEPROG_QUESTIONTEXT_H
#define PROJET_QUALITEPROG_QUESTIONTEXT_H

#include "question.h"

namespace sujet
{

class questionTexte : public question
{
    public:
        questionTexte(const std::string& intitule, const std::string& texte, const std::string& reponse);

        std::string reponse() const override;    //Renvoie la bonne réponse.
        bool reponseJuste(const std::string& reponse) const override;

    private:
        std::string d_reponse;

};

}
#endif //PROJET_QUALITEPROG_QUESTIONTEXT_H