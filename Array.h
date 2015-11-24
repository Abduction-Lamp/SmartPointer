/*
 * Array.h
 * Author: Vladimir
 *
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stddef.h>


template <typename T>
class Array
{
private:
	T *data;
	size_t size;

public:
	Array(size_t size);

	Array(const Array<T> &a);
	const Array<T> & operator=(const Array<T> &a);
	T operator[](int i);

	~Array();

	size_t getsize() const;
	bool set(int i, T val);
	T get(int i) const;
	void sort();
};


int cmp(const void *a, const void *b);

#include "Array_impl.h"

#endif /* ARRAY_H_ */
