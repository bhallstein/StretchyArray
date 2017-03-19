#include "../StretchyArray_swapRemove.h"
#include <cstdio>

int main() {
	StretchyArray<float, int> x;
	x.push(6);
	x.push(7);
	x.push(8);
	x.push(9);

	printf("%.0f,%.0f,%.0f,%.0f (%d)\n", x[0], x[1], x[2], x[3], x.get_n());
	printf("Removing: 1\n");
	int ind_of_swapped_item = StretchyArray_swapRemove(x, 1);
	printf("Item now swapped into position 1 previously had index: %d\n", ind_of_swapped_item);
	printf("%.0f,%.0f,%.0f (%d/%d)\n", x[0], x[1], x[2], x.get_n(), x.get_capacity());

	return 0;
}
