#pragma once
#include <vector>
#include <string>
#include "Osoba.h"
#include "Usluga.h"
#include <fstream>
#include <sstream>
#include "UslugiStream.h"

class OdczytOsoby
{
private:
	std::string nazwaPliku;
	Osoba WczytajOsobe(std::ifstream& plik);
	std::vector<Zwierzeta> opcje_zwierzeta = { Zwierzeta("tak", 50), Zwierzeta("nie", 0) };
	std::vector<Platnosc> opcje_platnosc = { Platnosc("na miejscu", 10), Platnosc("online", 0) };
	std::vector<Zakwaterowanie> opcje_zakwaterowania = { Zakwaterowanie("Penthouse",1000), Zakwaterowanie("Standard",500), Zakwaterowanie("Standard Family",600), Zakwaterowanie("VIP",2000) };
	std::vector<Wyzywienie> opcje_wyzywienia = { Wyzywienie("3posilki", 150), Wyzywienie("5posilkow", 300), Wyzywienie("roomservice", 200) };

public:
	OdczytOsoby(std::string nazwaPliku);
	OdczytOsoby() = default;
	~OdczytOsoby() = default;
	std::vector<Osoba> Wczytaj(std::vector<Usluga>& uslugi);
	Osoba stworzOsobe(std::string id, std::string imie, std::string nazwisko, std::string platnosc, std::string zakwaterowanie,
		std::string zwierzeta, std::string wyzywienie);
};
