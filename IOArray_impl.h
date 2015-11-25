/*
 * IOArray_impl.h
 * Author: Vladimir
 *
 */

#ifndef IOARRAY_IMPL_H_
#define IOARRAY_IMPL_H_

#include <cstdlib>
#include <ctime>

#include "IOArray.h"    				// Don't need inclusion, but I left so clear to me what the file is


template <typename T>
void printArray(const T &a, const char *titel)
{
	std::cout << titel << ": " << std::endl;
	for (size_t i = 0; i < a.getsize(); i++)
	{
		std::cout << a.get(i) << " ";
	}
	std::cout << std::endl;
}


template <typename T>
bool scanArray(T &a, const char *titel)
{
	int val;
	bool flag = true;

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
bool scanArrayRand(T &a, const char *titel)
{
	bool flag = true;

	srand(time(NULL));

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

#endif //IOARRAY_IMPL_H_

