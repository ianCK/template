// Compile flags -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2
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
typedef long long int ll;

constexpr int kN = int(1E3 + 10);
// constexpr int kMod = 998244353;
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;

template <typename T> T ABS(T n) {return n >= 0 ? n : -n;}

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
int dp[kN][kN];

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("file_name", "r", stdin);
	//freopen("file_name", "w", stdout);
	int *p = dp;
	for (int i = 1; i <= 5; i++) for (int j = 1; j <= 5; j++) dp[i][j] = i - j;
	for (int i = 1; i <= 5; i++, printf("\n")) for (int j = 1; j <= 5; j++) printf("%d ", p[i][j]);


}
