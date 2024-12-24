#include "board.h"
#include "Pipe.h"
#include <iostream>

board::board(std::string places, int turn, std::string piece)
{
    places = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr0";
    turn = 0;
    piece = nullptr;
    Pipe pipe_server = new Pipe;
    
}

void board::send_String()
{
    sendMessageToGraphics(const_cast<char*>(places.data()));
}

int board::change_Turns()
{
        
    return 0;
}

std::string board::check_Piece()
{
    return std::string();
}

int board::check_Valid_Move()
{
    return 0;
}

int board::check_For_Check()
{
    return 0;
}

