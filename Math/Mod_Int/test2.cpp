#include <stdio.h>

struct test {
	int val;
	test() {
		printf("new\n");
		val = 0;
	}
	template <typename T> test(const T &a) {
		printf("template\n");
		val = a;
	}
	test(const test &a) {
		printf("here\n");
		val = a.val;
	}
	~test() {printf("destructed %d\n", val);}
};

void fun(test a, test b, test c) {
	printf("val : a = %d, b = %d, c = %d\n", a.val, b.val, c.val);
	return ;
}

int main() {
	test a, b(1), c = 2;
	printf("---\n");
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	printf("---\n");
	fun(a, b, c);
	printf("---\n");
	printf("val : a = %d, b = %d, c = %d\n", a.val, b.val, c.val);
}
