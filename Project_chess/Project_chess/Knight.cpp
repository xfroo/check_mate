#include "Knight.h"

int Knight::check_Valid(std::string move)
{
	std::string source = board1.getSource(move);
	std::string dest = board1.getDest(move);

	int sourceI = board1.calcPose(move);
	int destI = board1.calcPose(dest);

	if (destI != sourceI + 17 || destI != sourceI + 15)
	{
		if (destI != sourceI - 17 || destI != sourceI - 15)
		{
			if (destI != sourceI + 10 || destI != sourceI + 6)
			{
				if (destI != sourceI - 10 || destI != sourceI - 6)
				{
					return 6;
				}
			}
		}
	}
	return 0;
}

void Knight::knightMove(int dest, int source)
{
	std::swap(board1._places[dest], board1._places[source]);
}
