/*
 * Scoped.h
 * Author: Vladimir
 *
 */

#ifndef SCOPED_H_
#define SCOPED_H_


template <typename T>
class Scoped_ptr
{
protected:
	T *pObject;


public:
	Scoped_ptr(T *pObj);
	~Scoped_ptr();

	T *ptr();
	bool isNull();

	T * operator ->();
	T & operator *();

private:
	Scoped_ptr(const Scoped_ptr<T> &p);
	const Scoped_ptr<T> & operator =(const Scoped_ptr<T> &p);

};

#include "Scoped_impl.h"

#endif /* SCOPED_H_ */
