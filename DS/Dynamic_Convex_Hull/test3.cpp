// yosupo Line Add Get Min
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
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"
#include "C:\Users\ianli\Desktop\CP\template\DS\Dynamic_Convex_Hull\DCH.cpp"

DCH dch;
ll t[kN], a[kN], b[kN], qa[kN], qb[kN], p[kN];
ll ans[kN];

int main() {
	int n, q; RP(n, q);
	RL(n, a, b);
	for (int i = 1; i <= q; i++) {
		RD(t[i]);
		if (!t[i]) R(qa[i], qb[i]);
		else R(p[i]);
	}

	dch.init();
	for (int i = 1; i <= n; i++) dch.insert(-a[i], -b[i]);

	for (int i = 1; i <= q; i++) {
		if (!t[i]) dch.insert(-qa[i], -qb[i]);
		else ans[i] = -dch(p[i]);
	}

	for (int i = 1; i <= q; i++) if (t[i]) printf("%lld\n", ans[i]);
}
