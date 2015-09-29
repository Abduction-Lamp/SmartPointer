#Makefile

main: main.o Array.o IOArray.o Scoped.o
	g++ main.o Array.o IOArray.o Scoped.o -o main

main.o: main.cpp Array.h IOArray.h Scoped.h
	g++ -c main.cpp
	
Array.o: Array.cpp Array.h
	g++ -c Array.cpp
	
IOArray.o: IOArray.cpp IOArray.h Array.h
	g++ -c IOArray.cpp
	
Scoped.o: Scoped.cpp Scoped.h
	g++ -c Scoped.cpp