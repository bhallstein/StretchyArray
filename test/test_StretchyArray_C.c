//
// test_StretchyArray_C.cpp - tests for stretchyarray (TODO: finish)
//

#include <stdio.h>
#include "../StretchyArray_C.h"

#define p_assert(x) do {             \
		printf("%60s", #x);    \
		assert(x);                   \
		printf(" - PASS :)\n");      \
	} while (false)

#define p_header(s) do {                               \
		printf("  %s  \n", s);                     \
	} while (false)


struct X {
	int a, b, c;
};
void print(struct X x) {
	printf("a:%d b:%d c:%d\n", x.a, x.b, x.c);
}


int main() {
	struct StretchyArray_C a = stretchyArray_make(8, sizeof(struct X));
	
	struct X s1 = {
		1, 2, 3
	};
	struct X s2 = {
		4, 6, 8
	};
	stretchyArray_add(&a, (char*) &s1);
	stretchyArray_add(&a, (char*) &s2);
	
	printf("%d %d %d\n", a.capacity, a.size, a.bytes_per_element);
	print(*(struct X *)stretchyArray_get(&a, 0));
	print(*(struct X *)stretchyArray_get(&a, 1));
	
	return 0;
}


