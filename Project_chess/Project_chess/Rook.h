#pragma once

#include "piece.h"
#include <iostream>"

class Rook : public piece
{
public:;
	Rook(std::string rook);
	~Rook();

	int check_Valid(std::string rook) override;

private:
	std::string rook;
};