#pragma once
#include <iostream>
#include <string>
class Usluga
{
private:
	int id;
	std::string nazwa;
	int cena = 0;
public:
	Usluga(int id, std::string nazwa, int cena);

	int GetCena();
	int getId();
	std::string getNazwa();
};

