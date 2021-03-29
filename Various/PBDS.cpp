#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, int> table;
int main() {
	table[3] = 5;
	printf("%d\n", table[3]);
}
