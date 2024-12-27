#pragma once

#include <iostream>
#include "Pipe.h"




class board : public Pipe
{
public:
	board(Pipe pipe_Server, std::string move, std::string source, std::string dest, std::string places,int turn, char piece);
	~board();

	
	void send_String();
	int change_Turns();
	char check_Piece(std::string pose);
	int check_Valid_Move();
	int check_For_Check();
	std::string getMove();
	char getSource();
	char getDest();
	void findPiece();
	

private:
	std::string source;
	std::string move;
	std::string dest;
	char piece;
	std::string places;
	int turn;
	Pipe pipe_Server;
	
	
	
};

