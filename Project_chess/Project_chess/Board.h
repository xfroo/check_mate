#pragma once

#include <iostream>
#include "Pipe.h"

class board : public Pipe
{
public:
	board(std::string places,int turn, std::string piece);
	~board();

	
	void send_String();
	int change_Turns();
	std::string check_Piece() const;
	int check_Valid_Move() const;
	int check_For_Check() const;


private:
	std::string piece;
	std::string places;
	int turn;
	Pipe pipe_Server;
	
	
};

