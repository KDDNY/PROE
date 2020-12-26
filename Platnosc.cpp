#include "Platnosc.h"

Platnosc::Platnosc(std::string opis, int cena): opis(opis), cena(cena)
{
}

int Platnosc::getCena() const {
     return cena;
}

std::string Platnosc::getOpis() const {
     return opis;
}