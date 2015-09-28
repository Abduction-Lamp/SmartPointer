/*
 * Array.h
 * Author: Vladimir
 *
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stddef.h>

class Array
{
private:
	int *data;
	size_t size;

public:
	Array(size_t size);

	Array(const Array &a);
	const Array & operator=(const Array &a);
	int operator[](int i);

	~Array();

	size_t getsize() const;
	bool set(int i, int val);
	int get(int i) const;
	void sort();
};


int cmp(const void *a, const void *b);


#endif /* ARRAY_H_ */
