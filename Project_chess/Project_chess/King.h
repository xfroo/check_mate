#pragma once

#include "piece.h"
#include <iostream>

class King : public piece
{
public:
	King();
	~King();

	int check_Valid() const override;

};

