/*
 * Auto_impl.h
 * Author: Vladimir
 *
 */

#ifndef AUTO_IMPL_H_
#define AUTO_IMPL_H_

#include "Auto.h" 		// Don't need inclusion, but I left so clear to me what the file is

/*
 * You need to understand how to inherit the operator copies
 *
template <typename T>
Auto_ptr<T>::Auto_ptr(Auto_ptr<T> &p) //: Scoped_ptr<T>(p)
{
	pObject = p.pObject;
	p.pObject = 0;
}
*/


template <typename T>
Auto_ptr<T> & Auto_ptr<T>::operator =(Auto_ptr<T> &p)
{
	if (this != &p)
	{
		delete pObject;
		pObject = p.pObject;
		p.pObject = 0;
	}
	return *this;
}

#endif //AUTO_IMPL_H_
