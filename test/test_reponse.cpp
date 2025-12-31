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
        SUBCASE("Changer de false à false")
        {
            bool validite{false};
            rep.changeValidite(validite);
            REQUIRE_EQ(rep.valide(),validite);
        }
        SUBCASE("Changer de false à true")
        {
            bool validite{true};
            rep.changeValidite(validite);
            REQUIRE_EQ(rep.valide(),validite);
        }
        SUBCASE("Changer de true à false")
        {
            rep.changeValidite(true);
            REQUIRE_UNARY(rep.valide());
            rep.changeValidite(false);
            REQUIRE_FALSE(rep.valide());
        }
        SUBCASE("Changer de true à true")
        {
            rep.changeValidite(true);
            REQUIRE_UNARY(rep.valide());
            rep.changeValidite(true);
            REQUIRE_UNARY(rep.valide());
        }
    }
}
