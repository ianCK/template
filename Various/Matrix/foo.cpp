#include "foo.h"

int main() {
	foo<2> a;
	foo<2, 3> b;

	a.bar(b);
}
