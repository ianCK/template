// yosupo
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
	#define Debug(x) _Debug((#x), (x))
	#define Debugln(x) _Debugln((#x), (x))
	#define Debug_Array(n,x) _Debug_Array((n), (#x), (x))
	#define Debugln_Array(n,x) _Debugln_Array((n), (#x), (x))
#endif
typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(1E5 + 10);
// constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Graph\Chromatic\Chromatic.cpp"

Chromatic graph;
int u[kN], v[kN];

int main() {
	int n, m; RP(n, m);
	RLP(m, u, v);

	graph.init(n);
	for (int i = 1; i <= m; i++) graph.AddEdge(u[i], v[i]);
	printf("%d\n", graph());
}
