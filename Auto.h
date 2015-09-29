/*
 * Auto.h
 * Author: Vladimir
 *
 */

#ifndef AUTO_H_
#define AUTO_H_

#include "Scoped.h"
#include "Array.h"

class Auto_ptr : public Scoped_ptr
{
public:
	Auto_ptr(Array *p) : Scoped_ptr(p) {};
	Auto_ptr(Auto_ptr &p);
	Auto_ptr & operator =(Auto_ptr &p);
};

#endif /* AUTO_H_ */
