#pragma once
#include <string>

class Zakwaterowanie
{
public:
    Zakwaterowanie() = default;
    Zakwaterowanie(std::string opis, int cena);
    int getCena() const;
    std::string getOpis() const;

    int cena = 0;
    std::string opis;

};

