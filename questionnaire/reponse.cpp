#include "questionnaire/reponse.h"

namespace test
{
    reponse::reponse(const std::string& donnee):
        d_donnee{donnee}, d_valide{false}
    {}

    std::string reponse::donnee() const
    {
        return d_donnee;
    }

    bool reponse::valide() const
    {
        return d_valide;
    }

    void reponse::changeValidite(bool validite)
    {
        d_valide = validite;
    }

} // test