//
// StretchyArray_swapRemove.h
//
// - Swap the final element with a removed element, keeping the array tightly
//   packed.
//
// - Returns the previous index of the previously-final element, in case
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
	T last = a.pop();
	const T_SIZE n = a.get_n();

	if (n > 0) {
		a.arr[i] = last;
	}

	return n;
}

#endif

