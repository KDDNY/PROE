#include "Osoba.h"

Osoba::Osoba(std::string id, std::string nazwisko, std::string imie, Platnosc platnosc, Zakwaterowanie zakwaterowanie, Zwierzeta zwierzeta, Wyzywienie kulinaria)
	: id(id), nazwisko(nazwisko), imie(imie), platnosc(platnosc), zakwaterowanie(zakwaterowanie), zwierzeta(zwierzeta), wyzywienie(kulinaria), cena(0)
{}

void Osoba::dodajUsluge(Usluga& u)
{
	kupioneUslugi.push_back(u);
}

void Osoba::zmien(Zakwaterowanie& z)
{
	this->zakwaterowanie = z;
}

void Osoba::zmien(Platnosc& p)
{
	this->platnosc = p;
}

void Osoba::zmien(Zwierzeta& z)
{
	this->zwierzeta = z;
}

void Osoba::zmien(Wyzywienie& w)
{
	this->wyzywienie = w;
}

void Osoba::obliczCene()
{
	cena = 0;
	for (Usluga u : kupioneUslugi)
	{
		cena += u.GetCena();
	}
	//platnosc
	cena += platnosc.cena;
	//zakwaterowanie
	cena += zakwaterowanie.cena;
	//zwierzeta
	cena += zwierzeta.cena;
	//kulinaria
	cena += wyzywienie.cena;
}

std::string Osoba::getPersonalInformation()
{
	return id + " " + imie + " " + nazwisko;
}

std::string Osoba::getID()
{
	return id;
}

std::string Osoba::getImie()
{
	return imie;
}

std::string Osoba::getNazwisko()
{
	return nazwisko;
}

int Osoba::getCena()
{
	return cena;
}

std::string Osoba::toCSV()
{
	return id + ";" + nazwisko + ";" + imie + ";" + std::to_string(cena) + "\n";
}