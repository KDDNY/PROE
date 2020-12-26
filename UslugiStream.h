#pragma once
#include <sstream>
#include <string>
class UslugiStream
{
private:
	std::istringstream stream;

public:
	UslugiStream(std::string uslugiStr);
	bool NastepneId();
	int PobierzId();
};

