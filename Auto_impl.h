/*
 * Auto_impl.h
 * Author: Vladimir
 *
 */

#ifndef AUTO_IMPL_H_
#define AUTO_IMPL_H_

#include "Auto.h" 		// Don't need inclusion, but I left so clear to me what the file is

/*
 *  Does not compile 
 *
template <typename T>
Auto_ptr<T>::Auto_ptr(Auto_ptr<T> &p) //: Scoped_ptr<T>(p)
{
	this->pObject = p.pObject;
	p.pObject = 0;                                       	// here the compiler wants   this->
}
*/


template <typename T>
Auto_ptr<T> & Auto_ptr<T>::operator =(Auto_ptr<T> &p)
{
	if (this != &p)
	{
		delete this->pObject;      			// here the compiler wants   this->
		this->pObject = p.pObject;                      // here the compiler wants   this->
		p.pObject = 0;
	}
	return *this;
}

#endif //AUTO_IMPL_H_
