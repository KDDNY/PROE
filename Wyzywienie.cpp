#include "Wyzywienie.h"

Wyzywienie::Wyzywienie(std::string opis, int cena): opis(opis), cena(cena)
{
}

int Wyzywienie::getCena() const {
     return cena;
}

std::string Wyzywienie::getOpis() const {
     return opis;
}