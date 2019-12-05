#include "Algo.h"
#include <iostream>
using namespace std;

Algo::Algo(int *result_map, const int pos_row, const int pos_col, const int ROWS_AUTO, const int COLS_AUTO)
{
    for(int i=0; i<ROWS_AUTO; i++)
    {
        for(int j=0; j<COLS_AUTO; j++)
        {
            int m =*(result_map+(i*8+j));
            map[i][j] = m;
        }
    }

    char_pos[0] = pos_row;
    char_pos[1] = pos_col;
}

char Algo::Direction()
{
    index ++;
    return direction[index];
}