#include "Rook.h"
#include <iostream>

Rook::Rook(std::string rook)
{
	rook = nullptr;
}

Rook::~Rook()
{
}

int Rook::check_Valid(std::string rook) override
{
	return 0;
}
