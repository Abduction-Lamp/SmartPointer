/*
 * Scoped.h
 * Author: Vladimir
 *
 */

#ifndef SCOPED_H_
#define SCOPED_H_

#include "Array.h"

class Scoped_ptr
{
protected:
	Array *pObject;


public:
	Scoped_ptr(Array *pObj);
	~Scoped_ptr();

	Array *ptr();
	bool isNull();

	Array * operator ->();
	Array & operator *();

private:
	Scoped_ptr(const Scoped_ptr &p);
	const Scoped_ptr & operator =(const Scoped_ptr &p);

};


#endif /* SCOPED_H_ */
