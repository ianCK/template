// cf 1511 F
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

constexpr int kN = 170;
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
#include "C:\Users\ianli\Desktop\CP\template\Math\Matrix\Matrix.cpp"

string s[kN];
int idx[kN][kN][kN];
int len[kN];
Matrix<Mint> A;

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s[i];

	for (int i = 1; i <= n; i++) len[i] = int(s[i].size());

	constexpr int kLen = 5;

	int cur = 0;
	// idx : lst s, len diff, wait

	for (int i = 1; i <= n; i++) for (int j = 1; j < len[i]; j++) for (int k = 0; k < kLen; k++) 
		idx[i][j][k] = cur++;

	for (int i = 0; i < kLen; i++) idx[0][0][i] = cur++;

	A.resize(cur);

	for (int i = 1; i <= n; i++) A[idx[0][0][len[i] - 1]][idx[0][0][0]]++;

	for (int i = 1; i <= n; i++) for (int j = 1; j < len[i]; j++) for (int k = 1; k < kLen; k++)
		A[idx[i][j][k - 1]][idx[i][j][k]]++;

	for (int i = 1; i < kLen; i++) A[idx[0][0][i - 1]][idx[0][0][i]]++;

	auto match = [&](int x, int idx, int y, int idy, int len) -> bool {
		for (int i = 0; i < len; i++) if (s[x][idx + i] != s[y][idy + i]) return false;
		return true;
	};

	for (int i = 1; i <= n; i++) for (int j = 1; j < len[i]; j++) for (int k = 1; k <= n; k++) {
		int mn = min(j, len[k]);
		if (!match(i, len[i] - j, k, 0, mn)) continue;

		if (len[k] == j) A[idx[0][0][j - 1]][idx[i][j][0]]++;
		else if (len[k] < j) A[idx[i][j - len[k]][len[k] - 1]][idx[i][j][0]]++;
		else A[idx[k][len[k] - j][j - 1]][idx[i][j][0]]++;
	}

	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
		int mn = min(len[i], len[j]);
		if (match(i, 0, j, 0, mn)) {
			if (len[i] < len[j]) A[idx[j][len[j] - len[i]][mn - 1]][idx[0][0][0]] += 2;
			else A[idx[i][len[i] - len[j]][mn - 1]][idx[0][0][0]] += 2;
		}
	}

	Mint ans = Pow(A, m)[idx[0][0][0]][idx[0][0][0]];
	printf("%d\n", ans);
}
