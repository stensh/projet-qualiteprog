#include "doctest.h"
#include "questionnaire.h"

#include <memory>
#include <string>

#include "questionChoixMultiples.h"
#include "questionNumerique.h"
#include "questionTexte.h"



TEST_CASE("Le questionnaire est bien construit")
{
    std::string nomFichier{};
    sujet::questionnaire q{nomFichier};
    SUBCASE("Les données sont bien initialisées")
    {
       REQUIRE_EQ(nomFichier,q.nomFichier());
       REQUIRE_FALSE(q.nombreQuestions());
    }
}

TEST_CASE("L'ajout d'une question se déroule normalement")
{
    std::string nomFichier{};
    sujet::questionnaire quest{nomFichier};


    SUBCASE("La question ajouté est une question numérique")
    {

        quest.ajouteQuestion(std::make_unique<sujet::questionNumerique>("intitule","texte",45,50));

        REQUIRE_EQ(quest.nombreQuestions(),1);
        REQUIRE_NE(dynamic_cast<sujet::questionNumerique*>(&quest.questionCourante(0)),nullptr);
    }


    SUBCASE("La question ajouté est une question texte")
    {
        quest.ajouteQuestion(std::make_unique<sujet::questionTexte>("intitule","texte","reponse"));

        sujet::questionTexte q{"","",""};
         REQUIRE_EQ(quest.nombreQuestions(),1);
         REQUIRE_NE(dynamic_cast<sujet::questionTexte*>(&quest.questionCourante(0)) ,nullptr);
    }


    SUBCASE("La question ajoutée est une question à choix multiples")
    {
        quest.ajouteQuestion(std::make_unique<sujet::questionChoixMultiples>("texte","intitule",2));

        REQUIRE_EQ(quest.nombreQuestions(),1);
        REQUIRE_NE(dynamic_cast<sujet::questionChoixMultiples*>(&quest.questionCourante(0)), nullptr);
    }
}