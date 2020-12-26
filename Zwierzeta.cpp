#include "Zwierzeta.h"

Zwierzeta::Zwierzeta(std::string opis, int cena): opis(opis), cena(cena)
{
}

int Zwierzeta::getCena() const {
     return cena;
}

std::string Zwierzeta::getOpis() const {
     return opis;
}
