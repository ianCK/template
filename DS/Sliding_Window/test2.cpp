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
#else
	#define Debug(x) printf("%s :", (#x)); _Debug(x)
	#define Debugln(x) printf("%s :", (#x)); _Debugln(x)
	#define Debug_Array(n,x) printf("%s :", (#x)); _Debug_Array((n), (x))
	#define Debugln_Array(n,x) printf("%s :", (#x)); _Debugln_Array((n), (x))
#endif
typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(1E4 + 10);
// constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"
#include "C:\Users\ianli\Desktop\CP\template\DS\Sliding_Window\Sliding_Window_Static.cpp"
#include "C:\Users\ianli\Desktop\CP\template\DS\Sliding_Window\Default_Operations.cpp"

bitset<kN> val[kN];
int n, a[kN];
Sliding_Window_Static<bitset<kN>, SW_OR> sw1, sw2;

bool ok(int len) {
	sw1.reset(); sw2.reset();
	for (int i = len; i + len <= n; i++) if (sw1(i - len + 1, i) == sw2(i + 1, i + len)) return true;
	return false;
}

int main() {
	RP(n);
	RLP(n, a);

	vector<int> X(n);
	for (int i = 1; i <= n; i++) X[i - 1] = a[i];
	Discrete(X);
	for (int i = 1; i <= n; i++) a[i] = lower_bound(X.begin(), X.end(), a[i]) - X.begin();

	for (int i = 1; i <= n; i++) val[i][a[i]] = true;
	sw1.Link(val); sw2.Link(val);

	int l = 0, r = (n >> 1) + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (ok(mid)) l = mid;
		else r = mid;
	}

	printf("%d\n", l << 1);
}
