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
	#define Debug(x) printf("%s :", (#x)); _Debug(x)
	#define Debugln(x) printf("%s :", (#x)); _Debugln(x)
	#define Debug_Array(n,x) printf("%s :", (#x)); _Debug_Array((n), (x))
	#define Debugln_Array(n,x) printf("%s :", (#x)); _Debugln_Array((n), (x))
	#define NL printf("\n")
#endif
typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Math\Mod_Int\Mod_Int.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Math\NTT\Butterfly.cpp"

constexpr int kN = NTT_size((1 << 20) - 2);

Mint A[kN], B[kN];
int a[kN], b[kN];

int main() {
	int n, m; RP(n, m);
	RLP(n, a); RLP(m, b);
	for (int i = 1; i <= n; i++) A[i - 1] = a[i];
	for (int i = 1; i <= m; i++) B[i - 1] = b[i];

	NTT(A, kN);
	NTT(B, kN);
	for (int i = 0; i < kN; i++) A[i] *= B[i];
	NTT_Inv(A, kN);

	printf("%d", A[0]); for (int i = 1; i < n + m - 1; i++) printf(" %d", A[i]); printf("\n");
}
