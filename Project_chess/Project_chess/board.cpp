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

board::board(Pipe _pipe_Server, std::string _move, std::string _source, std::string _dest, std::string _places, int _turn, char _piece)
{
    Pipe* _pipe_server = new Pipe;
    _move = nullptr;
    _source = nullptr;
    _dest = nullptr;
    _places = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr0";
    _turn = 0;
    _piece;
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

int board::change_Turns() //this func changes the current turn white is zero
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

std::string board::getMove() //this func is sending re_turning the current wanted move
{
    _move = getMessageFromGraphics();
    return _move;
}

std::string board::getSource(std::string move) //this function divieds the string of the move and returning the whatever in the position
{
    move = getMove();
    _source = move.substr(0, 2);
    
    return _source;
}

std::string board::getDest(std::string move) //this func takes the second half of the move
{
    move = getMove();
    _dest = move.substr(2, 2);

    return _dest;
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

int calcPose(std::string pose)
{
    char letter = pose[0];
    int first = letter - '0';
    first = first - 97;

    char number = pose[1];
    int second = number - '0';
    second = second * 8;

    int both = first + second;
    return both;
}

char board::check_Piece(int both) //this function gets a poistion and returning which piece is there
{
    if (both > 63)
    {
        return '5';
    }
    _piece = _places[both];

    return _piece;
}

int board::check_Valid_Move(std::string move)
{
    
    std::string sourceS = getSource(move);
    std::string destS = getDest(move);

    char sourceP = check_Piece(calcPose(sourceS));
    char destP = check_Piece(calcPose(destS));

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

