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
#include "C:\Users\ianli\Desktop\CP\template\DS\DSU\Undoable_DSU.cpp"

Undoable_DSU dsu;
int t[kN], k[kN], u[kN], v[kN];
vector<int> graph[kN];
vector<int> querys[kN];
int ans[kN];

void dfs(int cur) {
	int cur_time = dsu.cur_time();

	for (int i : querys[cur]) ans[i] = dsu.same(u[i], v[i]) ? 1 : 0;

	for (int i : graph[cur]) {
		dsu.Merge(u[i], v[i]);
		dfs(i);
		dsu.Undo_to_time(cur_time);
	}

	return ;
}

int main() {
	int n, q; RP(n, q);
	RL(q, t, k, u, v);
	for (int i = 1; i <= q; i++) k[i]++;

	for (int i = 1; i <= q; i++) {
		if (t[i]) querys[k[i]].PB(i);
		else graph[k[i]].PB(i);
	}

	dsu.init(n);
	dfs(0);

	for (int i = 1; i <= q; i++) if (t[i]) printf("%d\n", ans[i]);
}
