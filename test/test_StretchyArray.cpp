//
// test_StretchyArray.cpp - tests for stretchyarray
//

#include <cstdio>
#include <cassert>

#define SA_ENABLE_INITIALIZER_LIST
#include "../StretchyArray.h"

#define p_assert(x) do {       \
		printf("%60s", #x);      \
		assert(x);               \
		printf(" - PASS :)\n");  \
	} while (false)

#define p_header(s) do {       \
		printf("  %s  \n", s);   \
	} while (false)


struct X {
	int a, b, c;
	bool operator==(const X &x) const {
		return a == x.a && b == x.b && c == x.c;
	}
	bool operator!=(const X &x) const {
		return !(*this == x);
	}
};
void print(struct X x) {
	printf("a:%d b:%d c:%d\n", x.a, x.b, x.c);
}


int main() {
	p_header("\n");
	p_header("test_StretchyArray.cpp");
	p_header("--------------------------------\n");

	p_header("Initialises to requested capacity");
	StretchyArray<X, int> a(2);
	p_assert(a.get_n() == 0);
	p_assert(a.get_capacity() == 2);

	p_header("Initialization with initializer_list");
	StretchyArray<X, int> b{
		{ 1, 2, 3, },
		{ 2, 4, 6, },
		{ 3, 6, 9, },
		{ 4, 8, 12, },
		{ 5, 10, 15, },
	};
	p_assert(b.get_n() == 5);
	p_assert(b.get_capacity() == 8);


	p_header("Values pushed are added");
	X x0 = { 1, 2, 3};
	X x1 = { 4, 5, 6};
	X x2 = { 7, 8, 9};
	a.push(x0);
	a.push(x1);
	p_assert(a.get_n() == 2);
	p_assert(a.get_capacity() == 2);
	p_assert(a[0] == x0);
	p_assert(a[1] == x1);
	p_assert(a[0] != x1);

	p_header("Capacity expands");
	a.push(x2);
	p_assert(a.get_n() == 3);
	p_assert(a.get_capacity() == 4);
	p_assert(a[2] == x2);
	a.push(x2);
	a.push(x2);
	p_assert(a.get_n() == 5);
	p_assert(a.get_capacity() == 8);

	p_header("Multi-item push");
	X x_arr_A = { 10, 11, 12 };
	X x_arr_B = { 20, 21, 22 };
	X x_arr_1[] = {
		x_arr_A,
		x_arr_B,
	};
	a.push_multi(x_arr_1, 2);
	p_assert(a.get_n() == 7);
	p_assert(a[5] == x_arr_A);
	p_assert(a[6] == x_arr_B);
	a.pop();
	a.pop();

	p_header("Capacity expands properly on multi-item push");
	X x_arr_2[] = {
		x_arr_A, x_arr_A, x_arr_A, x_arr_A, x_arr_A, x_arr_A, x_arr_A, x_arr_A,
		x_arr_A, x_arr_A, x_arr_A, x_arr_A, x_arr_A, x_arr_A, x_arr_A, x_arr_A,
	};
	a.push_multi(x_arr_2, 16);
	p_assert(a.get_n() == 21);
	p_assert(a.get_capacity() == 32);
	for (int i=0; i < 16; ++i) {
		a.pop();
	}

	p_header("Removal of elements");
	X x2_test = a.pop();
	p_assert(x2_test == x2);
	p_assert(a.get_n() == 4);
	p_assert(a.get_capacity() == 8);

	p_header("Contraction around ~0.25 usage");
	a.pop();
	a.pop();
	p_assert(a.get_n() == 2);
	p_assert(a.get_capacity() == 4);
	X x1_test = a.pop();
	p_assert(x1_test == x1);

	p_header("Larger-scale expansion");
	a.pop();
	for (int i=0; i < 400; ++i) {
		a.push(x0);
	}
	p_assert(a.get_n() == 400);
	p_assert(a.get_capacity() == 512);
	for (int i=0; i < 399; ++i) {
		a.pop();
	}
	p_assert(a.get_n() == 1);
	p_assert(a.get_capacity() == 2);

	p_header("Reset");
	for (int i=0; i < 399; ++i) {
		a.push(x0);
	}
	p_assert(a.get_n() == 400);
	a.reset();
	p_assert(a.get_n() == 0);
	p_assert(a.get_capacity() == 1);

	return 0;
}
