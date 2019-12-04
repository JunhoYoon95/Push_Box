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
	Point resetPoint; // 해당 스테이지 캐릭터 처음 position

	int step; //캐릭터 이동 횟수
	int push; //상자 이동 횟수

	int map[8][8]; //2차원 배열: 벽, 목적지, 외부

	void initMap(int* arr, int r, int c);
	void moveCharacter(Point d); //캐릭터 움직이기
	bool isWall(Point d); //벽인지 판단
	bool isBox(Point d); //박스인지 판단
	bool canMoveBox(Point d); //박스 이동여부
	void moveBox(Point d); //박스 움직이기
	int remainingBox(); //목적지까지 남은 박스 개수
	bool isFinished();

};
