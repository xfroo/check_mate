#pragma once

#include "piece.h"
#include <iostream>

class Bishop : public piece
{
public:
	Bishop();
	~Bishop();

	int check_Valid();

};

