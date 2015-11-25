/*
 * Auto.h
 * Author: Vladimir
 *
 */

#ifndef AUTO_H_
#define AUTO_H_

#include "Scoped.h"  		// Don't need inclusion, but I left so clear to me what the file is


template <typename T>
class Auto_ptr : public Scoped_ptr<T>
{
public:
	Auto_ptr(T *p) : Scoped_ptr<T>(p) {};
	Auto_ptr(Auto_ptr<T> &p);
	Auto_ptr<T> & operator =(Auto_ptr<T> &p);
};

#include "Auto_impl.h"

#endif /* AUTO_H_ */
