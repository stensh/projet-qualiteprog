#include "doctest.h"
#include "gestionnaireQuestionnaire.h"
#include "questionnaire.h"

TEST_CASE("Test des différents codes d'erreurs")
{
    SUBCASE("Code de retour 0")
    {
        std::string nomFichier = "QuestionnaireDoctestCode0.txt";
        sujet::questionnaire q{nomFichier};
        sujet::gestionnaireQuestionnaire gq;
        REQUIRE_EQ(gq.chargeQuestionnaire(&q),0);
    }
    SUBCASE("Code de retour 1")
    {
        std::string nomFichier = "QuestionnaireInexistantCode1.txt";
        sujet::questionnaire q{nomFichier};
        sujet::gestionnaireQuestionnaire gq;
        REQUIRE_EQ(gq.chargeQuestionnaire(&q),1);
    }
    SUBCASE("Code de retour 2")
    {
        std::string nomFichier = "QuestionnaireDoctestCode2.txt";
        sujet::questionnaire q{nomFichier};
        sujet::gestionnaireQuestionnaire gq;
        REQUIRE_EQ(gq.chargeQuestionnaire(&q),2);
    }
    SUBCASE("Code de retour 3")
    {
        std::string nomFichier = "QuestionnaireDoctestCode3.txt";
        sujet::questionnaire q{nomFichier};
        sujet::gestionnaireQuestionnaire gq;
        REQUIRE_EQ(gq.chargeQuestionnaire(&q),3);
    }
}