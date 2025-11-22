#ifndef PROJET_QUALITEPROG_REPONSE_H
#define PROJET_QUALITEPROG_REPONSE_H
#include <string>

namespace test
{
    class reponse
    {
        public:
            reponse(const std::string& donnee);
            std::string donnee() const;
            bool valide() const;
            void changeValidite(bool validite);
        private:
            std::string d_donnee;
            bool d_valide;
    };
} // test

#endif //PROJET_QUALITEPROG_REPONSE_H