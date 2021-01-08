#include "OdczytUslugi.h"

OdczytUslugi::OdczytUslugi(std::string nazwaPliku) : nazwaPliku(nazwaPliku)
{
}

std::vector<Usluga> OdczytUslugi::WczytajDaneUslugi(std::vector<int> idVector)
{
	std::vector<Usluga> uslugi;
		for (auto el : idVector) {
			std::ifstream plik(nazwaPliku);
			while (!plik.eof()) {
				std::string id, nazwa, cena;
				getline(plik, id, ';');
				if (std::to_string(el) == id) {
					getline(plik, nazwa, ';');
					getline(plik, cena);
					uslugi.push_back(Usluga(atoi(id.c_str()), nazwa, atoi(cena.c_str())));
				}
				else {
					getline(plik, nazwa, ';');
					getline(plik, cena);
				}
			}
			plik.close();
		}
	return uslugi;
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

