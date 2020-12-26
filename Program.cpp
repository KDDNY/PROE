#include "Program.h"

void Program::uruchom()
{
	if (spa.Wczytaj())
	{
		std::cout << "Wczytano dane. " << std::endl;
		spa.Przelicz();
		if (spa.Zapisz())
		{
			std::cout << "Zapisano dane. " << std::endl;
		}
		else
		{
			std::cout << "Nie udalo sie zapisac danych." << std::endl;
		}
	}
	else
	{
		std::cout << "Nie udalo sie wczytac danych." << std::endl;
	}
}
