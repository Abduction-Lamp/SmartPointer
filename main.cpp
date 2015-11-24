/*
 * main.cpp
 * Author: Vladimir
 *
 */

#include <iostream>

#include "Array.h"
#include "IOArray.h"
#include "Scoped.h"
#include "Auto.h"
#include "Shared.h"


int main(void)
{
	char ch;

	// Test Array class
	{
		//< A
		Array a(10);
		scanArrayRand(a, "A10");
		printArray(a, "Array A10");

		//< B
		Array b(3);
		std::cout << std::endl;
		std::cout << "Init B3" << std::endl;
		std::cout << b[0] << "; " << b[1] << "; " << b[2] << std::endl;

		b = a;
		b.sort();
		printArray(b, "Array B10");

		//< C
		Array c(11);
		scanArrayRand(c, "C11");
		printArray(c, "Array C11");
		//<<
	}


	// Test Scoped ptr
	{
//		Scoped_ptr pArray_A = new Array(8);				//< Will not work with a private operator=()
		Scoped_ptr pArray_A(new Array(10));
		scanArrayRand(*(pArray_A.ptr()), "pA10");		//< Test .ptr()
		pArray_A->sort();								//< Test operator ->()
		printArray(*pArray_A, "Array pA10");			//< Test operator *()
	}													//< Test ~Scoped_ptr()


	// Test Auto ptr
	{
		Auto_ptr apArray_A(new Array (20));
		scanArrayRand(*(apArray_A.ptr()), "apA20");		//< Test .ptr()
		apArray_A->sort();								//< Test operator ->()
		printArray(*apArray_A, "Array apA20");			//< Test operator *()

		Auto_ptr apArray_B(new Array(25));
		printArray(*apArray_B, "Array apB25");

		apArray_B = apArray_A;							//< Test operator =()
		printArray(*apArray_B, "Array apB20");
	}													//< Test ~Auto_ptr()


	// Test Shared ptr
	{
		Shared_ptr spArray_A(new Array(30));
		scanArrayRand(*(spArray_A.ptr()), "spA30");		        //< Test .ptr()
		spArray_A->sort();								        //< Test operator ->()
		printArray(*spArray_A, "Array spA30");			        //< Test operator *()
		//<
		{
			Shared_ptr spArray_B(spArray_A);
			printArray(*spArray_B, "Array spB30");
			//<<
			{
				Shared_ptr spArray_C(new Array(35));
				scanArrayRand(*(spArray_C.ptr()), "spC35");
				printArray(*spArray_C, "Array spC35");

				spArray_C = spArray_B;					        //< Test operator =()
				printArray(*spArray_C, "Array spC30");
			}
			//<<
			printArray(*spArray_B, "Array spB30");
            		Shared_ptr spArray_D(spArray_A);                    //< Test copy constructor
            		printArray(*spArray_D, "Array spC35");
        	}
		//<
	}

	std::cin >> ch;
    return 0;
}
