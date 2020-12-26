#pragma once

#include <string>

class Platnosc
{
public:
    Platnosc() = default;
    Platnosc(std::string opis, int cena);
    int getCena() const;
    std::string getOpis() const;

    int cena = 0;
    std::string opis;

};

