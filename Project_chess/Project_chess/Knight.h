#pragma once

#include "piece.h"
#include <iostream>

class Knight : public piece
{
public:
	Knight();
	~Knight();

	int check_Valid() const override;

};
