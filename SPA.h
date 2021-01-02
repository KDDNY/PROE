#pragma once
#include <vector>
#include "Osoba.h"
#include "OdczytOsoby.h"
#include "Usluga.h"
#include "OdczytUslugi.h"
#include "Zapis.h"

class SPA
{
private:
	const std::string OsobyNazwaPliku = "Dane.csv";
	const std::string UslugiNazwaPliku = "Uslugi.csv";
	const std::string ZapisNazwaPliku = "Rozliczenie.csv";

	std::vector<Osoba> kontenerLudzi;
	std::vector<Usluga> kontenerUslug;
	OdczytOsoby odczytOsoby;
	OdczytUslugi odczytUslugi;
	Zapis zapis;

public:
	SPA();
	bool Wczytaj();
	void Przelicz();
	bool Zapisz();
	std::vector<Osoba>& getKontenerLudzi();
};
