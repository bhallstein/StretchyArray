//
// test_swapRemove.cpp - test for StretchyArray_swapRemove() add-on
//

#include <cstdio>
#include <cassert>

#include "../StretchyArray_swapRemove.h"

#define p_assert(x) do {     \
		printf("%60s", #x);      \
		assert(x);               \
		printf(" - PASS :)\n");  \
	} while (false)

#define p_header(s) do {   \
		printf("  %s\n", s);   \
	} while (false)

#define p_overall_header() do {   \
	printf("\n  " __FILE__ "\n");   \
	p_header("--------------------------------\n"); \
} while (false)


int main() {
	p_overall_header();

	StretchyArray<float, int> x;
	x.push(6);
	x.push(7);
	x.push(8);
	x.push(9);

	p_header("Initialised array has expected size");
	p_assert(x.get_n() == 4);
	p_assert(x.get_capacity() == 4);

	p_header("Initialised array has expected values");
	p_assert(x[0] == 6);
	p_assert(x[1] == 7);
	p_assert(x[2] == 8);
	p_assert(x[3] == 9);

	p_header("Removal returns previous index of last item");
	p_header("(Removing: 1)");
	int ind_of_swapped_item = StretchyArray_swapRemove(x, 1);
	p_assert(ind_of_swapped_item == 3);

	p_header("After removal, expected size");
	p_assert(x.get_n() == 3);
	p_assert(x.get_capacity() == 4);

	p_header("After removal, expected values");
	p_assert(x[0] == 6);
	p_assert(x[1] == 9);
	p_assert(x[2] == 8);

	p_header("Compaction");
	StretchyArray_swapRemove(x, 2);
	p_assert(x.get_n() == 2);
	p_assert(x.get_capacity() == 4);

	StretchyArray_swapRemove(x, 1);
	p_assert(x.get_n() == 1);
	p_assert(x.get_capacity() == 2);

	return 0;
}
