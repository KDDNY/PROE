#include "Usluga.h"

Usluga::Usluga(int id, std::string nazwa, int cena) : id(id), nazwa(nazwa), cena(cena) {}

int Usluga::GetCena()
{
	return cena;
}
