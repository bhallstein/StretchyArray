//
// StretchyArray_swapRemove.h
//
// - An add-on to StretchyArray which swaps the final element with a removed element,
//   allowing edits to be made while keeping the array tightly packed.
//
// - Return value: the previous index of the previously-final element, in case
//   the caller needs to update existing references to that index.
//
// - i.e. given array = [ 1, 2, 3, 4, 5 ]
//        swapRemove(array, 1) will change the array to: [ 1, 5, 3, 4 ], and return 4.
//

#include "StretchyArray.h"
#ifndef __StretchArray_swapRemove_h
#define __StretchArray_swapRemove_h

template<class T, class T_SIZE>
T_SIZE StretchyArray_swapRemove(StretchyArray<T, T_SIZE> &a, T_SIZE i) {
	a.arr[i] = a.pop();
	return a.get_n();
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
