#include "board.h"
#include "Pipe.h"
#include <iostream>

board::board(std::string places, int turn, std::string piece)
{
    places = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr0";
    turn = 0;
    piece = nullptr;
    Pipe* pipe_server = new Pipe;
    connect();
}

void board::send_String()
{
    sendMessageToGraphics(const_cast<char*>(places.data()));
}

int board::change_Turns()
{
        
    return 0;
}

std::string board::getMove() 
{
    move = getMessageFromGraphics();
    return move;
}

std::string board::getSource()
{
    move = getMove();
    source = move.substr(0, 2);

    return check_Piece(source);
}

std::string board::getDest()
{
    move = getMove();
    dest = move.substr(2, 2);

    return check_Piece(dest);
}

std::string board::check_Piece(std::string pose)
{
    char letter = pose[0];
    int first = letter - '0';
    first = first - 97;

    char number = pose[1];
    int second = number - '0';
    second = second * 8;
    
    int both = first + second;
    piece = places[both];

    return piece;
}

int board::check_Valid_Move()
{

    return 0;
}

int board::check_For_Check()
{
    return 0;
}

