#pragma once
#include <vector>
#include "Usluga.h"
#include <fstream>
#include <string>
#include <iostream>
class OdczytUslugi
{
private:
	std::string nazwaPliku;
public:
	OdczytUslugi(std::string nazwaPliku);
	std::vector<Usluga> Wczytaj();

};
