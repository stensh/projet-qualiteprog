#include "doctest.h"
#include "questionNumerique.h"
#include "questionChoixMultiples.h"
#include "questionTexte.h"

#include <string>

void questionBienConstruite(const sujet::question& q,const std::string& intitule,
                            const std::string& texte)
{
    REQUIRE((q.intitule()== intitule));
    REQUIRE((q.texte()== texte));
}

//Question Numérique
TEST_CASE("La question numérique est bien construite")
{
    std::string intitule{"intitule"}, texte{"texte"};
    int min{45}, max{50};
    sujet::questionNumerique q{intitule,texte,min,max};
    SUBCASE("La question est bien construite")
    {
        questionBienConstruite(q,intitule,texte);
    }
   SUBCASE("Les données de la classe question numérique sont bien assignées")
    {
        REQUIRE((q.limiteMin()== min));
        REQUIRE((q.limiteMax()== max));
        REQUIRE((q.reponseJuste(std::to_string(min))));
        REQUIRE((q.reponseJuste(std::to_string(max))));
    }
}

//Question à choix multiples
TEST_CASE("La question choix multiples est bien construite")
{
    std::string intitule{"intitule"}, texte{"texte"};
    int reponse{3};
    sujet::questionChoixMultiples q{intitule,texte,reponse};
    SUBCASE("La question est bien construite")
    {
        questionBienConstruite(q,intitule,texte);
    }
    SUBCASE("Les données de la classe question à choix multiples")
    {
        REQUIRE((std::stoi(q.reponse()) == reponse));
        REQUIRE((q.reponseJuste(std::to_string(reponse))));
    }
}

//Questions texte

TEST_CASE("La question texte est bien construite")
{
    std::string intitule{"intitule"}, texte{"texte"},reponse{"reponse"};
    sujet::questionTexte q{intitule,texte,reponse};

    SUBCASE("La question est bien construite")
    {
        questionBienConstruite(q,intitule,texte);
    }
    SUBCASE("Les données de la classe question à choix multiples")
    {
        REQUIRE((q.reponse() == reponse));
        REQUIRE(q.reponseJuste(reponse));
    }
}