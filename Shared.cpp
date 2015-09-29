/*
 * Shared.cpp
 * Author: Vladimir
 *
 */

#include "Shared.h"

//#include <iostream>


Shared_ptr::Shared_ptr(Array *obj)
{
	pObj = new Storage();
	pObj->object = obj;
	pObj->count = 1;
}

Shared_ptr::~Shared_ptr()
{
	pObj->count--;
//    std::cout << "Delete Shared(Array[" << pObj->object->getsize() << "]) | count = " << pObj->count << std::endl;
	if (pObj->count < 1)
	{
		delete pObj;
	}
}

Shared_ptr::Storage::~Storage()
{
	if (object)
	{
//        std::cout << "Delete Shared::Storage(Array[" << object->getsize() << "])" << std::endl;
		delete object;
	}
}

Shared_ptr::Shared_ptr(Shared_ptr &sPtr)
{
	pObj = sPtr.pObj;
	pObj->count++;
}

Shared_ptr & Shared_ptr::operator =(Shared_ptr &sPtr)
{
	if (this != &sPtr)
	{
		pObj->count--;
		if (pObj->count < 1)
		{
			delete pObj;
		}
		pObj = sPtr.pObj;
		pObj->count++;
	}
	return *this;
}

Array * Shared_ptr::ptr()
{
	return pObj->object;
}

Array * Shared_ptr::operator ->()
{
	return pObj->object;
}

Array & Shared_ptr::operator *()
{
	return *(pObj->object);
}

bool Shared_ptr::isNull()
{
	return (pObj->object == 0);
}
