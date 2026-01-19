#include "saison.h"

saison::saison(std::vector<episode>episodes):
    d_episodes{episodes}
{}

void saison::ajouterEpisode(const episode& ep)
{
    if(ep.numero()>=d_episodes.size() || ep.numero()>=d_episodes.back().numero())
    {
        d_episodes.push_back(ep);
    }
    else
    {
        d_episodes.insert(d_episodes.begin()+ep.numero(), ep);
    }
}
void saison::retireEpisode(double numero)
{
    if(!d_episodes.empty() and numero<d_episodes.size())
    {
        int i{0};
        while(i<d_episodes.size() and d_episodes[i].numero()!=numero)
        {
            ++i;
        }
        if(i!=d_episodes.size())
        {
            d_episodes.erase(d_episodes.begin()+i);
        }
    }
}

int saison::nombreEpisode() const
{
    return d_episodes.size();
}

double saison::numeroSaison() const
{
    return d_numeroSaison;
}

void saison::numeroSaison(double numeroSaison)
{
    d_numeroSaison=numeroSaison;
}
