/*
 * Scoped.cpp
 *
 *  Created on: 29.09.2015
 *      Author: Planet
 */

#include "Scoped.h"

Scoped_ptr::Scoped_ptr(Array *pObj)
{
	pObject = pObj;
}

Scoped_ptr::~Scoped_ptr()
{
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
