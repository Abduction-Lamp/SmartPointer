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
#include "Shared.h"


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
//		Scoped_ptr< Array<float> > pArray_A = new Array<float>(8);	//< Will not work with a private operator=()
		Scoped_ptr< Array<float> > pArray_A(new Array<float>(10));
		scanArrayRand< Array<float> >(*(pArray_A.ptr()), "pA10");	//< Test .ptr()
	//	pArray_A->sort();						//< Test operator ->()
		pArray_A->set(1, 3.1415);
		printArray< Array<float> >(*pArray_A, "Array pA10");		//< Test operator *()
		
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



	// Test Shared ptr
	std::cout << std::endl;
	std::cout << "\nShared Ptr" << std::endl;		
	{
		Shared_ptr<ArrInt> spArray_A(new Array<int>(30));
		scanArrayRand<ArrInt>(*(spArray_A.ptr()), "spA30");		        //< Test .ptr()
		spArray_A->sort();							//< Test operator ->()
		printArray<ArrInt>(*spArray_A, "Array spA30");			        //< Test operator *()
		std::cout << std::endl;
		{
			Shared_ptr<ArrInt> spArray_B(spArray_A);
			printArray<ArrInt>(*spArray_B, "Array spB30");
			std::cout << std::endl;
			{
				Shared_ptr<ArrInt> spArray_C(new Array<int>(35));
				scanArrayRand<ArrInt>(*(spArray_C.ptr()), "spC35");
				printArray<ArrInt>(*spArray_C, "Array spC35");

				spArray_C = spArray_B;					//< Test operator =()
				printArray<ArrInt>(*spArray_C, "Array spC30");
			}
			std::cout << std::endl;
			printArray<ArrInt>(*spArray_B, "Array spB30");
            Shared_ptr<ArrInt> spArray_D(spArray_A);                    	//< Test copy constructor
            printArray<ArrInt>(*spArray_D, "Array spC35");
        }
	}
                                          

	std::cin >> ch;

    return 0;
}
