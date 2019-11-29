#include "Game.h"
#include "info.h"
#include <iostream>
#include <ncurses.h>
#include <clocale>
#include <iostream>
#include <fstream>
using namespace std;

#define ROWS 8
#define COLS 8

#define BLOCKS 1
#define BOX 2
#define HOLE 3
#define PLAYER 4


int main()
{
	WINDOW *win1;
	setlocale(LC_ALL,"");

	initscr();

	win1 = newwin(20,35,6,0); //행:20 열:35
	curs_set(0);//커서 가렸어요
	wbkgd(win1, COLOR_PAIR(1));

	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	wattron(win1,COLOR_PAIR(1));
	cbreak();
	keypad(stdscr, TRUE);
	noecho(); //입력한 값을 보이지 않도록

	printw("Choose the stage\n");
	printw("if you want to go AUTO please push the button [left]\n");
	printw("if you want to go MANUAL please push the button [right]\n");

	refresh();

	//사용자 입력 받기
	int choose = getch();
	int mod; // 0:auto, 1:manual
	
	while (choose!=KEY_RIGHT && choose!=KEY_LEFT) choose=getch();

	if( choose==KEY_LEFT || choose==KEY_RIGHT)
	{
		clear();
		goto SET;
	}

	SET:
	win1 = newwin(20,35,6,0); //행:20 열:35
	curs_set(0);//커서 가렸어요
	wbkgd(win1, COLOR_PAIR(1));

	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_YELLOW, COLOR_WHITE);
	init_pair(3, COLOR_RED, COLOR_WHITE);
	init_pair(4, COLOR_BLUE, COLOR_WHITE);

	wattron(win1,COLOR_PAIR(1));
	cbreak();
	keypad(stdscr, TRUE);
	noecho(); //입력한 값을 보이지 않도록

	printw("F5 : next map ###################\n");
	printw("F3 : reset map ##################\n");
	printw("F10 : quit ######################\n");
	
	refresh();
	if (choose==KEY_LEFT){
		mod = 0;
		goto AUTO;
	}
	else if (choose==KEY_RIGHT){
		mod = 1;
		goto MANUAL;
	}

	MANUAL:
	if(mod == 1)
	{
		win1 = newwin(20,35,6,0); //행:20 열:35
		curs_set(0);//커서 가렸어요
		wbkgd(win1, COLOR_PAIR(1));

		start_color();
		init_pair(1, COLOR_BLACK, COLOR_WHITE);
		init_pair(2, COLOR_YELLOW, COLOR_WHITE);
		init_pair(3, COLOR_RED, COLOR_WHITE);
		init_pair(4, COLOR_BLUE, COLOR_WHITE);

		wattron(win1,COLOR_PAIR(1));
		cbreak();
		keypad(stdscr, TRUE);
		noecho(); //입력한 값을 보이지 않도록

		refresh();
		int lv;

		for (lv=0; lv<5; lv++){
			next:
			Game pushBoxGame(ROWS, COLS, INFO[lv][0] , INFO[lv][1], INFO[lv][2]);
			pushBoxGame.initMap((int*)(MAP[lv]), ROWS, COLS);
			Point d(0,0);

			while (1){

				//게임 상태 출력
				for (int r=0; r<ROWS; r++){
					for (int c=0; c<COLS; c++){
						bool b = false;

						// 캐릭터 위치면 * 출력
						if (pushBoxGame.point.r==r&&pushBoxGame.point.c==c) {
							wattron(win1, COLOR_PAIR(1)); //add
							wprintw(win1,"\u263B ");//캐릭터 스마일 원.
							continue;
						}

						// 박스가 있으면 박스 출력
						for (int i=0; i<pushBoxGame.numOfBox; i++){
							if (pushBoxGame.box[i].r==r&&pushBoxGame.box[i].c==c) {
								wattron(win1, COLOR_PAIR(3)); //add
								wprintw(win1,"\u26BF ");//박스
								b = true;
								break;
							}
						}
						// 맵 출력
						if (!b)
						{
							if(pushBoxGame.map[r][c]==0){
								wattron(win1, COLOR_PAIR(1)); //add
								wprintw(win1,"\u26DA ");//바닥
							}
							if(pushBoxGame.map[r][c]==1){
								wattron(win1, COLOR_PAIR(4)); //add
								wprintw(win1,"\u26CB ");//벽
							}
							if(pushBoxGame.map[r][c]==2){
								wattron(win1, COLOR_PAIR(3)); //add
								wprintw(win1,"\u26BF ");//박스
							}
							if(pushBoxGame.map[r][c]==3){
								wattron(win1, COLOR_PAIR(2)); //add
								wprintw(win1,"\u26F6 ");//목적지
							}
							if(pushBoxGame.map[r][c]==4){
								wattron(win1, COLOR_PAIR(1)); //add
								wprintw(win1,"\u26DD ");//바깥
							}
						}
					}
					wprintw(win1,"\n");
				}
				wrefresh(win1);

				//사용자 입력 받기
				int ch = getch();

				//예약키 외 다른 키 입력 방지
				while (ch!=KEY_LEFT&&ch!=KEY_RIGHT&&ch!=KEY_UP&&ch!=KEY_DOWN
				&&ch!=KEY_F(5)&&ch!=KEY_F(10)&&ch!=KEY_F(3)) ch=getch();

				if (ch==KEY_LEFT){
					win1 = newwin(20,35,6,0);
					wbkgd(win1, COLOR_PAIR(1));
					wattron(win1,COLOR_PAIR(1));
					d.set(0, -1);
				}
				else if (ch==KEY_RIGHT){
					win1 = newwin(20,35,6,0);
					wbkgd(win1, COLOR_PAIR(1));
					wattron(win1,COLOR_PAIR(1));
					d.set(0, 1);
				}
				else if (ch==KEY_UP){
					win1 = newwin(20,35,6,0);
					wbkgd(win1, COLOR_PAIR(1));
					wattron(win1,COLOR_PAIR(1));
					d.set(-1, 0);

				}
				else if (ch==KEY_DOWN){
					win1 = newwin(20,35,6,0);
					wbkgd(win1, COLOR_PAIR(1));
					wattron(win1,COLOR_PAIR(1));
					d.set(1, 0);

				}
				else if (ch==KEY_F(5)){//F5키를 누르면 else if
					if (lv==4)
					{
						win1 = newwin(20,35,6,0);
						wbkgd(win1, COLOR_PAIR(1));
						wattron(win1,COLOR_PAIR(1));
						wprintw(win1,"Level. %d is last level\n\n",lv+1);
						continue;
						wrefresh(win1);
					}
					else
					{
						win1 = newwin(20,35,6,0);
						wbkgd(win1, COLOR_PAIR(1));
						wattron(win1,COLOR_PAIR(1));
						lv++;
						goto next;
						wrefresh(win1);
					}
				}
				else if (ch==KEY_F(3)){
					win1 = newwin(20,35,6,0);
					wbkgd(win1, COLOR_PAIR(1));
					wattron(win1,COLOR_PAIR(1));
					wrefresh(win1);
					goto next;
				}
				else if (ch==KEY_F(10)){//F10을 누르면
					goto quit;
				}

				pushBoxGame.moveCharacter(d);
				
				wrefresh(win1);
			}

			wprintw(win1,"Map Level. %d FINISHED!\n",lv+1);
			wrefresh(win1);
		}
		quit:
		if (lv==5){
			wprintw(win1,"GAME FINISHED\n");
			wrefresh(win1);
		}
		else{
			wprintw(win1,"GAME OVER\n");
			wrefresh(win1);
		}
		wattroff(win1,COLOR_PAIR(1));

		getch();
		delwin(win1);

		endwin();
	}

	AUTO:
	if(mod == 0)
	{
		printw("###############<AUTO>############\n");
		
		ifstream map_txt;
		map_txt.open("map_info.txt");

		int ROWS_AUTO;
		map_txt >> ROWS_AUTO;
		int COLS_AUTO;
		map_txt >> COLS_AUTO;
		int char_pos_l;
		map_txt >> char_pos_l;
		int char_pos_r;
		map_txt >> char_pos_r;
		// wprintw(win1, "%d, %d, %d, %d", ROWS_AUTO, COLS_AUTO,char_pos_r,char_pos_l);

		int map_input[ROWS_AUTO][COLS_AUTO];
		int box_number = 0;
		for(int i=0; i<ROWS_AUTO; i++)
		{
			for(int j=0; j<COLS_AUTO; j++)
			{
				int input;
				map_txt >> input;
				if( input == 2) box_number++;
				// wprintw(win1, "%d ", input); //제대로 input 되는지 확인
				map_input[i][j] = input;
			}
		}
		map_txt.close();
		// wprintw(win1, "%d ", box_number); // box가 몇개 존재하는지

		Game pushBoxGame(ROWS_AUTO, COLS_AUTO, box_number, char_pos_r, char_pos_l);
		pushBoxGame.initMap((int*)(map_input), ROWS_AUTO, COLS_AUTO);
		// Point d(0,0);

		while (1){
			//게임 상태 출력
			for (int r=0; r<ROWS_AUTO; r++){
				for (int c=0; c<COLS_AUTO; c++){
					bool b = false;

					// 캐릭터 위치면 * 출력
					if (pushBoxGame.point.r==r&&pushBoxGame.point.c==c) {
						wattron(win1, COLOR_PAIR(1)); //add
						wprintw(win1,"\u263B ");//캐릭터 스마일 원.
						continue;
					}

					// 키가 있으면 키 출력
					for (int i=0; i<pushBoxGame.numOfBox; i++){
						if (pushBoxGame.box[i].r==r&&pushBoxGame.box[i].c==c) {
							wattron(win1, COLOR_PAIR(3)); //add
							wprintw(win1,"\u26BF ");//박스
							b = true;
							break;
						}
					}
					// 맵 출력
					if (!b)
					{
						if(pushBoxGame.map[r][c]==0){
							wattron(win1, COLOR_PAIR(1)); //add
							wprintw(win1,"\u26DA ");//바닥
						}
						if(pushBoxGame.map[r][c]==1){
							wattron(win1, COLOR_PAIR(4)); //add
							wprintw(win1,"\u26CB ");//벽
						}
						if(pushBoxGame.map[r][c]==2){
							wattron(win1, COLOR_PAIR(3)); //add
							wprintw(win1,"\u26BF ");//목적지
						}
						if(pushBoxGame.map[r][c]==3){
							wattron(win1, COLOR_PAIR(2)); //add
							wprintw(win1,"\u26F6 ");//키
						}
						if(pushBoxGame.map[r][c]==4){
							wattron(win1, COLOR_PAIR(1)); //add
							wprintw(win1,"\u26DD ");//바깥
						}
					}
				}
				wprintw(win1,"\n");
			}
			wrefresh(win1);
			
			while (choose!=KEY_F(10)) choose=getch();

			if (choose==KEY_F(10)){//F10을 누르면
				goto quit;
			}
			// wrefresh(win1);
		}
	}

	return 0;
}
