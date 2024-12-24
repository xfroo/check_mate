#pragma once

#include "piece.h"
#include <iostream>

class Rook : public piece
{
public:
	Rook();
	~Rook();

	int check_Valid() const override;

};
