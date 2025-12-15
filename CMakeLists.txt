cmake_minimum_required(VERSION 4.0)
project(projet-qualiteprog)

set(CMAKE_CXX_STANDARD 14)

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
        evaluation/gestionnaireEvaluation.cpp
        evaluation/testsDoctest/test_evaluation.cpp
        evaluation/testsDoctest/test_evaluationTest.cpp
        evaluation/testsDoctest/test_evaluationAdaptative.cpp
        evaluation/testsDoctest/test_gestionnaireEvaluation.cpp)

