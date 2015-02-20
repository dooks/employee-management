CC = g++

all: main.o
	g++ main.cpp manager.cpp employee.cpp pager.cpp date.cpp -o exe
	./exe
