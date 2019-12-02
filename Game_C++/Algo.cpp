#include "Algo.h"
#include <iostream>
using namespace std;

Algo::Algo(int *result_map, const int pos_row, const int pos_col, const int row, const int col)
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            int m =*(result_map+(i*8+j));
            map[i][j] = m;
        }
    }

    char_pos[0] = pos_row;
    char_pos[1] = pos_col;
    map_row = row;
    map_col = col;
}

char Algo::Direction(int *result_map, const int pos_row, const int pos_col)
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            int m =*(result_map+(i*8+j));
            map[i][j] = m;
        }
    }
    if(index == 16) index = -1;
    index ++;
    char_pos[0] = pos_row;
    char_pos[1] = pos_col;

    return stage[index];
}