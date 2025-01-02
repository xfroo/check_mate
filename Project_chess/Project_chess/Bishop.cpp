#include "Bishop.h"

int Bishop::check_Valid(std::string _move)
{
    std::string bishop = board1.getSource(_move);
    std::string dest = board1.getDest(_move);

    int sourceI = board1.calcPose(bishop);
    int destI = board1.calcPose(dest);

    int row;
    int col;

    if(sourceI / 8 > destI/8)
    {
        row = sourceI / 8 - destI / 8;
    }
    else
    {
        row = destI/8-sourceI/8;
    }
       
    if(sourceI%8>destI%8)
    {
        col = sourceI%8-destI%8;
    }
    else
    {
        col = destI%8-sourceI%8;
    }
       
    if (row == col)
    {
        if (sourceI>destI)
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

bool Bishop::checkValidDw(std::string _move)
{
    std::string source = board1.getSource(_move);
    std::string dest = board1.getDest(_move);

    int sourceI = board1.calcPose(source);
    int destI = board1.calcPose(dest);

    int step;

    if (destI%8 > sourceI%8)
    {
        step =9;
    }
    else
    {
        step =7;
    }
    

    for (int i = sourceI+step; i <=destI; i +=step)
    {
        if (i ==destI)
        {
            bishopMove(destI, sourceI);
            return true;
        }
    }

    return false;

}

bool Bishop::checkValidUp(std::string _move)
{
    std::string source = board1.getSource(_move);
    std::string dest = board1.getDest(_move);

    int sourceI = board1.calcPose(source);
    int destI = board1.calcPose(dest);

    int step;
    
    if(destI% 8> sourceI%8)
    {
        step=-7;
    }
    else
    {
        step=-9;
    }

    for (int i = sourceI+step; i >=destI; i +=step)
    {
        if (i == destI)
        {
            bishopMove(destI, sourceI);
            return true;
        }
    }
    return false;
    
}
void Bishop::bishopMove(int dest, int source)
{
    std::swap(board1._places[dest], board1._places[source]);
}
