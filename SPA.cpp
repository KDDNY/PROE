#include "SPA.h"

SPA::SPA() : odczytOsoby(OsobyNazwaPliku), odczytUslugi(UslugiNazwaPliku), zapis(ZapisNazwaPliku, OsobyNazwaPliku)
{
}

bool SPA::Wczytaj()
{
    kontenerUslug = odczytUslugi.Wczytaj();
    kontenerLudzi = odczytOsoby.Wczytaj(kontenerUslug);

    if (kontenerLudzi.size() == 0 || kontenerUslug.size() == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void SPA::Przelicz()
{
    for (int i = 0; i < kontenerLudzi.size(); i++)
    {
        kontenerLudzi[i].obliczCene();
    }
}

bool SPA::Zapisz()
{
    if (kontenerLudzi.size() == 0)
    {
        return false;
    }
    return zapis.zapiszOsoby(kontenerLudzi);
}

bool SPA::ZapiszDane()
{
    if (kontenerLudzi.size() == 0)
    {
        return false;
    }
    return zapis.zapiszOsobyDane(kontenerLudzi);
}

std::vector<Osoba>& SPA::getKontenerLudzi()
{
    return kontenerLudzi;
}