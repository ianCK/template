#include "C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.h"

constexpr int kN = 1 << 20;
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

#include "All.h"
// using Mint = Mod_Int<kMod>;

int a[kN];
int dp[kN];
int ans[kN];

int main() {
	FastIO IO;

	int n, m; IO.RP(n, m);
	IO.RLP(n, a);

	int tot = 1 << 20;

	for (int i = 0; i < n; i++) dp[i] = a[n - i];

	SOSXor(tot, dp);

	for (int i = 1; i <= m; i++) ans[i] = dp[tot - i];

	IO.WP(ans[1]);
	for (int i = 2; i <= m; i++) {
		IO.WSpace();
		IO.WP(ans[i]);
	}
	IO.WLine();
}
