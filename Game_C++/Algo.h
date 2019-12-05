#include <iostream>
#include <vector>
#include "Game.h"
using namespace std;
class Algo
{
public:
    Algo(Game pushBoxGame);
    int index = -1;
    vector<char> direction = {'w', 's', 'a', 'w', 'd', 's', 'd', 'w'};

    char Direction();
    /* 
    'w' : 위로 이동
    's' : 아래로 이동
    'a' : 왼쪽으로 이동
    'd' : 오른쪽으로 이동
    */

};