#pragma once

#include "piece.h"
#include <iostream>

class Queen : public piece
{
public:
	Queen(std::string _move);
	~Queen();

	virtual int check_Valid(std::string _move) override;
	bool checkValidY(std::string move);
	bool checkValidDw(std::string move);
	bool checkValidUp(std::string move);
	void queenMove(int dest, int source);
	bool checkValidX(std::string move);
private:
	std::string _move;
};
