#include "Game.h"
#include <vector>
#include <iostream>
using namespace std;

Game::Game():
point(Point(0,0))
{
	row = 0;
	col = 0;
	numOfBox = 0;
	step = 0;
	push = 0;
}

Game::Game(int r, int c, int b, int start_r, int start_c):
point(Point(start_r, start_c))
{
	row = r;
	col = c;
	numOfBox = b;
	step = 0;
	push = 0;
}


void Game::initMap(int* arr, int r, int c)
{
	for (int i=0; i<r; i++){
		for (int j =0; j<c; j++){
			int m = *(arr+(i*c+j));
			if (m == BOX) {
				box.push_back(Point(i,j));
				map[i][j] = 0;
			}else map[i][j] = m;
		}
	}
}

void Game::moveCharacter(Point d)
{
	point += d;
	step++;
}


