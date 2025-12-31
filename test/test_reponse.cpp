#include  <string>
#include  "test/doctest.h"
#include  "questionnaire/reponse.h"

TEST_CASE("La réponse est bien construite et fonctionne")
{
    std::string s = "Hello World";
    test::reponse rep{s};

    SUBCASE("Les données testées sont bien assignées")
    {
        REQUIRE_EQ(rep.donnee(),s);
        REQUIRE_FALSE(rep.valide());
    }

    SUBCASE("Le changement de validité fonctionne")
    {
        SUBCASE("Changer de false à false fonctionne")
        {
            bool validite{false};
            rep.changeValidite(validite);
            REQUIRE_EQ(rep.valide(),validite);
        }

        SUBCASE("Changer de false à true fonctionne")
        {
            bool validite{true};
            rep.changeValidite(validite);
            REQUIRE_EQ(rep.valide(),validite);
        }

        SUBCASE("Changer de true à false fonctionne")
        {
            rep.changeValidite(true);
            REQUIRE_UNARY(rep.valide());
            rep.changeValidite(false);
            REQUIRE_FALSE(rep.valide());
        }

        SUBCASE("Changer de true à true fonctionne")
        {
            rep.changeValidite(true);
            REQUIRE_UNARY(rep.valide());
            rep.changeValidite(true);
            REQUIRE_UNARY(rep.valide());
        }
    }
}
