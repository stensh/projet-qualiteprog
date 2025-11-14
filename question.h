//
// Created by surab on 11/14/2025.
//

#ifndef PROJET_QUESTION_H
#define PROJET_QUESTION_H
#include <string>

class question
{
public:
    question(const std::string& intitule, const std::string& texte);
    virtual ~question() = default ;
    std::string renvoieQuestion() const;
    std::string intituleQuestion() const;
    std::string texteQuestion() const;
private:
    std::string d_intitule;
    std::string  d_texte;
};


#endif //PROJET_QUESTION_H