#pragma once
#include "board.h"
#include "piece.h"
#include <iostream>

class Rook : public piece
{
public:
	Rook(std::string _move);
	~Rook();

	virtual int check_Valid(std::string move) override;
	bool checkValidX(std::string move);
	bool checkValidY(std::string move);


private:
	board board1;
	std::string _move;
};