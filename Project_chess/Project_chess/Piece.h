#pragma once
#include "Board.h"
#include <iostream>
#include "Rook.h"

class piece : board
{
public:
	piece();
	piece(std::string move);
	~piece();

	virtual int check_Valid(std::string move) = 0;

private:
	std::string _move;
	
};