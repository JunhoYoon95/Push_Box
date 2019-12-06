
#include <iostream>
#include <ncurses.h>
#include <clocale>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <stack>

#include "Algo.h"

using namespace std;

#define ROWS 8
#define COLS 8

#define BLOCKS 1
#define BOX 2
#define HOLE 3
#define PLAYER 4


int main()
{



	//Algo 객체 생성시, Algo.cpp의 생성자에서 Algo.cpp에 정으되어 있는 AStar_execute함수를 실행해 객체의 AStar_solution 벡터에 Solution을 넣어준다.
	Algo algo;
	
	//!!!TEST 함수!!!!
	//Algo 클래스의 chck() 함수는 생성자에서 호출한 함수를 통해 저장된 객체의 solution vector변수를 확인한다.
	
	
	//algo.check();




	return 0;
}
