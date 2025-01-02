#pragma once
#include "Board.h"
#include <iostream>
#include "Rook.h"

class piece
{
public:
	piece(std::string _move);
	virtual ~piece();

	virtual int check_Valid(std::string _move) = 0;
	board board1;
private:
	std::string _move;
	
	
};