/*
 * Auto.cpp
 * Author: Vladimir
 *
 */

#include "Auto.h"

/*
 * You need to understand how to inherit the operator copies
 *
Auto_ptr::Auto_ptr(Auto_ptr &p) : Scoped_ptr(p)
{
	pObject = p.pObject;
	p.pObject = 0;
}
*/

Auto_ptr & Auto_ptr::operator =(Auto_ptr &p)
{
	if (this != &p)
	{
		delete pObject;
		pObject = p.pObject;
		p.pObject = 0;
	}
	return *this;
}
