#ifndef ANIME_H
#define ANIME_H

#include "saison.h"
#include <QDate>

class anime
{
    public:
        anime();

        int nombreSaison() const;
        void ajouterSaison(const saison& s);
        void supprimerSaison(int numeroSaison);

        bool enCoursDeDiffusion() const;
        void enCoursDeDiffusion(bool diffusion);
        QString id() const;
        void id(const QString& id);
        QString nom() const;
        void nom(const QString& nom);
        QString commentaire() const;
        void commentaire(const QString& commentaire);
        QDate dateSortie() const;
        void dateSortie(const QDate& dateSortie);


    private:
        bool d_enCoursDeDiffusion;
        std::vector<saison> d_saison;
        QString d_id;
        QString d_nom;
        QString d_commentaire;
        QDate d_dateSortie;

};

#endif // ANIME_H
