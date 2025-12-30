#include  "test/doctest.h"
#include  "questionnaire/reponse.h"

#include  <string>

TEST_CASE("La réponse est bien construite et opérationelle")
{
    std::string s = "Hello World";
    test::reponse rep{s};
    SUBCASE("Les données testées sont bien assignées")
    {
        REQUIRE_EQ(rep.donnee(),s);
        REQUIRE_FALSE(rep.valide());
    }
    SUBCASE("Le changement de validité est opérationnel")
    {
        bool validite{false};
        rep.changeValidite(validite);
        REQUIRE_EQ(rep.valide(),validite);
    }
}
