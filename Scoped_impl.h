/*
 * Scoped_impl.h
 * Author: Vladimir
 *
 */

#ifndef SCOPED_IMPL_H_
#define SCOPED_IMPL_H_

#include "Scoped.h"    			// Don't need inclusion, but I left so clear to me what the file is


template <typename T>
Scoped_ptr<T>::Scoped_ptr(T *pObj)
{
	pObject = pObj;
}


template <typename T>
Scoped_ptr<T>::~Scoped_ptr()
{
	if (pObject)
	{
		delete pObject;
	}
}


template <typename T>
T * Scoped_ptr<T>::ptr()
{
	return pObject;
}


template <typename T>
bool Scoped_ptr<T>::isNull()
{
	return (pObject == 0);
}


template <typename T>
T * Scoped_ptr<T>::operator ->()
{
	return pObject;
}


template <typename T>
T & Scoped_ptr<T>::operator *()
{
	return *pObject;
}

#endif //SCOPED_IMPL_H_
