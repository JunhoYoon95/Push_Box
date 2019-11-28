#include "Game.h"
#include "info.h"
#include <iostream>
#include <ncurses.h>
#include <clocale>
using namespace std;

#define ROWS 10
#define COLS 10

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
	int lv; // level
	while (choose!=KEY_RIGHT && choose!=KEY_LEFT) choose=getch();
	if (choose==KEY_LEFT){
		mod = 0;
		// initscr();
		refresh();
		// delwin(win2);
		goto AUTO;
	}
	else if (choose==KEY_RIGHT){
		mod = 1;
		clear();
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

		printw("F5 : next map ###################\n");
		printw("F3 : reset map ##################\n");
		printw("F10 : quit ######################\n");

		refresh();
		// int lv;

		for (lv=0; lv<5; lv++){
			next:
			Game pushBoxGame(ROWS, COLS, INFO[lv][0] , INFO[lv][1], INFO[lv][2]);
			pushBoxGame.initMap((int*)(MAP[lv]), ROWS, COLS);
			// Point d(0,0);

			while (1){

				//게임 상태 출력
				for (int r=0; r<ROWS; r++){
					for (int c=0; c<COLS; c++){
						bool b = false;

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
				while (ch!=KEY_F(5)&&ch!=KEY_F(10)&&ch!=KEY_F(3)) ch=getch();

				if (ch==KEY_F(5)){//F5키를 누르면 else if
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
		win1 = newwin(20,35,6,0); //행:20 열:35
		wbkgd(win1, COLOR_PAIR(1));
		wattron(win1,COLOR_PAIR(1));
		printw("AUTO");
	}

	return 0;
}
