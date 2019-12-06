#include "Algo.h"
#include <iostream>
#include<vector>
#include "sokoban.h"
#include<fstream>
#include<cstring>

using namespace std;

extern stack<char> res_astar;
extern stack<char> res_gfs;
using namespace std;
extern void AStar(const vector<string> &ground);
extern void GFS(const vector<string> &ground);




void getInput(vector<string> &ground)
{
	fstream fs;
	fs.open("input.txt", fstream::in);
	int n;
	fs >> n;
	string t;
	getline(fs, t);


	for (int i = 0; i < n; ++i) {
		getline(fs, t);



		int len = t.size();
		//    cout <<"len: "<< len << endl;
		for (int i = 0; i < len; i++) {


			if (t[i] == '0') {
				//  cout<<"ok";             
				t[i] = ' ';
			}
			else if (t[i] == '4') {
				t[i] = '1';
				//cout<<"Fase";           


			}


		}





		ground.push_back(t);




	}
	//	cout<<"input success"<<endl;

	fs.close();

}
void pullAndMark(vector<string> &mark, Position b, Position p)
{
	if (outOfBoundary(mark, p) || outOfBoundary(mark, b)) {
		return;
	}
	if (mark[b.x][b.y] == 'V')
		return;
	if (isWall(mark[b.x][b.y]) || isWall(mark[p.x][p.y]))
		return;
	mark[b.x][b.y] = 'V';
	for (int i = 0; i < 4; ++i) {
		Position newbox(b.x + direction[i][0], b.y + direction[i][1]);
		Position newperson(newbox.x + direction[i][0], newbox.y + direction[i][1]);
		pullAndMark(mark, newbox, newperson);
	}
}




 /**
  * detecting simple deadlocks
  */
void detectDeadSquare(vector<string> &ground)
{
	vector<Position> goal;
	getGoalPosition(ground, goal);
	vector<string> mark = ground;
	for (int i = 0; i < goal.size(); ++i) {
		for (int j = 0; j < 4; ++j) {
			Position person(goal[i].x + direction[j][0], goal[i].y + direction[j][1]);
			pullAndMark(mark, goal[i], person);
		}
	}
	for (int i = 0; i < ground.size(); ++i) {
		for (int j = 0; j < ground[i].size(); ++j) {
			if (!isWall(ground[i][j]) && !isPerson(ground[i][j]) && !isBox(ground[i][j]) && mark[i][j] != 'V') {
				ground[i][j] = 'X';
			}
		}
	}
}



void AStar_execute()
{

	vector<string> ground;

	getInput(ground);

	detectDeadSquare(ground);
	cout << "AStar" << endl;
	AStar(ground);

	/*
		cout << res_astar.top();
		res_astar.pop();

		while (!res_astar.empty()) {

			cout << ", " << res_astar.top();
			res_astar.pop();
		}
		cout << endl;
	*/

}

void GFS_execute() {
	vector<string> ground;

	getInput(ground);

	detectDeadSquare(ground);
	cout << "GFS" << endl;
	GFS(ground);

	cout << res_gfs.top();
	res_gfs.pop();

	while (!res_gfs.empty()) {

		cout << ", " << res_gfs.top();
		res_gfs.pop();
	}
	cout << endl;

}


//Algo��ü�� �����ڿ��� ��ü ������ ���ÿ� AStar_solution ���� ������ ASTAR �Լ� ���� ��� ASTAR solution�� �����ϳ�.
Algo::Algo()
{
	//ASTAR����.ASTAR���� ��� res_astar ���� solution�� �����Ѵ�. �׸��� �� ����� astar Ŭ���� ���� AStar_solution ���Ϳ� �ش� ����Ű�� �ִ´�.
	AStar_execute();


	while (!res_astar.empty())
	{
		char tmp = res_astar.top();

		this->AStar_solution.push_back(tmp);
		res_astar.pop();
	}

}

//���Ƿ� ���� �Լ���, ������ ȣ�� ��� SOLUTION VECTORȮ���Ѵ�.
void Algo::check()

{

	int len = this->AStar_solution.size();
	for (int i = 0; i < len; i++) {
		cout << this->AStar_solution[i] << endl;
	}

}
