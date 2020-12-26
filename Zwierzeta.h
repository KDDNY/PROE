#pragma once
#include <string>

class Zwierzeta
{
public:
    Zwierzeta() = default;
    Zwierzeta(std::string opis, int cena);
    int getCena() const;
    std::string getOpis() const;

    int cena = 0;
    std::string opis;

};

