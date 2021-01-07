#include "OdczytOsoby.h"

Osoba OdczytOsoby::WczytajOsobe(std::ifstream& file)
{
	std::string id, imie, nazwisko, platnosc, zakwaterowanie, zwierzeta, wyzywienie;
	getline(file, id, ';');
	getline(file, nazwisko, ';');
	getline(file, imie, ';');
	getline(file, platnosc, ';');
	getline(file, zakwaterowanie, ';');
	getline(file, zwierzeta, ';');
	getline(file, wyzywienie, ';');


	Zakwaterowanie zakwaterowanieObj;
	Platnosc platnoscObj;
	Zwierzeta zwierzetaObj;
	Wyzywienie wyzywienieObj;


	for (Zakwaterowanie z : opcje_zakwaterowania)
	{
		if (z.opis == zakwaterowanie)
			zakwaterowanieObj = z;
	}
	for (Platnosc p : opcje_platnosc)
	{
		if (p.opis == platnosc)
			platnoscObj = p;
	}
	for (Zwierzeta z : opcje_zwierzeta)
	{
		if (z.opis == zwierzeta)
			zwierzetaObj = z;
	}
	for (Wyzywienie w : opcje_wyzywienia)
	{
		if (w.opis == wyzywienie)
			wyzywienieObj = w;
	}

	Osoba nowaOsoba(id, nazwisko, imie, platnoscObj, zakwaterowanieObj, zwierzetaObj, wyzywienieObj);
	return nowaOsoba;
}

Osoba OdczytOsoby::stworzOsobe(std::string id, std::string imie, std::string nazwisko, std::string platnosc, std::string zakwaterowanie,
	std::string zwierzeta, std::string wyzywienie) {
	Zakwaterowanie zakwaterowanieObj;
	Platnosc platnoscObj;
	Zwierzeta zwierzetaObj;
	Wyzywienie wyzywienieObj;
	for (Zakwaterowanie z : opcje_zakwaterowania)
	{
		if (z.opis == zakwaterowanie)
			zakwaterowanieObj = z;
	}
	for (Platnosc p : opcje_platnosc)
	{
		if (p.opis == platnosc)
			platnoscObj = p;
	}
	for (Zwierzeta z : opcje_zwierzeta)
	{
		if (z.opis == zwierzeta)
			zwierzetaObj = z;
	}
	for (Wyzywienie w : opcje_wyzywienia)
	{
		if (w.opis == wyzywienie)
			wyzywienieObj = w;
	}

	Osoba nowaOsoba(id, nazwisko, imie, platnoscObj, zakwaterowanieObj, zwierzetaObj, wyzywienieObj);
	return nowaOsoba;
}

OdczytOsoby::OdczytOsoby(std::string nazwaPliku) : nazwaPliku(nazwaPliku)
{
}

std::vector<Osoba> OdczytOsoby::Wczytaj(std::vector<Usluga>& uslugi)
{
	std::vector<Osoba> osoby;

	std::ifstream file(nazwaPliku);

	if (!file.is_open())
	{
		return osoby;
	}

	while (!file.eof())
	{
		Osoba nowaOsoba = WczytajOsobe(file);
		if (file.eof())
		{
			break;
		}

		std::string idUslug;
		getline(file, idUslug);
		//Trzeba sprawdzic czy klient posiada jakiekolwiek uslugi bo inaczej wystepuje blad
		if (idUslug != "") {
			UslugiStream stream(idUslug);
			while (!stream.NastepneId())
			{
				nowaOsoba.dodajUsluge(uslugi[stream.PobierzId() - 1]);
			}
		}
		osoby.push_back(nowaOsoba);

	}
	return osoby;
}
