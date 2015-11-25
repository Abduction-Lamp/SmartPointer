/*
 * Shared.cpp
 * Author: Vladimir
 *
 */

#ifndef SHARED_IMPL_H_
#define SHARED_IMPL_H_

#include "Shared.h"


template <typename T>
Shared_ptr<T>::Shared_ptr(T *obj)
{
	pObj = new Storage();
	pObj->object = obj;
	pObj->count = 1;
}


template <typename T>
Shared_ptr<T>::~Shared_ptr()
{
	pObj->count--;
//    	std::cout << "Delete Shared(Array[" << pObj->object->getsize() << "]) | count = " << pObj->count << std::endl;      	// test
	if (pObj->count < 1)
	{
		delete pObj;
	}
}


template <typename T>
Shared_ptr<T>::Storage::~Storage()
{
	if (object)
	{
//        	std::cout << "Delete Shared::Storage(Array[" << object->getsize() << "])" << std::endl;           		// test
		delete object;
	}
}


template <typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr<T> &sPtr)
{
	pObj = sPtr.pObj;
	pObj->count++;
}


template <typename T>
Shared_ptr<T> & Shared_ptr<T>::operator =(Shared_ptr<T> &sPtr)
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


template <typename T>
T * Shared_ptr<T>::ptr()
{
	return pObj->object;
}


template <typename T>
T * Shared_ptr<T>::operator ->()
{
	return pObj->object;
}


template <typename T>
T & Shared_ptr<T>::operator *()
{
	return *(pObj->object);
}


template <typename T>
bool Shared_ptr<T>::isNull()
{
	return (pObj->object == 0);
}

#endif //SHARED_IMPL_H_

