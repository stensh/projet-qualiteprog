#include <sstream>
#include "test/doctest.h"
#include "questionnaire/gestionnaireQuestionnaire.h"
#include "questionnaire/questionnaire.h"

TEST_CASE("Test des différents codes d'erreurs")
{
    int code;
    SUBCASE("Code de retour 1")
    {
        std::string nomFichier = "../QuestionnaireInexistantCode1.txt";
        sujet::questionnaire q{nomFichier};
        sujet::gestionnaireQuestionnaire gq;
        gq.chargeQuestionnaire(q,code);
        REQUIRE_EQ(code,1);
    }
    SUBCASE("Code de retour 2")
    {
        std::string nomFichier = "../test/QuestionnaireDoctestCode2.txt";
        sujet::questionnaire q{nomFichier};
        sujet::gestionnaireQuestionnaire gq;
        gq.chargeQuestionnaire(q,code);
        REQUIRE_EQ(code,2);
    }
}

TEST_CASE("Test de la fonction creeQuestion")
{
    sujet::gestionnaireQuestionnaire gq{};

    SUBCASE("Création infructueuse à cause d'une erreur de balise")
    {
        std::string balise = "Balise erronée";
        std::ifstream fichier;
        REQUIRE_EQ(gq.creeQuestion(balise, fichier), nullptr);
    }

    SUBCASE("Créer une question texte")
    {
        std::string balise = "[QT]";
        std::istringstream fichier("Culture cinématographique\n"
                                    "Quel est le vrai nom de The Rock ?\n"
                                    "Dwayne Johnson\n");
        auto question = gq.creeQuestion(balise, fichier);
        REQUIRE_NE(question, nullptr);
    }

    SUBCASE("Créer une question numérique")
    {
        std::string balise = "[QN]";
        std::istringstream fichier("Culture générale\n"
                                    "A quelle distance se trouve la lune de la terre en kilomètre ?\n"
                                    "370000 410000\n");
        auto question = gq.creeQuestion(balise, fichier);
        REQUIRE_NE(question, nullptr);
    }

    SUBCASE("Créer une question à choix multiple")
    {
        std::string balise = "[QCM]";
        std::istringstream fichier("Evidence\n"
                                    "Pourquoi n'a-t-on pas gravé la tête de Chuck Norris dans le mont Rushmore ?\n"
                                    "Les gens ne le connaissaient pas\n"
                                    "La pierre n'était pas assez dure pour le représenter\n"
                                    "Personne ne grave Chuck Norris\n"
                                    "C'était des incultes\n"
                                    "2\n");
        auto question = gq.creeQuestion(balise, fichier);
        REQUIRE_NE(question, nullptr);
    }
}

TEST_CASE("Test de la fonction lireQuestionNum")
{
    SUBCASE("Lecture correcte d'une question numérique")
    {
        sujet::gestionnaireQuestionnaire gq{};
        std::istringstream fichier("Test\n"
                                    "Question test\n"
                                    "10 20\n");
        auto question = gq.lireQuestionNum(fichier);
        REQUIRE_EQ(question->intitule(), "Test");
        REQUIRE_EQ(question->texte(), "Question test");
        REQUIRE_EQ(question->limiteMin(), 10);
        REQUIRE_EQ(question->limiteMax(), 20);
    }
}

TEST_CASE("Test de la fonction lireQuestionTxt")
{
    SUBCASE("Lecture correcte d'une question texte")
    {
        sujet::gestionnaireQuestionnaire gq{};
        std::istringstream fichier("Catégorie\n"
                                    "Question ?\n"
                                    "Réponse attendue\n");
        auto question = gq.lireQuestionTxt(fichier);
        REQUIRE_EQ(question->intitule(), "Catégorie");
        REQUIRE_EQ(question->texte(), "Question ?");
        REQUIRE_EQ(question->reponse(), "Réponse attendue");
    }
}

