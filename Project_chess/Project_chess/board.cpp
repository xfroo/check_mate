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

board::board(Pipe pipe_Server, std::string move, std::string source, std::string dest, std::string places, int turn, char piece)
{
    Pipe* _pipe_server = new Pipe;
    _move = "";
    _source = "";
    _dest = "";
    _places = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr0";
    _turn = 0;
    _piece = piece;
    connect();
}

board::~board()
{
    close();
}

void board::send_String()
{
    sendMessageToGraphics(const_cast<char*>(_places.data()));
}

int board::change_Turns() //this func changes the current turn
{
    if (_turn == 0)
    {
        _turn = 1;
    }
    else if (_turn == 1)
    {
        _turn = 0;
    }
    return _turn;
}

std::string board::getMove() //this func is sending returning the current wanted move
{
    _move = getMessageFromGraphics();
    return _move;
}

char board::getSource() //this function divieds the string of the move and returning the whatever in the position
{
    _move = getMove();
    _source = _move.substr(0, 2);
    
    return check_Piece(_source);
}

char board::getDest() //this func takes the second half of the move
{
    _move = getMove();
    _dest = _move.substr(2, 2);

    return check_Piece(_dest);
}

void board::findPiece() //this func checks which piece is that
{
    _piece = toupper(_piece);
    switch (_piece)
    {
    case 'Q':

        break;

    case 'K':
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

char board::check_Piece(std::string pose) //this function gets the position and returns the piece in the place
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
    _piece = _places[both];

    return _piece;
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

    if (_turn == 1)
    {
        if (isupper(sourceP))
        {
            return 2;
        }
    }

    if (_turn == 0)
    {
        if (islower(sourceP))
        {
            return 2;
        }
    }
    
    if (_turn == 1)
    {
        if (islower(destP))
        {
            return 3;
        }
    }
    if (_turn == 0)
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

