#pragma once
#include <iostream>
#include "Usluga.h"
#include "Zakwaterowanie.h"
#include "Zwierzeta.h"
#include "Platnosc.h"
#include "Wyzywienie.h"
#include <string>
#include <vector>


class Osoba
{
private:
	std::string id;
	std::string nazwisko;
	std::string imie;
	Platnosc platnosc;
	Zakwaterowanie zakwaterowanie;
	Zwierzeta zwierzeta;
	Wyzywienie wyzywienie;
	std::vector<Usluga> kupioneUslugi;
	int cena = 0;

public:
	Osoba(std::string id, std::string nazwisko, std::string imie, Platnosc platnosc, Zakwaterowanie zakwaterowanie, Zwierzeta zwierzeta, Wyzywienie kulinaria);

	void dodajUsluge(Usluga& u);

	void zmien(Zakwaterowanie& z);

	void zmien(Platnosc& p);

	void zmien(Zwierzeta& z);

	void zmien(Wyzywienie& w);

	void obliczCene();

	std::string getPersonalInformation();

	Platnosc getPlatnosc();
	Zakwaterowanie getZakwaterowanie();
	Zwierzeta getZwierzeta();
	Wyzywienie getWyzywienie();
	std::vector<Usluga> getKupioneUslugi();
	std::string getID();
	std::string getImie();
	std::string getNazwisko();
	int getCena();

	std::string toCSV();

};

