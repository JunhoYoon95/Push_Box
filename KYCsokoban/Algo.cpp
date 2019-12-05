#include "Algo.h"
#include <iostream>
#include<vector>
#include "sokoban.h"
#include<fstream>
#include<cstring>

using namespace std;

extern stack<char> res_astar;
extern stack<char> res_gfs;


Algo::Algo(int *result_map, const int pos_row, const int pos_col, const int row, const int col)
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            int m =*(result_map+(i*8+j));
            map[i][j] = m;
        }
    }

    char_pos[0] = pos_row;
    char_pos[1] = pos_col;
    map_row = row;
    map_col = col;
}
void getInput(vector<string> &ground)
{
	fstream fs;
	fs.open("in.txt", fstream::in);
	int n;
	fs>>n;
	string t;
	getline(fs, t);


	for (int i = 0; i < n; ++i) {
		getline(fs, t);
	


	   int len = t.size();
    //    cout <<"len: "<< len << endl;
        for (int i=0;i<len;i++){


                if(t[i]=='0'){
      //  cout<<"ok";             
        t[i]=' ';
        }
                else if(t[i]=='4'){
                t[i]='1';
        //cout<<"Fase";           


}


}





		ground.push_back(t);


	

	}
//	cout<<"input success"<<endl;

	fs.close();

}


/**
 * mark all places that are reachable
 */
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
			Position person(goal[i].x  + direction[j][0], goal[i].y + direction[j][1]);
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
void showGround(vector<string> &ground)
{
	for (int i = 0; i < ground.size(); ++i) {
		cout<<ground[i]<<endl;
	}
}

int main(){
  
  	//map정보를 저장할 ground vector. 
    vector<string> ground;


	//getInput에서 input file로 입력받음.
	///맵의 크기를 int로 먼저 받고 맵 정보 저장. 맵 정보를 string으로 저장하기 때문에 우리 팀에 맞게 숫자로 변환해야 함 . 
	//예를 들어, box가 우리 입력에서는 & 인데, 팀 입력에서는 4 이런식으로 변경해야 함. 
    getInput(ground);
    
 //   cout<<"1"<<endl;
    
	detectDeadSquare(ground);
 //   cout<<"2"<<endl;
//	cout<<"ground size: "<<ground.size()<<endl;
	
	//입력받은 map정보 출력 
//	showGround(ground);
//	cout<<"3"<<endl;      


	//입력 결과 저장할 output.txt. 파일 출력이 아닌 화면 출력 
//	freopen("output.txt", "w", stdout);


//	for(int i=0;i<ground.size();i++){
//
//		cout<<ground[i]<<endl;
//}

	//AStar
	cout<<"AStar"<<endl;
	AStar(ground);

        cout<<res_astar.top();
        res_astar.pop();

        while (!res_astar.empty()) {

                cout<<", "<<res_astar.top();
                res_astar.pop();
        }
        cout<<endl;



	//GFS
	cout<<"GFS"<<endl;
    GFS(ground);

        cout<<res_gfs.top();
        res_gfs.pop();

        while (!res_gfs.empty()) {

                cout<<", "<<res_gfs.top();
                res_gfs.pop();
        }
        cout<<endl;





}

