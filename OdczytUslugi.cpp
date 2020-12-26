#include "OdczytUslugi.h"

OdczytUslugi::OdczytUslugi(std::string nazwaPliku) : nazwaPliku(nazwaPliku)
{
}

std::vector<Usluga> OdczytUslugi::Wczytaj()
{
	std::vector<Usluga> uslugi;

	std::ifstream plik(nazwaPliku);

	if (!plik.is_open())
	{
		return uslugi;
	}

	while (!plik.eof())
	{
		std::string id, nazwa, cena;
		getline(plik, id, ';');
		getline(plik, nazwa, ';');
		getline(plik, cena);
		uslugi.push_back(Usluga(atoi(id.c_str()), nazwa, atoi(cena.c_str())));

	}
	return uslugi;
}
