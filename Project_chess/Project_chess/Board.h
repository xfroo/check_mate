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
	std::string check_Piece(std::string pose);
	int check_Valid_Move();
	int check_For_Check();
	std::string getMove();
	std::string getSource();
	std::string getDest();

private:
	std::string source;
	std::string move;
	std::string dest;
	std::string piece;
	std::string places;
	int turn;
	Pipe pipe_Server;
	
	
};

