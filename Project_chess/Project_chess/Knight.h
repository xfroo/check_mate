#pragma once

#include "piece.h"
#include <iostream>

class Knight : public piece
{
public:
	Knight();
	~Knight();


	virtual int check_Valid(std::string move) override;
	void knightMove(int dest, int source);

};
