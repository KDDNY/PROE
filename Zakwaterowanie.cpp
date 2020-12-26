#include "Zakwaterowanie.h"

Zakwaterowanie::Zakwaterowanie(std::string opis, int cena): opis(opis), cena(cena)
{
}

int Zakwaterowanie::getCena() const {
     return cena;
}

std::string Zakwaterowanie::getOpis() const {
     return opis;
}

