/*
 * Array.cpp
 * Author: Vladimir
 *
 */

#include "Array.h"

#include <stdlib.h>
//#include <iostream>


int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

Array::Array(size_t size)
{
	(size < 0) ? this->size = 0 : this->size = size;
	this->data = new int [this->size];
	for (size_t i = 0; i < this->size; i++)
	{
		data[i] = 0;
	}
}


Array::Array(const Array &a)
{
	size = a.size;
	data = new int [size];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = a.data[i];
	}
}

const Array & Array::operator =(const Array &a)
{
	if (this != &a)
	{
		size = a.size;
		delete [] data;
		data = new int [size];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = a.data[i];
		}
	}

	return *this;
}

int Array::operator [](int i)
{
	return get(i);
}

Array::~Array()
{
	if (data)
	{
//        std::cout << "Delete Array[" << size << "]" << std::endl;
		delete[] data;
	}
}

size_t Array::getsize() const
{
	return size;
}

bool Array::set(int i, int val)
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

int Array::get(int i) const
{
	if (i < 0 || (size_t)i >= size)
	{
//		throw
		exit(1);		//< Badly, need to redo it
	}

	return data[i];
}

void Array::sort()
{
	qsort(data, size, sizeof(int), cmp);
}
