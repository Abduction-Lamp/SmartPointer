/*
 * Shared.h
 * Author: Vladimir
 *
 */

#ifndef SHARED_H_
#define SHARED_H_

#include "Array.h"


class Shared_ptr
{
private:
	class Storage
	{
	public:
		Array *object;
		int count;

	public:
		~Storage();
	};

private:
	Storage *pObj;

public:
	Shared_ptr(Array *obj);
	Shared_ptr(Shared_ptr &sPtr);
	~Shared_ptr();

	Shared_ptr & operator =(Shared_ptr &sPtr);

	Array * operator ->();
	Array & operator *();

	Array *ptr();
	bool isNull();
};


#endif /* SHARED_H_ */
