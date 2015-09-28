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

void printArray(const Array &a, const char *titel)
{
	std::cout << std::endl;
	std::cout << titel << ": " << std::endl;
	for (size_t i = 0; i < a.getsize(); i++)
	{
		std::cout << a.get(i) << " ";
	}
	std::cout << std::endl;
}

bool scanArray(Array &a, const char *titel)
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

bool scanArrayRand(Array &a, const char *titel)
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


