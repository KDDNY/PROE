#include "UslugiStream.h"

UslugiStream::UslugiStream(std::string uslugiStr) : stream(uslugiStr) {}

bool UslugiStream::NastepneId()
{
	return stream.eof();
}

int UslugiStream::PobierzId()
{
	int numer;
	stream >> numer;
	return numer;
}
