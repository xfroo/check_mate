#pragma once

#include <iostream>
#include "Pipe.h"




class board : public Pipe
{
public:
	board();
	board(Pipe _pipe_Server, std::string _move, std::string _source, std::string _dest, std::string _places,int _turn, char _piece);
	~board();

	
	void send_String();
	int change_Turns();
	char check_Piece(int both);
	int check_Valid_Move(std::string move);
	int check_For_Check();
	int calcPose(std::string pose);
	std::string getMove();
	std::string getSource(std::string move);
	std::string getDest(std::string move);
	void findPiece();
	std::string _places;

private:
	std::string _source;
	std::string _move;
	std::string _dest;
	char _piece;
	int _turn;
	Pipe _pipe_Server;
	
	
	
};

