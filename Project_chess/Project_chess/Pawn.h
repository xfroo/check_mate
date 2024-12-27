#pragma once

#include "piece.h"
#include <iostream>

class Pawn : public piece
{
public:
	Pawn();
	~Pawn();

	int check_Valid();

};

