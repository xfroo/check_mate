#pragma once

#include "piece.h"
#include <iostream>

class King : public piece
{
public:
	King(std::string _move);
	~King();

	virtual int check_Valid(std::string _move) override;
	void kingMove(int dest, int source);
	

};

