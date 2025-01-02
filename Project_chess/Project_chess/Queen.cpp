#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

int Queen::check_Valid(std::string _move) 
{
	std::string queen = board1.getSource(_move);
	std::string dest = board1.getDest(_move);

	char source = queen[0];
	char dest1 = dest[0];

	if (source == dest1)
	{
		if (checkValidX(_move) == false)
		{
			return 6;
		}
	}
	else if(queen[1] == dest[1])
	{
		if (checkValidY(_move) == false)
		{
			return 6;
		}
	}
	else
	{
        int sourceI = board1.calcPose(queen);
        int destI = board1.calcPose(dest);

        int row;
        int col;

        if (sourceI/8 > destI/8)
        {
            row = sourceI/8 - destI/8;
        }
        else
        {
            row = destI/8 - sourceI/8;
        }

        if (sourceI%8 > destI%8)
        {
            col = sourceI%8 - destI%8;
        }
        else
        {
            col = destI%8 - sourceI%8;
        }

        if (row == col)
        {
            if (sourceI < destI)
            {
                if (!checkValidDw(_move))
                    return 6;
            }
            else
            {
                if (!checkValidUp(_move))
                    return 6;
            }
            return 0;
        }

        return 6;
	}
	return 0;
}

bool Queen::checkValidX(std::string move)
{
    return checkValidX(move);
}

bool Queen::checkValidY(std::string move)
{
    return checkValidY(move);
}

bool Queen::checkValidDw(std::string move)
{
    return checkValidDw(move);
}

bool Queen::checkValidUp(std::string move)
{
    return checkValidUp(move);
}

void Queen::queenMove(int dest, int source)
{
    std::swap(board1._places[dest], board1._places[source]);
}