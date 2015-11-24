/*
 * IOArray.cpp
 * Author: Vladimir
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Array.h"
#include "IOArray.h"

template <typename T>
void printArray(const Array<T> &a, const char *titel)
{
	std::cout << std::endl;
	std::cout << titel << ": " << std::endl;
	for (size_t i = 0; i < a.getsize(); i++)
	{
		std::cout << a.get(i) << " ";
	}
	std::cout << std::endl;
}


template <typename T>
bool scanArray(Array<T> &a, const char *titel)
{
	int val;
	bool flag = true;

	std::cout << std::endl;
	std::cout << "Enter " << titel << ": " << std::endl;
	for (size_t i = 0; i < a.getsize(); i++)
	{
		std::cout << titel << "[" << i+1 << "] = ";
		std::cin >> val;
		flag = a.set(i, val);
		if (flag == false)
			exit(1);	//< Badly, need to redo it
	}
	std::cout << std::endl;

	return flag;		//< Badly, need to redo it
}


template <typename T>
bool scanArrayRand(Array<T> &a, const char *titel)
{
	bool flag = true;

	srand(time(NULL));

	std::cout << std::endl;
	std::cout << "An array " << titel << " filled with random values";
	for (size_t i = 0; i < a.getsize(); i++)
	{
		(rand() % 2) ? flag = a.set(i, rand() % 100) : flag = a.set(i, (0 - (rand() % 100)));

		if (flag == false)
			exit(1);	//< Badly, need to redo it
	}
	std::cout << std::endl;

	return flag;
}


