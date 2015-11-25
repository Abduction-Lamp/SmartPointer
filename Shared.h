/*
 * Shared.h
 * Author: Vladimir
 *
 */

#ifndef SHARED_H_
#define SHARED_H_


template <typename T>
class Shared_ptr
{
private:
	class Storage
	{
	public:
		T *object;
		int count;

	public:
		~Storage();
	};

private:
	Storage *pObj;

public:
	Shared_ptr(T *obj);
	Shared_ptr(Shared_ptr<T> &sPtr);
	~Shared_ptr();

	Shared_ptr<T> & operator =(Shared_ptr<T> &sPtr);

	T * operator ->();
	T & operator *();

	T * ptr();
	bool isNull();
};

#include "Shared_impl.h"

#endif /* SHARED_H_ */
