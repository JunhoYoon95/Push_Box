#include "Point.h"
#include <vector>
using namespace std;
enum CELLS { EMPTY, WALL, BOX, GOAL, OUT };

class Game {
	public:
	Game();
	Game(int r, int c, int b, int start_r, int start_c);

	int row;
	int col;
	int numOfBox;
	Point point; //character position

	int step; //캐릭터 이동 횟수
	int push; //상자 이동 횟수

	int map[10][10]; //2차원 배열: 벽, 목적지, 외부
	vector<Point> box; //포인트 배열: 박스 위치

	void initMap(int* arr, int r, int c);
	void initMap(int* arr, int r); //임시

};
