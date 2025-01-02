#include "Pawn.h"
#include <iostream>
#include "Board.h"

int Pawn::check_Valid(std::string _move)
{
	std::string source = board1.getSource(_move);
	std::string dest = board1.getDest(_move);

	int sourceI = board1.calcPose(_move);
	int destI = board1.calcPose(dest);

	char destPawn = board1.check_Piece(destI);

	if (destI == sourceI + 9 && destPawn != '#' || destI == sourceI + 7 && destPawn != '#')
	{
		return 0;
	}
	else if (destI == sourceI + 8 && destPawn == '#')
	{
		return 0;
	}
	return 6;
}

void Pawn::pawnMove(int dest, int source)
{
	std::swap(board1._places[dest], board1._places[source]);
}
