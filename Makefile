#Makefile

main: main.o Array.o IOArray.o Scoped.o Auto.o Shared.o
	g++ main.o Array.o IOArray.o Scoped.o Auto.o Shared.o -o main

main.o: main.cpp Array.h IOArray.h Scoped.h Auto.h Shared.o
	g++ -c main.cpp
	
Array.o: Array.cpp Array.h
	g++ -c Array.cpp
	
IOArray.o: IOArray.cpp IOArray.h Array.h
	g++ -c IOArray.cpp
	
Scoped.o: Scoped.cpp Scoped.h
	g++ -c Scoped.cpp
	
Auto.o: Auto.h Auto.cpp Scoped.h
	g++ -c Auto.cpp

Shared.o: Shared.cpp Shared.h
	g++ -c Shared.cpp
