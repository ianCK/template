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

map<string, int> ma;
Dinic<int> dinic;
int val[6][6];

void solve(int n, int m) {
	static int p = []() -> int {
		ma["XS"] = 0;
		ma["S"] = 1;
		ma["M"] = 2;
		ma["L"] = 3;
		ma["XL"] = 4;
		ma["XXL"] = 5;
		return 1;
	}();

	memset(val, 0, sizeof(val));
	for (int i = 1; i <= m; i++) {
		string l, r; cin >> l >> r;
		val[ma[l]][ma[r]]++;
	}

	int S = 36 + 6, T = 36 + 6 + 1;
	dinic.init(36 + 6 + 2);
	for (int i = 0, now = 0; i < 6; i++) for (int j = i + 1; j < 6; j++, now++) {
		dinic.AddEdge(S, now, val[i][j] + val[j][i]);
		dinic.AddEdge(now, 36 + i, val[i][j] + val[j][i]);
		dinic.AddEdge(now, 36 + j, val[i][j] + val[j][i]);
	}
	for (int i = 0; i < 6; i++) dinic.AddEdge(36 + i, T, n / 6);

	if (dinic(S, T) == m) cout << "YES\n";
	else cout << "NO\n";

	return ;
}

int main() {
	int n, m;
	while (cin >> n >> m) solve(n, m);
}
