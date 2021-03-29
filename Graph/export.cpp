// Exported by Exporter.exe

// Included from test.cpp
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

// Included from C:\Users\ianli\Desktop\CP\template\Various\Fast_IO.cpp
static inline char Get_Raw_Char() {
	static char buf[1 << 16], *p = buf, *end = buf;
	if (p == end) {
		if ((end = buf + fread(buf, 1, 1 << 16, stdin)) == buf) return '\0';
		p = buf;
	}
	return *p++;
}

static inline int Get_Digit() {
	char c = Get_Raw_Char();
	while (!isdigit(c)) c = Get_Raw_Char();
	return int(c - '0');
}

static inline int Get_PInt() {
	char c = Get_Raw_Char();
	int ret;
	while (!isdigit(c)) c = Get_Raw_Char();
	ret = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) ret = ret * 10 + int(c - '0');
	return ret;
}

static inline int Get_Int() {
	char c = Get_Raw_Char();
	bool neg = false;
	int ret;
	while (!isdigit(c)) {
		if (c == '-') neg = true;
		c = Get_Raw_Char();
	}
	ret = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) ret = ret * 10 + int(c - '0');
	if (neg) return -ret;
	return ret;
}

static inline long long int Get_ll() {
	char c = Get_Raw_Char();
	bool neg = false;
	long long int ret;
	while (!isdigit(c)) {
		if (c == '-') neg = true;
		c = Get_Raw_Char();
	}
	ret = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) ret = ret * 10 + int(c - '0');
	if (neg) return -ret;
	return ret;
}

static inline long long int Get_Pll() {
	char c = Get_Raw_Char();
	long long int ret;
	while (!isdigit(c)) c = Get_Raw_Char();
	ret = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) ret = ret * 10 + int(c - '0');
	return ret;
}

template <typename T> static inline void Read_P(T &n) {
	static_assert(is_integral<T>::value);
	char c = Get_Raw_Char();
	while (!isdigit(c)) c = Get_Raw_Char();
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> static inline void Read(T &n) {
	static_assert(is_integral<T>::value);
	char c = Get_Raw_Char();
	bool neg = false;
	while (!isdigit(c)) {
		if (c == '-') neg = true;
		c = Get_Raw_Char();
	}
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> static inline void Read_Digit(T &n) {
	static_assert(is_integral<T>::value);
	char c = Get_Raw_Char();
	while (!isdigit(c)) c = Get_Raw_Char();
	n = int(c - '0');
	return ;
}

template <typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {
	Read(n);
	return Read(Fargs...);
}

template <typename T, typename... Targs> static inline void Read_Digit(T &n, Targs&... Fargs) {
	Read_Digit(n);
	return Read_Digit(Fargs...);
}

template <typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {
	Read_P(n);
	return Read_P(Fargs...);
}
// End of C:\Users\ianli\Desktop\CP\template\Various\Fast_IO.cpp


// Included from C:\Users\ianli\Desktop\CP\template\Graph\Bipartite_Matching.cpp
// kN = #(left vertices), kM = #(right vertices)
// AddEdge(left_vertex, right_vertex)
// MaxMatch(#(left vertices)) -> matchx, matchy
// 0-based

struct Bipartite_Matching {
	struct Edge {int ed, next;};
	vector<Edge> edge;
	vector<int> head, disx, disy, matchx, matchy;
	vector<bool> vis;
	int bfs_dis, x_size, y_size;

	void init(int n, int m) {
		x_size = n, y_size = m;
		edge.clear();
		head.clear(); head.resize(x_size, -1);
		disx.clear(); disx.resize(x_size);
		disy.clear(); disy.resize(y_size);
		matchx.clear(); matchx.resize(x_size);
		matchy.clear(); matchy.resize(y_size);
		vis.clear(); vis.resize(y_size);
		return ;
	}

	void AddEdge(int a, int b) {
		edge.push_back({b, head[a]});
		head[a] = int(edge.size()) - 1;
		return ;
	}

	bool Bfs(int v) {
		queue<int> que;
		bfs_dis = v << 1;
		fill(disx.begin(), disx.end(), -1);
		fill(disy.begin(), disy.end(), -1);

		for (int i = 0; i < v; ++i) if (matchx[i] < 0) {
			disx[i] = 0;
			que.push(i);
		}

		while (!que.empty()) {
			int x = que.front();
			que.pop();
			if (disx[x] > bfs_dis) break;
			for (int i = head[x]; i >= 0; i = edge[i].next) {
				int y = edge[i].ed;
				if (disy[y] < 0) {
					disy[y] = disx[x] + 1;
					if (matchy[y] < 0) bfs_dis = disy[y];
					else {
						disx[matchy[y]] = disy[y] + 1;
						que.push(matchy[y]);
					}
				}
			}
		}
		return bfs_dis < (v << 1);
	}

	bool Dfs(int x) {
		for (int i = head[x]; i >= 0; i = edge[i].next) {
			int y = edge[i].ed;
			if (!vis[y] && disy[y] == disx[x] + 1) {
				vis[y] = true;
				if (matchy[y] >= 0 && disy[y] == bfs_dis) continue;
				if (matchy[y] < 0 || Dfs(matchy[y])) {
					matchx[x] = y;
					matchy[y] = x;
					return true;
				}
			}
		}
		return false;
	}

	int MaxMatch() {
		int ret = 0;
		fill(matchx.begin(), matchx.end(), -1);
		fill(matchy.begin(), matchy.end(), -1);
		while (Bfs(x_size)) {
			fill(vis.begin(), vis.end(), false);
			for (int i = 0; i < x_size; ++i) if (matchx[i] < 0 && Dfs(i)) ++ret;
		}
		return ret;
	}

	int operator ()() {return MaxMatch();}
};
// End of C:\Users\ianli\Desktop\CP\template\Graph\Bipartite_Matching.cpp

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
// End of test.cpp

