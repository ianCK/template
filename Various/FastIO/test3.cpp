#include "C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.h"

constexpr int kN = int(1E5 + 10);
// constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;
// constexpr int dx[4] = {0, 0, 1, -1};
// constexpr int dy[4] = {1, -1, 0, 0};
// constexpr int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
// constexpr int dy[8] = {1, -1, 1, -1, -1, 1, 0, 0};

// using Mint = Mod_Int<kMod>;

template <int A> class cA {
	public:
		template <typename T> T val(T v);
};

template <int A> template <typename T> T cA<A>::val(T v) { return v + A; }

int main() {

	cA<1> a;
	printf("%d\n", a.val(3));
}
