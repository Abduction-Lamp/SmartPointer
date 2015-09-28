#Makefile

main: main.o Array.o IOArray.o
	g++ main.o Array.o IOArray.o -o main

main.o: main.cpp Array.h IOArray.h
	g++ -c main.cpp
	
Array.o: Array.cpp Array.h
	g++ -c Array.cpp
	
IOArray.o: IOArray.cpp IOArray.h Array.h
	g++ -c IOArray.cpp