#pragma once
#include "Board.h"
#include <iostream>
#include "Rook.h"

class piece : board
{
public:
	piece(std::string move);
	~piece();

	virtual int check_Valid(std::string rook);

private:
	std::string move;
	
};