all:push_game
clean:
	-rm *.o push_game

push_game:Game.o main.o
	g++ -W -Wall -o push_game Game.o main.o -lncursesw

Game.o:Game.cpp
	g++ -W -Wall -c -o Game.o Game.cpp

main.o:main.cpp
	g++ -W -Wall -c -o main.o main.cpp

