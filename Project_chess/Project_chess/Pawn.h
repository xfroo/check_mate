#pragma once

#include "piece.h"
#include <iostream>

class Pawn : public piece
{
public:
	Pawn();
	~Pawn();

	virtual int check_Valid(std::string _move) override;
	void pawnMove(int dest, int source);

};

