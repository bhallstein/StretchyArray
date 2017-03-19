//
// StretchyArray_C.h
// 
// - C translation of StretchyArray.
// 

#ifndef __StretchyArray_C_h
#define __StretchyArray_C_h

#include <stdlib.h>
#include <stdint.h>


// StretchyArray_C -- data type
// ---------------------------------

struct StretchyArray_C {
	uint16_t size;
	uint16_t capacity;
	uint8_t bytes_per_element;
	char *arr;
};


// Functions 
// ---------------------------------

struct StretchyArray_C stretchyArray_make(uint16_t initial_capacity, uint8_t bytes_per_element) {
	return (struct StretchyArray_C) {
		0,
		initial_capacity,
		bytes_per_element,
		(char*) malloc(bytes_per_element * initial_capacity),
	};
}

void sretchyArray_destroy(struct StretchyArray_C *a) {
	free(a->arr);
}

void stretchyArray_expand(struct StretchyArray_C *a) {
	uint16_t capacity = (a->capacity *= 2);
	a->arr = (char*) realloc(a->arr, capacity);
}

void stretchyArray_add(struct StretchyArray_C *a, char *obj) {
	if (a->capacity == a->size) {
		stretchyArray_expand(a);
	}
	uint16_t n = a->size++;
	for (uint8_t i=0, m=a->bytes_per_element; i < m; ++i) {
		a->arr[n*m + i] = obj[i];
	}
}

char* stretchyArray_get(struct StretchyArray_C *a, uint16_t i) {
	return a->arr + i * a->bytes_per_element;
}


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
