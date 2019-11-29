CC = g++
CFLAGS = -std=c++14
TARGET = push_game
SOURCES = main.cpp \
          Algo.cpp \
		  Game.cpp

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) -lncursesw

clean:
	rm -rf *.o $(TARGET)