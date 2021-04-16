#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define MTP make_tuple
#define R Read
#define RD Read_Digit
#define RP Read_P
#define RL Read_Loop
#define RLD Read_Loop_Digit
#define RLP Read_Loop_P
#ifdef ONLINE_JUDGE
	#define Debug(x) ;
	#define Debugln(x) ;
	#define Debug_Array(n,x) ;
	#define Debugln_Array(n,x) ;
	#define NL ;
#else
	#define Debug(x) printf("%s :", (#x)), _Debug(x)
	#define Debugln(x) printf("%s :", (#x)), _Debugln(x)
	#define Debug_Array(n,x) printf("%s :", (#x)), _Debug_Array((n), (x))
	#define Debugln_Array(n,x) printf("%s :", (#x)), _Debugln_Array((n), (x))
	#define NL printf("\n")
#endif
typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(2E5 + 10);
// constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"
#include "C:\Users\ianli\Desktop\CP\template\DS\Dynamic_Convex_Hull\DCH.cpp"

struct seg_tree {
	DCH val[kN << 2];

	void init(int n, int l, int r, int *a, ll *s) {
		val[n].init();
		for (int i = l; i <= r; i++) val[n].insert(a[i], s[i]);

		if (l < r) {
			int mid = (l + r) >> 1;
			init(n << 1, l, mid, a, s);
			init(n << 1 | 1, mid + 1, r, a, s);
		}
		return ;
	}

	ll ask(int n, int l, int r, int L, int R, ll x) {
		if (L <= l && r <= R) return val[n](x);
		else if (L > r || l > R) return -kInf;
		else {
			int mid = (l + r) >> 1;
			return max(ask(n << 1, l, mid, L, R, x), ask(n << 1 | 1, mid + 1, r, L, R, x));
		}
	}
} sg;

int a[kN], l[kN], r[kN], w[kN];
int id[kN];
ll s[kN], mxf[kN], mxs[kN], mnf[kN], mns[kN];
ll mx[kN], mn[kN];

int main() {
	int n, q; RP(n, q);
	RL(n, a);
	RL(q, l, r, w);

	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

	for (int i = 1; i <= n; i++) mxf[i] = max(mxf[i - 1], s[i]);
	for (int i = 1; i <= n; i++) mnf[i] = min(mnf[i - 1], s[i]);
	mxs[n] = mns[n] = s[n];
	for (int i = n - 1; i >= 1; i--) mxs[i] = max(mxs[i + 1], s[i]);
	for (int i = n - 1; i >= 1; i--) mns[i] = min(mns[i + 1], s[i]);

	for (int i = 1; i <= q; i++) {
		if (l[i] > 1) {
			chmax(mx[i], mxf[l[i] - 1]);
			chmin(mn[i], mnf[l[i] - 1]);
		}

		if (r[i] < n) {
			chmax(mx[i], mxs[r[i] + 1] + ll(r[i] - l[i] + 1) * w[i]);
			chmin(mn[i], mns[r[i] + 1] + ll(r[i] - l[i] + 1) * w[i]);
		}
	}

	for (int i = 1; i <= n; i++) id[i] = i;

	sg.init(1, 1, n, id, s);
	for (int i = 1; i <= q; i++) chmax(mx[i], sg.ask(1, 1, n, l[i], r[i], w[i]) - ll(l[i] - 1) * w[i]);

	for (int i = 1; i <= n; i++) id[i] = -id[i];
	for (int i = 1; i <= n; i++) s[i] = -s[i];

	sg.init(1, 1, n, id, s);
	for (int i = 1; i <= q; i++) chmin(mn[i], -sg.ask(1, 1, n, l[i], r[i], w[i]) - ll(l[i] - 1) * w[i]);

	for (int i = 1; i <= q; i++) printf("%lld\n", mx[i] - mn[i]);
}
