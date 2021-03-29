// Compile flags -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define MTP make_tuple
typedef long long int ll;
template <typename T> T ABS(T n) {return n >= 0 ? n : -n;}
constexpr int kN = int(1E5 + 10);
// constexpr int kMod = 998244353;
// constexpr int kInf = 0x3f3f3f3f
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Graph\Bipartite_Matching.cpp"
Bipartite_Matching BM;

void solve(int n, int k) {
	BM.init(n, n);
	for (int i = 1; i <= k; i++) {
		int r, c;
		scanf("%d%d", &r, &c);
		BM.AddEdge(r - 1, c - 1);
	}
	printf("%d\n", BM());
	return ;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("file_name", "r", stdin);
	//freopen("file_name", "w", stdout);
	//fstream input, output;
	//input.open("file_name", ios::in);
	//output.open("file_name", ios::out);
	int testcase = 0;
	while (true) {
		int n, k;
		scanf("%d%d", &n, &k);
		if (n == 0 && k == 0) break;
		printf("Case #%d:", ++testcase); solve(n, k);
	}
	//input.close();
	//output.close();
}
