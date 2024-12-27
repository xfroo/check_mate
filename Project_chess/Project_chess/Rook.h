#pragma once

#include "piece.h"
#include <iostream>
#include "Board.h"

class Rook : public piece
{
public:
	Rook();
	~Rook();

	int check_Valid(std::string rook);
};