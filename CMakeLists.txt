cmake_minimum_required(VERSION 4.0)
project(projet-qualiteprog)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

# Application principale
add_executable(main
        main.cpp
        evaluation/evaluation.h
        evaluation/evaluation.cpp
        evaluation/evaluationAdaptative.h
        evaluation/evaluationAdaptative.cpp
        evaluation/evaluationSecondeChance.h
        evaluation/evaluationSecondeChance.cpp
        evaluation/evaluationTest.h
        evaluation/evaluationTest.cpp
        evaluation/gestionnaireEvaluation.h
        evaluation/gestionnaireEvaluation.cpp)

# Questionnaire
add_executable(projet_qualiteprog
        main.cpp
        questionnaire/question.cpp
        questionnaire/question.h
        questionnaire/questionnaire.cpp
        questionnaire/questionnaire.h
        questionnaire/questionTexte.cpp
        questionnaire/questionTexte.h
        questionnaire/questionNumerique.cpp
        questionnaire/questionNumerique.h
        questionnaire/questionChoixMultiples.cpp
        questionnaire/questionChoixMultiples.h
        questionnaire/gestionnaireQuestionnaire.cpp
        questionnaire/gestionnaireQuestionnaire.h)

# Test unitaire
add_executable(test
        test/testmain.cpp
        questionnaire/reponse.cpp
        test/reponseTest.cpp
        questionnaire/question.cpp
        questionnaire/questionTexte.cpp
        questionnaire/questionNumerique.cpp
        questionnaire/questionChoixMultiples.cpp
        test/questionTest.cpp
        questionnaire/questionnaire.cpp
        test/questionnaireTest.cpp
        questionnaire/gestionnaireQuestionnaire.cpp
        test/gestionnaireQuestionnaireTest.cpp)