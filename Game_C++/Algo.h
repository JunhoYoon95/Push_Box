#include <iostream>
using namespace std;
class Algo
{
public:
    Algo(int *map);
    int map[8][8];
    char stage[17] = {'s', 's', 'a', 'w', 'd', 's', 'd', 'w', 't', 'w', 's', 'a', 'w', 'd', 's', 'd', 'w'};
    int index = -1;

    char Direction(int *map);
    /* 
    'w' : 위로 이동
    's' : 아래로 이동
    'a' : 왼쪽으로 이동
    'b' : 오른쪽으로 이동
    */

};