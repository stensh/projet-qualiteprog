#ifndef SAISON_H
#define SAISON_H

#include <vector>
#include "episode.h"

class saison
{
    public:
        saison(const std::vector<episode>episodes);

        void ajouterEpisode(const episode& ep);
        void retireEpisode(double numero);

        int nombreEpisode() const;
        double numeroSaison() const;

        void numeroSaison(double numeroSaison);




    private:
        double d_numeroSaison;
        std::vector<episode> d_episodes;
};

#endif // SAISON_H
