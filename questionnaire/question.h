#ifndef PROJET_QUESTION_H
#define PROJET_QUESTION_H

#include <string>

namespace sujet
{

class question
{
    public:
        question(const std::string& intitule, const std::string& texte);
        virtual ~question() = default;

        std::string contenu() const;
        std::string intitule() const;
        std::string texte() const;

        virtual std::string reponse() const = 0;

        virtual bool reponseJuste(const std::string& reponse) const = 0;

    private:
        std::string d_intitule;
        std::string  d_texte;
};

}
#endif //PROJET_QUESTION_H