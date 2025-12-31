cmake_minimum_required(VERSION 3.10)
project(projet-qualiteprog)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

# Test unitaire OK
add_executable(
    test_questionnaire
    test/testmain.cpp
    questionnaire/reponse.cpp
    test/test_reponse.cpp
    questionnaire/question.cpp
    questionnaire/questionTexte.cpp
    questionnaire/questionNumerique.cpp
    questionnaire/questionChoixMultiples.cpp
    test/test_question.cpp
    questionnaire/questionnaire.cpp
    test/test_questionnaire.cpp
    questionnaire/gestionnaireQuestionnaire.cpp
    test/test_gestionnaireQuestionnaire.cpp
)

#Apprentissage OK
add_executable(
        testApprentissage
    main.cpp
    apprentissage/apprentissage.h
    apprentissage/apprentissage.cpp
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
    apprentissage/apprentissage.cpp
)

# Questionnaire
add_executable(
        questionnaire
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
    questionnaire/reponse.cpp
    questionnaire/reponse.h
)

# Application principale
add_executable(
        main
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

add_executable(
        evaluation
    evaluation/evaluation.h
    evaluation/evaluation.cpp
    evaluation/evaluationAdaptative.h
    evaluation/evaluationAdaptative.cpp
    evaluation/evaluationSecondeChance.h
    evaluation/evaluationSecondeChance.cpp
    evaluation/evaluationTest.h
)
