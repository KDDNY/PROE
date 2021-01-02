#include "Zapis.h"

Zapis::Zapis(std::string nazwaPliku) : nazwaPliku(nazwaPliku)
{
}

bool Zapis::zapiszOsoby(std::vector<Osoba> osoby)
{
	std::ofstream plik(nazwaPliku);

	if (!plik.is_open())
	{
		return false;
	}

	for (int i = 0; i < osoby.size(); i++)
	{
		plik << osoby[i].toCSV();
	}

	plik.close();

	return true;
}