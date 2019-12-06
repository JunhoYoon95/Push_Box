CC = g++
CFLAGS = -std=c++14
TARGET = push_game
SOURCES = main.cpp \
          Algo.cpp \
		  Game.cpp \
		  AStar.cpp \
		  GFS.cpp \
		  helper.cpp \

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) -lncursesw

clean:
	rm -rf *.o $(TARGET)