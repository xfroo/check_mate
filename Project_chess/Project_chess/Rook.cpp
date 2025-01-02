#include "Rook.h"
#include <iostream>
#include "board.h"


Rook::Rook(std::string _move) : piece(_move)
{

}

Rook::~Rook()
{

}

int Rook::check_Valid(std::string move)
{
	std::string rook = board1.getSource(move);
	std::string dest = board1.getDest(move);

	char source = rook[0];
	char dest1 = dest[0];

	if (source == dest1)
	{
		if (checkValidX(move) == false)
		{
			return 6;
		}
	}
	else
	{
		if (checkValidY(move) == false)
		{
			return 6;
		}
	}

}

bool Rook::checkValidX(std::string move)
{
	std::string source = board1.getSource(move);
	std::string dest = board1.getDest(move);

	int sourceI = board1.calcPose(move);
	int destI = board1.calcPose(dest);

	if ((sourceI / 8) == (destI / 8))
	{
		if (sourceI < destI)
		{
			for (int i = (sourceI + 1); i <= destI; i++)
			{
				if (i == destI)
				{
					rookMove(destI, sourceI);
					return 0;
				}
			}
		}
		else
		{
			for (int i = (sourceI - 1); i >= destI; i--)
			{
				if (i == destI)
				{
					rookMove(destI, sourceI);
					return 0;
				}
			}
		}
	}
	
	return false;
}

bool Rook::checkValidY(std::string move)
{
	std::string source = board1.getSource(move);
	std::string dest = board1.getDest(move);

	int sourceI = board1.calcPose(move);
	int destI = board1.calcPose(dest);

	if ((sourceI % 8) == (destI % 8))
	{
		if (sourceI < destI)
		{
			for (int i = (sourceI + 8); i <= destI; i = i + 8)
			{
				if (i == destI)
				{
					rookMove(destI, sourceI);
					return 0;
				}
			}
		}
		else
		{
			for (int i = (sourceI - 8); i >= destI; i = i - 8)
			{
				if (i == destI)
				{
					rookMove(destI,sourceI);
					return 0;
				}
			}
		}
	}

	return false;
}

void Rook::rookMove(int dest,int source)
{
	std::swap(board1._places[dest], board1._places[source]);
}
