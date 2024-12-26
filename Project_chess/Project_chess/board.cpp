#include "board.h"
#include "Pipe.h"
#include <iostream>
#include "Piece.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"



board::board(std::string places, int turn, char piece)
{
    places = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr0";
    turn = 0;
    piece;
    Pipe* pipe_server = new Pipe;
    connect();
}

board::~board()
{
    close();
}

void board::send_String()
{
    sendMessageToGraphics(const_cast<char*>(places.data()));
}

int board::change_Turns()
{
        
    return turn;
}

std::string board::getMove() 
{
    move = getMessageFromGraphics();
    return move;
}

char board::getSource()
{
    move = getMove();
    source = move.substr(0, 2);

    return check_Piece(source);
}

char board::getDest()
{
    move = getMove();
    dest = move.substr(2, 2);

    return check_Piece(dest);
}

void board::findPiece()
{
    piece = toupper(piece);
    switch (piece)
    {
    case 'Q':

        break;

    case 'K':
        King::check_Valid();
        break;

    case 'R':

        break;

    case 'P':

        break;

    case 'N':

        break;

    case 'B':

        break;
    }
}

char board::check_Piece(std::string pose)
{
    char letter = pose[0];
    int first = letter - '0';
    first = first - 97;

    char number = pose[1];
    int second = number - '0';
    second = second * 8;
    
    int both = first + second;
    if (both > 63)
    {
        return '5';
    }
    piece = places[both];

    return piece;
}

int board::check_Valid_Move()
{
    char sourceP = getSource();
    char destP = getDest();

    if (sourceP == '5' || destP == '5')
    {
        return 5;
    }
    if (destP == '#' || sourceP == '#')
    {
        return 2;
    }
    if (turn == 1)
    {
        if (isupper(sourceP))
        {
            return 2;
        }
    }
    if (turn == 0)
    {
        if (islower(sourceP))
        {
            return 2;
        }
    }
    
    if (turn == 1)
    {
        if (islower(destP))
        {
            return 3;
        }
    }
    if (turn == 0)
    {
        if (isupper(destP))
        {
            return 3;
        }
    }
    if (check_For_Check() != 0)
    {
        return 4;
    }
    if (destP == sourceP)
    {
        return 7;
    }
}

int board::check_For_Check()
{

    return 0;
}