TEST_CASE("Test de la fonction lireQuestionChoixMultiples")
{

    SUBCASE("Lecture correcte d'une question à choix multiples")
    {
        sujet::gestionnaireQuestionnaire gq{};
        std::istringstream fichier("Test\n"
                                    "Question test ?\n"
                                    "Choix 1\n"
                                    "Choix 2\n"
                                    "Choix 3\n"
                                    "Choix 4\n"
                                    "3\n");
        auto question = gq.lireQuestionChoixMultiples(fichier);
        REQUIRE_EQ(question->intitule(), "Test");
        REQUIRE_EQ(question->texte(), "Question test ?\nChoix 1\nChoix 2\nChoix 3\nChoix 4");
        REQUIRE_EQ(question->reponse(), "3");
    }
}

TEST_CASE("Test de la fonction valideEntete")
{
    sujet::gestionnaireQuestionnaire gq{};

    SUBCASE("Entête valide")
    {
        std::istringstream fichier("CECI EST UN QUESTIONNAIRE\n{\n");
        REQUIRE(gq.valideEntete(fichier));
    }

    SUBCASE("Entête invalide - mauvaise première ligne")
    {
        std::istringstream fichier("CECI N'EST PAS UN QUESTIONNAIRE\n{\n");
        REQUIRE_FALSE(gq.valideEntete(fichier));
    }

    SUBCASE("Entête invalide - accolade manquante")
    {
        std::istringstream fichier("CECI EST UN QUESTIONNAIRE\n[\n");
        REQUIRE_FALSE(gq.valideEntete(fichier));
    }

    SUBCASE("Entête invalide - ligne vide au lieu de l'accolade")
    {
        std::istringstream fichier("CECI EST UN QUESTIONNAIRE\n\n");
        REQUIRE_FALSE(gq.valideEntete(fichier));
    }
}

TEST_CASE("Test de la fonction analyseQuestions")
{
    sujet::gestionnaireQuestionnaire gq{};
    int code;
    std::string nomFichier = {};
    sujet::questionnaire q{nomFichier};
    SUBCASE("Analyse réussie avec plusieurs questions")
    {
        std::istringstream fichier("[QT]\n"
                                    "Cat1\n"
                                    "Question 1\n"
                                    "Réponse 1\n"
                                    "[QN]\n"
                                    "Cat2\n"
                                    "Question 2\n"
                                    "1 10\n"
                                    "}\n");
        gq.analyseQuestions(q, fichier, code);
        REQUIRE_EQ(code, 0);
    }

    SUBCASE("Analyse échouée avec balise invalide")
    {
        std::istringstream fichier("[QX]\n"
                                    "Cat1\n"
                                    "Question 1\n"
                                    "}\n");
        gq.analyseQuestions(q, fichier, code);
        REQUIRE_EQ(code, 3);
    }

    SUBCASE("Analyse d'un questionnaire vide")
    {
        std::istringstream fichier("}\n");
        gq.analyseQuestions(q, fichier, code);
        REQUIRE_EQ(code, 0);
    }
}

TEST_CASE("Chargement d'un questionnaire complet valide")
{
    std::string nomFichier = "../test/QuestionnaireDoctestCode0.txt";
    sujet::questionnaire q{nomFichier};
    sujet::gestionnaireQuestionnaire gq;
    int code;
    gq.chargeQuestionnaire(q,code);
    REQUIRE_EQ(code, 0);
}

TEST_CASE("Test la taille d'un questionnaire")
{
    SUBCASE("Taille par défaut égal 0")
    {
        sujet::questionnaire q{};
        REQUIRE_EQ(q.taille(), 0);
    }
    SUBCASE("Taille augmente après ajout de question")
    {
        sujet::questionnaire q{};
        auto qTexte(std::make_unique<sujet::questionTexte>("intitule", "texte", "reponse"));
        q.ajouteQuestion(std::move(qTexte));
        REQUIRE_EQ(q.taille(), 1);
    }
}