/*
 * Author: Vladimir
 *
 */

#include <iostream>

#include "Array.h"
#include "IOArray.h"


int main()
{
	//<	A
	Array a(12);
	scanArray(a, "A");
	printArray(a, "Array A");

	//< B
	Array b(3);
	std::cout << std::endl;
	std::cout << "Init B" << std::endl;
	std::cout << b[0] << "; " << b[1] << "; " << b[2] << std::endl;

	b = a;
	b.sort();
	printArray(b, "Array B");

	//< C
	Array c(25);
	scanArrayRand(c, "C");
	printArray(c, "Array C");

    return 0;
}
