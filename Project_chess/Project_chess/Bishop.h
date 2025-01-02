#pragma once

#include "piece.h"
#include <iostream>

class Bishop : public piece
{
public:
	Bishop(std::string _move);
	~Bishop();

	virtual int check_Valid(std::string _move) override;
	bool checkValidDw(std::string move);
	bool checkValidUp(std::string move);
	void bishopMove(int dest, int source);
private:
	std::string _move;
	
};

