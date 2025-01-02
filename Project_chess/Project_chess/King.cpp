#include "King.h"

int King::check_Valid(std::string _move)
{
	std::string king = board1.getSource(_move);
	std::string dest = board1.getDest(_move);

	int sourceI = board1.calcPose(king);
	int destI = board1.calcPose(dest);

	if(destI != sourceI + 1 || destI != sourceI - 1)
	{
		if (destI != sourceI - 7 || destI != sourceI + 7)
		{
			if (destI != sourceI - 9 || destI != sourceI + 9)
			{
				if (destI != sourceI - 8 || destI != sourceI + 8)
				{
					return 6;
				}
			}
		}
		
	}
	return 0;
	

	return 0;
}

void King::kingMove(int dest, int source)
{
	std::swap(board1._places[dest], board1._places[source]);
}
