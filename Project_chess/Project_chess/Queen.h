#pragma once

#include "piece.h"
#include <iostream>

class Queen : public piece
{
public:
	Queen();
	~Queen();

	int check_Valid() const override;

};
