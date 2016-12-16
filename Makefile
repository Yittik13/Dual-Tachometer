all: main

main: main.cpp Engine.cpp Gauges.cpp
	g++ -std=c++11 -Wall -lncurses -o main main.cpp Engine.cpp Gauges.cpp
