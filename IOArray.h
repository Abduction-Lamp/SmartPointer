/*
 * IOArray.h
 * Author: Vladimir
 *
 */

#ifndef IOARRAY_H_
#define IOARRAY_H_

#include "Array.h"

template <typename T>
void printArray(const Array<T> &a, const char *titel);

template <typename T>
bool scanArray(Array<T> &a, const char *titel);

template <typename T>
bool scanArrayRand(Array<T> &a, const char *titel);


#include "IOArray_impl.h"

#endif /* IOARRAY_H_ */
