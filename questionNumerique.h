//
// Created by surab on 11/14/2025.

#ifndef PROJET_QUALITEPROG_QUESTIONNUMERIQUE_H
#define PROJET_QUALITEPROG_QUESTIONNUMERIQUE_H
#include <string>
#include "question.h"

class questionNumerique: public question
{
public:
    questionNumerique(std::string intitule,std::string texte,int reponse);
    int reponse() const ;
private:
    int d_reponse;
};


#endif //PROJET_QUALITEPROG_QUESTIONNUMERIQUE_H