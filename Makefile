CC = g++

all: main.o
	g++ main.cpp manager.cpp employee.cpp date.cpp -o exe
	./exe
