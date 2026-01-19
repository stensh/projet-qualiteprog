#ifndef ANIMECONTROLEUR_H
#define ANIMECONTROLEUR_H

#include "anime.h"
#include <QList>

class animeControleur
{
    public:
        animeControleur();

    private:
        QList<anime> animes;
};

#endif // ANIMECONTROLEUR_H
