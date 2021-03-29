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
#include "C:\Users\ianli\Desktop\CP\template\Flow\Dinic\Dinic2.cpp"

Dinic<ll> dinic;
int v[kN], in[kN], out[kN], l[kN], r[kN];
vector<int> graph[kN];

int main() {
	int n; RP(n);
	RLP(n, v);
	int m; RP(m);
	RLP(m, l, r);

	dinic.init(n + n + 3);
	for (int i = 1; i <= m; i++) dinic.AddEdge(l[i] + n, r[i], min(v[l[i]], v[r[i]]));
	for (int i = 1; i <= m; i++) in[r[i]]++;
	for (int i = 1; i <= m; i++) out[l[i]]++;

	int S = n + n + 1, T = n + n + 2;
	for (int i = 1; i <= n; i++) if (!in[i]) dinic.AddEdge(S, i, v[i]);
	for (int i = 1; i <= n; i++) if (!out[i]) dinic.AddEdge(i + n, T, v[i]);
	for (int i = 1; i <= n; i++) dinic.AddEdge(i, i + n, v[i]);
	printf("%lld\n", dinic(S, T));
}
