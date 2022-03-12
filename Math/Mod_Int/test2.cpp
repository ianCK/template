#include <stdio.h>
constexpr int kN = 100;
int main() {
#if kN == 100
	printf("100\n");
#else
	printf("bad\n");
#endif
}
