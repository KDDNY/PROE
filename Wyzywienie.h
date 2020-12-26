#ifndef WYZYWIENIE_H
#define WYZYWIENIE_H

#include <string>

class Wyzywienie
{
public:
    Wyzywienie() = default;
    Wyzywienie(std::string opis, int cena);
    int getCena() const;
    std::string getOpis() const;

    int cena = 0;
    std::string opis;

};

#endif
