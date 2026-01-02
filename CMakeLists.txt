cmake_minimum_required(VERSION 3.10)
project(projet-qualiteprog)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

# Application principale OK
add_executable(main
        main.cpp
        apprentissage/apprentissage.h
        apprentissage/apprentissage.cpp
        evaluation/evaluation.h
        evaluation/evaluation.cpp
        evaluation/evaluationAdaptative.h
        evaluation/evaluationAdaptative.cpp
        evaluation/evaluationSecondeChance.h
        evaluation/evaluationSecondeChance.cpp
        evaluation/evaluationTest.h
        evaluation/evaluationTest.cpp
        evaluation/gestionnaireEvaluation.h
        evaluation/gestionnaireEvaluation.cpp
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
        questionnaire/gestionnaireQuestionnaire.h
        questionnaire/reponse.h
        questionnaire/reponse.cpp
)

# Test unitaire OK
add_executable(Doctest_questionnaire
        test/testmain.cpp
        questionnaire/reponse.cpp
        questionnaire/question.cpp
        questionnaire/questionTexte.cpp
        questionnaire/questionNumerique.cpp
        questionnaire/questionChoixMultiples.cpp
        questionnaire/questionnaire.cpp
        questionnaire/gestionnaireQuestionnaire.cpp
        test/test_reponse.cpp
        test/test_question.cpp
        test/test_questionnaire.cpp
        test/test_gestionnaireQuestionnaire.cpp
)

add_executable(Doctest_evaluation
        test/testmain.cpp
        evaluation/evaluation.cpp
        evaluation/evaluationTest.cpp
        evaluation/evaluationAdaptative.cpp
        evaluation/evaluationSecondeChance.cpp
        questionnaire/reponse.cpp
        questionnaire/question.cpp
        questionnaire/questionTexte.cpp
        questionnaire/questionNumerique.cpp
        questionnaire/questionChoixMultiples.cpp
        questionnaire/questionnaire.cpp
        test/test_evaluation.cpp
        test/test_evaluationTest.cpp
        test/test_evaluationAdaptative.cpp
        test/test_evaluationSecondeChance.cpp
        test/test_reponse.cpp
)
