/*
 * main.cpp
 * Author: Vladimir
 *
 */

#include <iostream>
#include <stdlib.h>

#include "Array.h"
#include "IOArray.h"
#include "Scoped.h"
#include "Auto.h"

//#include "Shared.h"

typedef Array<int> ArrInt;


int main(void)
{
	char ch;
	system("cls");


	// Test Array class
	std::cout << "Array" << std::endl;
	{
		//< A
		ArrInt a(10);
		std::cout << std::endl;
		scanArrayRand<ArrInt>(a, "A10");
		printArray<ArrInt>(a, "Array A10");

		//< B
		ArrInt b(3);
		std::cout << std::endl;
		std::cout << "Init B3" << std::endl;
		std::cout << b[0] << "; " << b[1] << "; " << b[2] << std::endl;

		b = a;
		b.sort();
		printArray<ArrInt>(b, "Array B10");

		//< C
		ArrInt c(11);
		std::cout << std::endl;
		scanArrayRand<ArrInt>(c, "C11");
		printArray<ArrInt>(c, "Array C11");
	}									// Delete Arrays A, B, C


	// Test Scoped ptr
	std::cout << std::endl;
	std::cout << "\nScoped Ptr" << std::endl;
	{
//		Scoped_ptr<ArrInt> pArray_A = new ArrInt(8);			//< Will not work with a private operator=()
		Scoped_ptr<ArrInt> pArray_A(new Array<int>(10));
		scanArrayRand<ArrInt>(*(pArray_A.ptr()), "pA10");		//< Test .ptr()
		pArray_A->sort();						//< Test operator ->()
		printArray<ArrInt>(*pArray_A, "Array pA10");			//< Test operator *()
	}									//< Test ~Scoped_ptr()


	// Test Auto ptr
	std::cout << std::endl;
	std::cout << "\nAuto Ptr" << std::endl;	
	{
		Auto_ptr<ArrInt> apArray_A(new Array<int> (20));
		scanArrayRand<ArrInt>(*(apArray_A.ptr()), "apA20");		//< Test .ptr()
		apArray_A->sort();						//< Test operator ->()
		printArray<ArrInt>(*apArray_A, "Array apA20");			//< Test operator *()
               	
		std::cout << std::endl;
		Auto_ptr<ArrInt> apArray_B(new Array<int>(25));
		printArray<ArrInt>(*apArray_B, "Array apB25");
		apArray_B = apArray_A;						//< Test operator =()
		printArray<ArrInt>(*apArray_B, "Array apB20");

//		std::cout << std::endl;
//		Auto_ptr<ArrInt> apArray_C(apArray_B);
//		printArray<ArrInt>(*apArray_C, "Array apC20");				
	}									//< Test ~Auto_ptr()

/*
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

*/


                                           

	std::cin >> ch;

    	return 0;
}
