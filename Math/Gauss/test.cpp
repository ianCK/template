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

constexpr int kN = int(6E2 + 10);
// constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Math\Gauss\Gauss.cpp"

Gauss<double> gauss;
int a[kN][kN], b[kN];

void solve() {
	int n; RP(n);
	for (int i = 1; i <= n; i++) {
		RL(n, a[i]);
		R(b[i]);
	}

	gauss.reset(n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) gauss.set(i - 1, j - 1, a[i][j]);
	for (int i = 1; i <= n; i++) gauss.set_constant(i - 1, b[i]);
	//gauss.need_piviting();
	for (int i = 1; i <= n; i++) printf("%.10e\n", gauss[i - 1]);
	return ;
}

int main() {
	int t; RP(t);
	for (int i = 1; i <= t; i++) {
		solve();
	}
}
