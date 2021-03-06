//
// StretchyArray.h
//
// - Simple vector-like container.
// - Members must be trivially copyable value types.
//
// MIT licensed: http://opensource.org/licenses/MIT
//

#ifndef __StretchyArray_h
#define __StretchyArray_h

#define SA_CONTRACTION_THRESHOLD 0.28

#ifdef SA_ENABLE_INITIALIZER_LIST
#include <initializer_list>
#endif

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
	typedef T value_type;

	StretchyArray(T_INDEX initial_capacity) :
		capacity(0),
		n(0),
		arr(0)
	{
		reallocateTo(initial_capacity);
	}
	#ifdef SA_ENABLE_INITIALIZER_LIST
	StretchyArray(std::initializer_list<T> l) :
		capacity(0),
		n(0),
		arr(0)
	{
		reallocateTo(1);
		push_multi(l.begin(), l.size());
	}
	#endif
	StretchyArray() :
		capacity(0),
		n(0),
		arr(0)
	{
		reallocateTo(1);
	}
	~StretchyArray()
	{
		delete [] arr;
	}

	void reset() {
		n = 0;
		reallocateTo(1);
	}

	T_INDEX push(const T &t) {
		T_INDEX _n = n;
		if (_n == capacity) {
			reallocateTo(capacity*2);
		}
		arr[_n] = t;
		++n;
		return _n;
	}

	void push_multi(const T *t, T_INDEX count) {
		T_INDEX new_n = n + count;
		while (capacity < new_n) {
			reallocateTo(capacity*2);
		}
		for (T_INDEX i=0; i < count; ++i) {
			arr[n+i] = t[i];
		}
		n = new_n;
	}

	T pop() {
		const T t = arr[--n];
		if (n <= capacity * SA_CONTRACTION_THRESHOLD && capacity > 1) {
			reallocateTo(capacity / 2);
		}
		return t;
	}

	T_INDEX get_capacity() const {
		return capacity;
	}

	T_INDEX get_n() const {
		return n;
	}

	T& operator[](const T_INDEX i) {
		return arr[i];
	}
	T& first() {
		return arr[0];
	}
	T& last() {
		return arr[n-1];
	}

	T* unsafe_ptr() const {
		return arr;
	}

	friend T_INDEX StretchyArray_swapRemove<T, T_INDEX>(StretchyArray<T, T_INDEX> &a, T_INDEX i);

private:
	T *arr;
	T_INDEX capacity;
	T_INDEX n;

	StretchyArray(const StretchyArray &) { }
	StretchyArray& operator= (const StretchyArray &) { }

	void reallocateTo(T_INDEX new_capacity) {
		T *arr_new = new T[new_capacity];
		if (arr) {
			for (T_INDEX i=0, _n = n; i < _n; ++i) {
				arr_new[i] = arr[i];
			}
			delete [] arr;
		}
		arr = arr_new;
		capacity = new_capacity;
	}
};


#endif

