/*
 * Scoped.cpp
 * Author: Vladimir
 *
 */

#include "Scoped.h"

//#include <iostream>

Scoped_ptr::Scoped_ptr(Array *pObj)
{
	pObject = pObj;
}

Scoped_ptr::~Scoped_ptr()
{
//    std::cout << "Delete Scoped/Auto" << std::endl;
	if (pObject)
	{
		delete pObject;
	}
}

Array * Scoped_ptr::ptr()
{
	return pObject;
}

bool Scoped_ptr::isNull()
{
	return (pObject == 0);
}

Array * Scoped_ptr::operator ->()
{
	return pObject;
}

Array & Scoped_ptr::operator *()
{
	return *pObject;
}
