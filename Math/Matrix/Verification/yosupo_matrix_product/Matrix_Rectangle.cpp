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

constexpr int kN = int(1E3 + 100);
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
#include "C:\Users\ianli\Desktop\CP\template\Math\Matrix\Matrix_Rectangle.cpp"

Matrix<Mint> A, B, C;

int a[kN][kN], b[kN][kN];

int main() {
	int n, m, k; RP(n, m, k);
	for (int i = 1; i <= n; i++) RLP(m, a[i]);
	for (int i = 1; i <= m; i++) RLP(k, b[i]);

	A.resize(n, m);
	B.resize(m, k);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) A[i - 1][j - 1] = a[i][j];
	for (int i = 1; i <= m; i++) for (int j = 1; j <= k; j++) B[i - 1][j - 1] = b[i][j];

	C = A * B;
	for (int i = 0; i < n; i++) {
		printf("%d", C[i][0]);
		for (int j = 1; j < k; j++) printf(" %d", C[i][j]);
		printf("\n");
	}
}
