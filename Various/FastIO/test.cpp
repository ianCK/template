#include "C:\Users\ianli\Desktop\CP\template\Various\Pragma\Pragma.cpp"
#include "C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.h"

constexpr int kN = int(1E6 + 10);
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

#include "C:\Users\ianli\Desktop\CP\template\Various\FastIO\FastIO.h"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"

// using Mint = Mod_Int<kMod>;

ll a[kN], b[kN];
ll ans[kN];

int main() {
	FastIO IO("test1", stdout);

	int t; IO.RP(t);
	IO.RLP(t, a, b);

	for (int i = 1; i <= t; i++) ans[i] = a[i] + b[i];

	for (int i = 1; i <= t; i++) IO.W(ans[i], '\n');
}
