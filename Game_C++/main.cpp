#include "Game.h"
#include "info.h"
#include <iostream>
#include <ncurses.h>
#include <clocale>
using namespace std;

#define ROWS 10
#define COLS 10

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

	printw("F5 : next map ###################\n");
	printw("F3 : reset map ##################\n");
	printw("F10 : quit ######################\n");

	refresh();
	int lv;

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
							wprintw(win1,"\u26BF ");//박스
							b = true;
							break;
						}
					}
					// 맵 출력
					if (!b)
					{
						if(pushBoxGame.map[r][c]==0) wprintw(win1,"\u26DA ");//바닥
						if(pushBoxGame.map[r][c]==1) wprintw(win1,"\u26CB ");//벽
						if(pushBoxGame.map[r][c]==2) wprintw(win1,"\u26BF ");//박스
						if(pushBoxGame.map[r][c]==3) wprintw(win1,"\u26F6 ");//목적지
						if(pushBoxGame.map[r][c]==4) wprintw(win1,"\u26DD ");//바깥
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
