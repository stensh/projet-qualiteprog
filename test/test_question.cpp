#include "test/doctest.h"
#include "questionnaire/questionNumerique.h"
#include "questionnaire/questionChoixMultiples.h"
#include "questionnaire/questionTexte.h"

#include <string>


void questionBienConstruite(const sujet::question& q,const std::string& intitule,
                            const std::string& texte)
{
    REQUIRE_EQ(q.intitule(),intitule);
    REQUIRE_EQ(q.texte(),texte);
}

TEST_CASE("La construction d'une question est correcte")
{
    std::string intitule{"intitule"}, texte{"texte"};

    SUBCASE("La construction d'une question numérique est correcte")
    {
        int min{45}, max{50};
        sujet::questionNumerique q{intitule,texte,min,max};
        SUBCASE("La construction de la partie question est correcte")
        {
            questionBienConstruite(q,intitule,texte);
        }
        SUBCASE("Les données de la question numérique sont bien assignées")
        {
            REQUIRE_EQ(q.limiteMin(),min);
            REQUIRE_EQ(q.limiteMax(),max);
            REQUIRE((q.reponseJuste(std::to_string(min+2))));
            REQUIRE_FALSE((q.reponseJuste(std::to_string(max+1))));
        }
    }
    SUBCASE("La construction d'une question à choix multiples est correcte")
    {
        int reponse{3};
        sujet::questionChoixMultiples q{intitule,texte,reponse};
        SUBCASE("La construction de la partie question est correcte")
        {
            questionBienConstruite(q,intitule,texte);
        }
        SUBCASE("Les données de la question à choix multiples sont bien assignées")
        {
            REQUIRE_EQ(std::stoi(q.reponse()),reponse);
            REQUIRE(q.reponseJuste(std::to_string(reponse)));
        }
    }
    SUBCASE("La construction d'une question texte est correcte")
    {
        std::string reponse{"reponse"};
        sujet::questionTexte q{intitule,texte,reponse};

        SUBCASE("La construction de la partie question est correcte")
        {
            questionBienConstruite(q,intitule,texte);
        }
        SUBCASE("Les données de la classe question à choix multiples")
        {
            REQUIRE_EQ(q.reponse(), reponse);
            REQUIRE(q.reponseJuste(reponse));
        }
    }
}
