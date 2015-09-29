/*
 * Author: Vladimir
 *
 */

#include <iostream>

#include "Array.h"
#include "IOArray.h"
#include "Scoped.h"
#include "Auto.h"
#include "Shared.h"


int main()
{
	char ch;

	// Test Array class
	//< A
	Array a(12);
	scanArrayRand(a, "A");
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
	//<<


	// Test Scoped ptr
	{
//		Scoped_ptr pArray_A = new Array(8);			//< Will not work with a private operator=()
		Scoped_ptr pArray_A(new Array(15));
		scanArrayRand(*(pArray_A.ptr()), "pA");		//< Test .ptr()
		pArray_A->sort();							//< Test operator ->()
		printArray(*pArray_A, "Array pA");			//< Test operator *()
	}												//< Test ~Scoped_ptr()


	// Test Auto ptr
	{
		Auto_ptr apArray_A(new Array (27));
		scanArrayRand(*(apArray_A.ptr()), "apA");	//< Test .ptr()
		apArray_A->sort();							//< Test operator ->()
		printArray(*apArray_A, "Array apA");		//< Test operator *()

		Auto_ptr apArray_B(new Array(17));
		printArray(*apArray_B, "Array apB");

		apArray_B = apArray_A;						//< Test operator =()
		printArray(*apArray_B, "Array apB");
	}												//< Test ~Auto_ptr()


	// Test Shared ptr
	{
		Shared_ptr spArray_A(new Array(9));
		scanArrayRand(*(spArray_A.ptr()), "spA");		//< Test .ptr()
		spArray_A->sort();								//< Test operator ->()
		printArray(*spArray_A, "Array spA");			//< Test operator *()
		//<
		{
			Shared_ptr spArray_B(spArray_A);
			printArray(*spArray_B, "Array spB");
			//<<
			{
				Shared_ptr spArray_C(new Array(19));
				scanArrayRand(*(spArray_C.ptr()), "spC");
				printArray(*spArray_C, "Array spC");

				spArray_C = spArray_B;					//< Test operator =()
				printArray(*spArray_C, "Array spC");
			}
			//<<
			printArray(*spArray_B, "Array spB");
		}
		//<
	}

	std::cin >> ch;
    return 0;
}
