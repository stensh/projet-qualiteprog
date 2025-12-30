#include <memory>
#include <string>

#include "test/doctest.h"
#include "questionnaire/questionnaire.h"
#include "questionnaire/questionChoixMultiples.h"
#include "questionnaire/questionNumerique.h"
#include "questionnaire/questionTexte.h"


TEST_CASE("Le questionnaire est bien construit")
{
    SUBCASE("Questionnaire par défaut bien construit")
    {
        sujet::questionnaire q{};
        REQUIRE_EQ("",q.nomFichier());
        REQUIRE_FALSE(q.taille());
    }
    SUBCASE("Questionnaire avec un nom de fichier bien construit")
    {
        std::string nomFichier{};
        sujet::questionnaire q{nomFichier};
        REQUIRE_EQ(nomFichier,q.nomFichier());
        REQUIRE_FALSE(q.taille());
    }
}

TEST_CASE("L'ajout d'une question se déroule normalement")
{
    std::string nomFichier{};
    sujet::questionnaire quest{nomFichier};


    SUBCASE("La question ajouté est une question numérique")
    {

        quest.ajouteQuestion(std::make_unique<sujet::questionNumerique>("intitule","texte",45,50));

        REQUIRE_EQ(quest.taille(),1);
        REQUIRE_NE(dynamic_cast<sujet::questionNumerique*>(quest.questionIndice(0).get()),nullptr);
    }


    SUBCASE("La question ajouté est une question texte")
    {
        quest.ajouteQuestion(std::make_unique<sujet::questionTexte>("intitule","texte","reponse"));

        sujet::questionTexte q{"","",""};
         REQUIRE_EQ(quest.taille(),1);
         REQUIRE_NE(dynamic_cast<sujet::questionTexte*>(quest.questionIndice(0).get()) ,nullptr);
    }


    SUBCASE("La question ajoutée est une question à choix multiples")
    {
        quest.ajouteQuestion(std::make_unique<sujet::questionChoixMultiples>("texte","intitule",2));

        REQUIRE_EQ(quest.taille(),1);
        REQUIRE_NE(dynamic_cast<sujet::questionChoixMultiples*>(quest.questionIndice(0).get()), nullptr);
    }
}

TEST_CASE("Les questionnaire est bien vidé")
{
    sujet::questionnaire quest{};
    SUBCASE("Un questionnaire vide est bien vidé")
    {
        quest.videQuestionnaire();
        REQUIRE_EQ(quest.taille(),0);
    }
    SUBCASE("Un questionnaire contenant une question est bien vidé")
    {
        quest.ajouteQuestion(std::make_unique<sujet::questionNumerique>("intitule","texte",45,50));
        quest.videQuestionnaire();
        REQUIRE_EQ(quest.taille(),0);
    }
}