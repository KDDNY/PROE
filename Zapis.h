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
public:
	Zapis(std::string nazwaPliku);
	bool zapiszOsoby(std::vector<Osoba> osoby);
};