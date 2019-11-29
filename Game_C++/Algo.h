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
    그 외의 입력은 해당 스테이지를 초기화 해준다
    */

   /* 맵 값
    0:빈부분(길)
    1:벽    
    2:박스    
    3:도착지점    
    4:없어도 되는 부분         
   */

};