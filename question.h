//
// Created by surab on 11/14/2025.
//

#ifndef PROJET_QUESTION_H
#define PROJET_QUESTION_H
#include <string>

class question
{
public:
    question(std::string intitule, std::string texte);
    virtual ~question() = default ;
    void afficherQuestion();

private:
    std::string d_intitule;
    std::string  d_texte;
};


#endif //PROJET_QUESTION_H