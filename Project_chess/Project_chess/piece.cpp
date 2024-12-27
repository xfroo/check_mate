#include "piece.h"
#include "Board.h"
#include <iostream>

piece::piece(std::string move)
{
	move = nullptr;
}

piece::~piece()
{
}

int piece::check_Valid(std::string rook)
{
	return 0;
}

int Rook::check_Valid(std::string rook)
{
	return 0;
}
