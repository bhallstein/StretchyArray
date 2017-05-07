//
// StretchyArray.h
//
// - A simple vector-like container.
// - Members must be trivially copyable value types.
//

#ifndef __StretchyArray_h
#define __StretchyArray_h

#include <cstdlib>

#define SA_CONTRACTION_THRESHOLD 0.28


// Forward declarations
// --------------------------------------

template<class T, class T_INDEX>
class StretchyArray;

template<class T, class T_INDEX>
T_INDEX StretchyArray_swapRemove(StretchyArray<T, T_INDEX> &a, T_INDEX i);


// StretchyArray
// --------------------------------------

template<class T, class T_INDEX>
class StretchyArray {
public:
	StretchyArray(T_INDEX initial_size) :
		size(0),
		n(0),
		arr(NULL)
	{
		reallocateTo(initial_size);
	}
	StretchyArray() :
		size(0),
		n(0),
		arr(NULL)
	{
		reallocateTo(1);
	}
	~StretchyArray()
	{
		free(arr);
	}

	void reset() {
		n = 0;
		reallocateTo(1);
	}

	void push(const T &t) {
		if (n == size) {
			reallocateTo(size*2);
		}
		arr[n++] = t;
	}

	T pop() {
		const T t = arr[--n];
		if (n <= size * SA_CONTRACTION_THRESHOLD) {
			reallocateTo(size / 2);
		}
		return t;
	}

	T_INDEX get_capacity() const {
		return size;
	}

	T_INDEX get_n() const {
		return n;
	}

	T operator[](const T_INDEX i) const {
		return arr[i];
	}

	T* unsafe_ptr() const {
		return arr;
	}

	friend T_INDEX StretchyArray_swapRemove<T, T_INDEX>(StretchyArray<T, T_INDEX> &a, T_INDEX i);

private:
	T *arr;
	T_INDEX size;
	T_INDEX n;
	T default_val;

	StretchyArray(const StretchyArray &) { }
	StretchyArray& operator= (const StretchyArray &) { }

	void reallocateTo(T_INDEX new_size) {
		arr = (T*) realloc(arr, new_size * sizeof(T));
		size = new_size;
	}

};


#endif


// LICENSE
// Copyright (c) 2017 Ben Hallstein
// -------------------------------------------
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions:
//   The above copyright notice and this permission notice shall be included in all
//   copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
