#include "../StretchyArray_swapRemove.h"
#include <cstdio>
#include <cassert>

#define p_assert(x) do {             \
		printf("%60s", #x);    \
		assert(x);                   \
		printf(" - PASS :)\n");      \
	} while (false)

#define p_header(s) do {                               \
		for (int i=0; s[i] != '\0'; ++i) printf("*");  \
		printf("********\n");                          \
		printf("**  %s  **\n", s);                     \
		for (int i=0; s[i] != '\0'; ++i) printf("*");  \
		printf("********\n");                          \
	} while (false)


int main() {
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
	printf("Removing: 1\n");
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
