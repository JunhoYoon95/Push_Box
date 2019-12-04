#include "Game.h"
#include <vector>
#include <iostream>
using namespace std;

Game::Game()
{
	row = 0;
	col = 0;
	numOfBox = 0;
	step = 0;
	push = 0;
	resetPoint.set(0,0);
}

Game::Game(int r, int c, int b, int start_r, int start_c)
{
	row = r;
	col = c;
	numOfBox = b;
	step = 0;
	push = 0;
	point.set(start_r, start_c);
	resetPoint.set(start_r, start_c);
}


void Game::initMap(int* arr, int r, int c)
{
	for (int i=0; i<r; i++){
		for (int j =0; j<c; j++){
			int m = *(arr+(i*c+j));
			map[i][j] = m;
		}
	}
}

void Game::moveCharacter(Point d)
{
	point += d;
	step++;
}

bool Game::isWall(Point d)
{
	if(map[point.r+d.r][point.c+d.c] == 1 
	|| map[point.r+d.r][point.c+d.c] == 4)
	{ 
		return true;
	}
	else
	{
		return false;
	}
}


bool Game::isBox(Point d)
{
	for (int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			int row = point.r+d.r;
			int col = point.c+d.c;
			if ( map[row][col] == 2) return true;
		}
	}
	return false;
}


bool Game::canMoveBox(Point d)
{
	if ((*this).isWall(d*2)) return false;
	if ((*this).isBox(d*2)) return false;
	return true;
}


int Game::remainingBox()
{
	return numOfBox;
}


void Game::moveBox(Point d)
{
	int i=0;
	int row = point.r + d.r;
	int box_row = point.r + d.r + d.r;
	int col = point.c + d.c;
	int box_col = point.c + d.c + d.c;
	map[row][col] = 0;
	if(map[box_row][box_col] == 3){
		numOfBox --;
	}
	map[box_row][box_col] = 2;
	push++;
}

bool Game::isFinished()
{
	return Game::remainingBox() == 0;
}
