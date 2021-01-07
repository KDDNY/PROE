#pragma once

#include "Osoba.h"
#include "Usluga.h"
#include <vector>
#include <fstream>
#include <string>

class Zapis
{
private:
	std::string nazwaPliku;
	std::string nazwaPlikuDane;
public:
	Zapis(std::string nazwaPliku, std::string nazwaPlikuDane);
	bool zapiszOsoby(std::vector<Osoba> osoby);
	bool zapiszOsobyDane(std::vector<Osoba> osoby);
};