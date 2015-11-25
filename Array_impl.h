/*
 * Array_impl.h
 * Author: Vladimir
 *
 */

#ifndef ARRAY_IMPL_H_
#define ARRAY_IMPL_H_

#include <stdlib.h>


template <typename T>
T cmp(const void *a, const void *b)
{
/*	if (*(T *)a < *(T *)b)
		return -1;

	if (*(T *)a > b *(T *)b)
		return 1;

	return 0;
*/	
	return (*(T *)a - *(T *)b);
}



template <typename T>
Array<T>::Array(size_t size)
{
	(size < 0) ? this->size = 0 : this->size = size;
	this->data = new T [this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		data[i] = 0;
	}
}


template <typename T>
Array<T>::Array(const Array<T> &a)
{
	size = a.size;
	data = new T [size];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
}


template <typename T>
const Array<T> & Array<T>::operator =(const Array<T> &a)
{
	if (this != &a)
	{
		size = a.size;
		delete [] data;
		data = new T [size];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
	}

	return *this;
}


template <typename T>
T Array<T>::operator [](int i)
{
	return get(i);
}


template <typename T>
Array<T>::~Array()
{                                                   
	if (data)
	{
		delete[] data;
	}
}


template <typename T>
size_t Array<T>::getsize() const
{
	return size;

}


template <typename T>
bool Array<T>::set(int i, T val)
{
	bool flag;
	if (i > 0 || (size_t)i < size)
	{
		flag = true;
		data[i] = val;
	}
	else
	{
		flag = false;
	}
	return flag;
}


template <typename T>
T Array<T>::get(int i) const
{
	if (i < 0 || (size_t)i >= size)
	{
//		throw
		exit(1);		//< Badly, need to redo it
	}

	return data[i];
}


template <typename T>
void Array<T>::sort()
{
	qsort(data, size, sizeof(T), cmp<T>);
}

#endif //ARRAY_IMPL_H_

