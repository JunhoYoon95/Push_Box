CC = g++
CFLAGS = -std=c++14
TARGET = push_game
SOURCES = Algo.cpp \
	 GFS.cpp \
AStar.cpp \
helper.cpp \
main.cpp \

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) -lncursesw

clean:
	rm -rf *.o $(TARGET)
