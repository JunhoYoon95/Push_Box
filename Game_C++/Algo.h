#include <iostream>
#include <vector>
using namespace std;
class Algo
{
public:
    Algo(int *map, const int pos_row, const int pos_col, const int ROWS_AUTO, const int COLS_AUTO);
    int map[8][8];
    // char stage[17] = {'s', 's', 'a', 'w', 'd', 's', 'd', 'w', 't', 'w', 's', 'a', 'w', 'd', 's', 'd', 'w'};
    int index = -1;
    int char_pos[2]; // {row, col}
    int ROWS_AUTO;
    int COLS_AUTO;
    vector<char> direction = {'s', 's', 'a', 'w', 'd', 's', 'd', 'w', 't', 'w', 's', 'a', 'w', 'd', 's', 'd', 'w'};

    char Direction();
    /* 
    'w' : 위로 이동
    's' : 아래로 이동
    'a' : 왼쪽으로 이동
    'd' : 오른쪽으로 이동
    */

};