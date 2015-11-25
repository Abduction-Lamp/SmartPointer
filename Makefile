#Makefile

#main: main.o Scoped.o Auto.o Shared.o
#	g++ main.o Scoped.o Auto.o Shared.o -o main

#main.o: main.cpp Array.h Array_impl.h IOArray.h IOArray_impl.h Scoped.h Auto.h Shared.o
#	g++ -c main.cpp
	
#Scoped.o: Scoped.cpp Scoped.h
#	g++ -c Scoped.cpp
	
#Auto.o: Auto.h Auto.cpp Scoped.h
#	g++ -c Auto.cpp

#Shared.o: Shared.cpp Shared.h
#	g++ -c Shared.cpp




main: main.o
	g++ main.o -o main

main.o: main.cpp Array.h Array_impl.h IOArray.h IOArray_impl.h Scoped.h Scoped_impl.h #Auto.h Auto_impl.h
	g++ -c main.cpp
