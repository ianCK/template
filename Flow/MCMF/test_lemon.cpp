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

constexpr int kN = 60;
// constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Flow\MCMF\LEMON.cpp"

int a[kN][kN];
int rid[kN], cid[kN], rcid[kN << 1];
bitset<kN> used[kN];

int main() {
	int n, k; RP(n, k);
	for (int i = 1; i <= n; i++) RLP(n, a[i]);

	int itr = 0;
	for (int i = 1; i <= n; i++) rid[i] = itr++;
	for (int i = 1; i <= n; i++) cid[i] = itr++;
	for (int i = 1; i <= n; i++) rcid[cid[i]] = i;

	int S = itr++;
	int T = itr++;

	mcf_graph_ns<int, ll> mcmf(itr);

	for (int i = 1; i <= n; i++) mcmf.add_edge(S, rid[i], 0, k, 0);
	for (int i = 1; i <= n; i++) mcmf.add_edge(cid[i], T, 0, k, 0);

	ll ans = 0;
	ans += ll(kInf) * n * k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) mcmf.add_edge(rid[i], cid[j], 0, 1, kInf - a[i][j]);
	for (int i = 1; i <= n; i++) mcmf.add_edge(rid[i], T, 0, k, kInf);

	mcmf.set_supply(S, n * k);
	mcmf.set_supply(T, -(n * k));

	ans -= mcmf.solve();
	printf("%lld\n", ans);

	//auto edges = mcmf.Edges();
	//for (auto e : edges) if (e.from != S && e.to != T && e.flow != 0) used[e.from + 1][e.to - n + 1] = true;

	int rid_l = rid[1], rid_r = rid[n];

	for (auto edge : mcmf.Edges) if (rid_l <= edge.from and edge.from <= rid_r and mcmf.flow[edge.eid] == 1) {
		used[edge.from - rid_l + 1][rcid[edge.to]] = true;
	}
	
	//for (int i = 1; i <= n; i++) for (MCMF<ll>::Edge ed : mcmf.graph[rid[i]]) if (ed.to != T && ed.cap == 0) 
	//	used[i][rcid[ed.to]] = true;

	for (int i = 1; i <= n; i++, printf("\n")) for (int j = 1; j <= n; j++) printf("%c", used[i][j] ? 'X' : '.');
}
