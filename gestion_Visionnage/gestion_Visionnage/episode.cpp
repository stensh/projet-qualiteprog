#include "episode.h"

episode::episode(double numero, const QString& lien, bool download, bool vu):
    d_numero{numero}, d_lien{lien}, d_download{download}, d_vu{vu}
{}

double episode::numero() const
{
    return d_numero;
}

void episode::numero(double numero)
{
    d_numero=numero;
}

QString episode::lien() const
{
    return d_lien;
}

void episode::lien(const QString& lien)
{
    d_lien=lien;
}

bool episode::download() const
{
    return d_download;
}

void episode::download(bool download)
{
    d_download=download;
}

bool episode::vu()const
{
    return d_vu;
}

void episode::vu(bool vu)
{
    d_vu=vu;
}
