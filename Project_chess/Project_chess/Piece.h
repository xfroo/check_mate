#pragma once
#include "Board.h"
#include <iostream>

class piece : public board
{
public:
	piece(int move);
	~piece();

	virtual int check_Valid();


private:
	int move;
	

};