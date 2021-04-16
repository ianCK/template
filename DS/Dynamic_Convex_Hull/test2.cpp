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

int a[kN], l[kN], r[kN], w[kN];
int id[kN];
ll s[kN], mxf[kN], mxs[kN], mnf[kN], mns[kN];
ll mx[kN], mn[kN], tmp[kN];

DCH dch;

void solve(int cur_l, int cur_r, vector<int> q, ll* tar) {
	dch.init();
	for (int i = cur_l; i <= cur_r; i++) dch.insert(id[i], s[i]);
	for (int i : q) if (l[i] <= cur_l && cur_r <= r[i]) chmax(tar[i], dch(w[i]));

	if (cur_l < cur_r) {
		int mid = (cur_l + cur_r) >> 1;
		vector<int> ql, qr;
		for (int i : q) {
			if (l[i] <= cur_l && cur_r <= r[i]) continue;
			if (l[i] <= mid) ql.PB(i);
			if (r[i] > mid) qr.PB(i);
		}
		solve(cur_l, mid, ql, tar);
		solve(mid + 1, cur_r, qr, tar);
	}

	return ;
}

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

	vector<int> qu(q);
	for (int i = 1; i <= q; i++) qu[i - 1] = i;
	for (int i = 1; i <= q; i++) tmp[i] = -kInf;
	solve(1, n, qu, tmp);
	for (int i = 1; i <= q; i++) chmax(mx[i], tmp[i] - ll(l[i] - 1) * w[i]); 

	for (int i = 1; i <= n; i++) id[i] = -id[i];
	for (int i = 1; i <= n; i++) s[i] = -s[i];

	for (int i = 1; i <= q; i++) tmp[i] = -kInf;
	solve(1, n, qu, tmp);
	for (int i = 1; i <= q; i++) chmin(mn[i], -tmp[i] - ll(l[i] - 1) * w[i]);

	for (int i = 1; i <= q; i++) printf("%lld\n", mx[i] - mn[i]);
}
