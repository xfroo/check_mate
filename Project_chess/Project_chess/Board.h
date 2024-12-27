#pragma once

#include <iostream>
#include "Pipe.h"
#include <string>



class board : public Pipe
{
public:
	board();
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
	std::string _source;
	std::string _move;
	std::string _dest;
	char _piece;
	std::string _places;
	int _turn;
	Pipe _pipe_Server;
	
	
	
};

