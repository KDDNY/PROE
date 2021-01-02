#include "Usluga.h"

Usluga::Usluga(int id, std::string nazwa, int cena) : id(id), nazwa(nazwa), cena(cena) {}

int Usluga::GetCena()
{
	return cena;
}

int Usluga::getId()
{
	return id;
}

std::string Usluga::getNazwa()
{
	return nazwa;
}
