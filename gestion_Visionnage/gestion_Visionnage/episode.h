#ifndef EPISODE_H
#define EPISODE_H

#include <QString>

class episode
{
    public:
        episode(double numero, const QString& lien, bool download, bool vu);

        //Obtenir les données
        double numero() const;
        QString lien() const;
        bool download() const;
        bool vu() const;

        //Modifier les données
        void numero(double numero);
        void lien(const QString& lien);
        void download(bool download);
        void vu(bool vu);


    private:
        double d_numero;   //le numéro de l'épisode en double pour les épisodes intermédiaire.
        QString d_lien; //Lien vers l'épisode.
        bool d_download;  //true si sur le disque.
        bool d_vu;    //true si déjà vu.
};

#endif // EPISODE_H
