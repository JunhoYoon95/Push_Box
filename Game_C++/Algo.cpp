#include "Algo.h"
#include <iostream>
using namespace std;

Algo::Algo(int *result_map)
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            int m =*(result_map+(i*8+j));
            map[i][j] = m;
        }
    }
}

char Algo::Direction(int *result_map)
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            int m =*(result_map+(i*8+j));
            map[i][j] = m;
        }
    }
    index ++;

    return stage[index];
}