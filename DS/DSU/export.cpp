// Exported by Exporter.exe

// Included from test.cpp
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


// Included from C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp
// --- Get ---
static inline char Get_Raw_Char() {
	static char buf[1 << 16], *p = buf, *end = buf;
	if (p == end) {
		if ((end = buf + fread(buf, 1, 1 << 16, stdin)) == buf) return '\0';
		p = buf;
	}
	return *p++;
}

// --- Read ---
template <typename T> static inline void Read_P(T &n) {
	static_assert(is_integral<T>::value);
	char c;
	while (!isdigit(c = Get_Raw_Char())) ;
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> static inline void Read(T &n) {
	static_assert(is_integral<T>::value);
	char c;
	bool neg = false;
	while (!isdigit(c = Get_Raw_Char())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> static inline void Read_Digit(T &n) {
	static_assert(is_integral<T>::value);
	char c;
	while (!isdigit(c = Get_Raw_Char())) ;
	n = int(c - '0');
	return ;
}

// --- Read multiple ---
template <typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read(n); return Read(Fargs...);}
template <typename T, typename... Targs> static inline void Read_Digit(T &n, Targs&... Fargs) {Read_Digit(n); return Read_Digit(Fargs...);}
template <typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P(n); return Read_P(Fargs...);}

// --- Read Loop ---
template <typename T> static inline void Read_Loop_i(int i, T *a) {return Read(a[i]);}
template <typename T, typename... Targs> static inline void Read_Loop_i(int i, T *a, Targs*... Fargs) {Read(a[i]); return Read_Loop_i(i, Fargs...);}
template <typename... Targs> static inline void Read_Loop(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) Read_Loop_i(i, Fargs...);}

template <typename T> static inline void Read_Loop_Digit_i(int i, T *a) {return Read_Digit(a[i]);}
template <typename T, typename... Targs> static inline void Read_Loop_Digit_i(int i, T *a, Targs*... Fargs) {Read_Digit(a[i]); return Read_Loop_Digit_i(i, Fargs...);}
template <typename... Targs> static inline void Read_Loop_Digit(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) Read_Loop_Digit_i(i, Fargs...);}

template <typename T> static inline void Read_Loop_P_i(int i, T *a) {return Read_P(a[i]);}
template <typename T, typename... Targs> static inline void Read_Loop_P_i(int i, T *a, Targs*... Fargs) {Read_P(a[i]); return Read_Loop_P_i(i, Fargs...);}
template <typename... Targs> static inline void Read_Loop_P(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) Read_Loop_P_i(i, Fargs...);}

// --- Float ---
template <int mul, typename T> static inline void Read(T &n) {
	char c;
	bool neg = false;
	while (!isdigit(c = Get_Raw_Char())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = Get_Raw_Char())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	while (cnt++ < mul) n = n * 10;

	if (neg) n = -n;
	return ;
}

template <int mul, typename T> static inline void Read_P(T &n) {
	char c;
	while (!isdigit(c = Get_Raw_Char())) ;
	
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	
	int cnt = 0;

	if (c == '.') {
		while (isdigit(c = Get_Raw_Char())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	while (cnt++ < mul) n = n * 10;
	return ;
}

template <int mul, typename T, typename... Targs> static inline void Read(T &n, Targs&... Fargs) {Read<mul>(n); return Read<mul>(Fargs...);}
template <int mul, typename T, typename... Targs> static inline void Read_P(T &n, Targs&... Fargs) {Read_P<mul>(n); return Read_P<mul>(Fargs...);}

// --- init ---
inline void IOS() {ios::sync_with_stdio(false); cin.tie(0);}
inline void Freopen(const char *in, const char *out) {freopen(in, "r", stdin); freopen(out, "w", stdout);}

// --- Output ---
template <typename T> void Print(T x) {
	if (x < 0) {
		printf("-");
		x = -x;
	}
	if (x == 0) printf("0");
	else {
		static int val[100];
		int idx = -1;
		while (x) {
			val[++idx] = x % 10;
			x /= 10;
		}
		while (idx >= 0) printf("%d", val[idx--]);
	}
} 
// End of C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp


// Included from C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp
template <typename T> inline void sort(vector<T> &v) {return sort(v.begin(), v.end());}
template <typename T> inline void sort_r(vector<T> &v) {return sort(v.begin(), v.end(), greater<T>());}

template <typename T> inline void reverse(vector<T> &v) {return reverse(v.begin(), v.end());}

template <typename T> inline void Merge(vector<T> &a, vector<T> &b, vector<T> &c) {
	if (c.size() < a.size() + b.size()) c.resize(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	return ;
}

template <typename T> inline void Discrete(vector<T> &v) {sort(v); v.resize(unique(v.begin(), v.end()) - v.begin());}

template <typename T> using PQ = priority_queue<T>;
template <typename T> using PQ_R = priority_queue<T, vector<T>, greater<T>>;

template <typename T> inline T ABS(T n) {return n >= 0 ? n : -n;}
template <typename T> inline T gcd(T a, T b) {return b ? gcd(b, a % b) : a;}
template <typename T> inline T lcm(T a, T b) {return a * b / gcd(a, b);}
template <typename T, typename... Targs> inline T min(T a, T b, T c, Targs... args) {return min(a, min(b, c, args...));}
template <typename T, typename... Targs> inline T max(T a, T b, T c, Targs... args) {return max(a, max(b, c, args...));}
template <typename T> inline void chmin(T &a, T b) {a = min(a, b); return ;}
template <typename T> inline void chmax(T &a, T b) {a = max(a, b); return ;}
template <typename T, typename... Targs> inline void chmin(T &a, T b, T c, Targs... args) {a = min(a, min(b, c, args...)); return ;}
template <typename T, typename... Targs> inline void chmax(T &a, T b, T c, Targs... args) {a = max(a, max(b, c, args...)); return ;}

template <typename T> inline int Digit_Sum(T a) {
	int ans = 0;
	while (a) {
		ans += a % 10;
		a /= 10;
	}
	return ans;
}
template <typename T> inline int Num_Length(T a) {
	int ans = 1;
	while (a /= 10) ans++;
	return ans;
}
// End of C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp


// Included from C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp
void _print(int x) {printf("%d", x);}
void _print(long long int x) {printf("%lld", x);}
void _print(double x) {printf("%lf", x);}
template <typename T1, typename T2> void _print(pair<T1, T2> x) {printf("("); _print(x.first); printf(", "); _print(x.second); printf(")");}

template <typename T> void _Debug(T x) {_print(x); printf("\n");}
template <typename T> void _Debug(vector<T> v) {
	if (v.empty()) printf(" empty");
	else for (T i : v) printf(" "), _print(i); 
	printf("\n");
}

template <typename T1, typename T2, typename T3> void _Debug(priority_queue<T1, T2, T3> pq) {
	if (pq.empty()) printf(" empty");
	else {
		while (!pq.empty()) {
			printf(" ");
			_print(pq.top());
			pq.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debug(queue<T> q) {
	if (q.empty()) printf(" empty");
	else {
		while (!q.empty()) {
			printf(" ");
			_print(q.front());
			q.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debug(stack<T> st) {
	if (st.empty()) printf(" empty");
	else {
		while (!st.empty()) {
			printf(" ");
			_print(st.top());
			st.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debug(deque<T> dq) {
	if (dq.empty()) printf(" empty");
	else {
		while (!dq.empty()) {
			printf(" ");
			_print(dq.front());
			dq.pop_front();
		}
	}
	printf("\n");
}

template <typename T> void _Debugln(vector<T> v) {
	if (v.empty()) printf(" empty\n");
	else {
		for (T i : v) printf("\n"), _print(i); 
		printf("\n");
	}
}

template <typename T1, typename T2, typename T3> void _Debugln(priority_queue<T1, T2, T3> pq) {
	if (pq.empty()) printf(" empty");
	else {
		while (!pq.empty()) {
			printf("\n");
			_print(pq.top());
			pq.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debugln(queue<T> q) {
	if (q.empty()) printf(" empty");
	else {
		while (!q.empty()) {
			printf("\n");
			_print(q.front());
			q.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debugln(stack<T> st) {
	if (st.empty()) printf(" empty");
	else {
		while (!st.empty()) {
			printf("\n");
			_print(st.top());
			st.pop();
		}
	}
	printf("\n");
}

template <typename T> void _Debugln(deque<T> dq) {
	if (dq.empty()) printf(" empty");
	else {
		while (!dq.empty()) {
			printf("\n");
			_print(dq.front());
			dq.pop_front();
		}
	}
	printf("\n");
}

template <typename T> void _Debug_Array(int n, const T *x) {for (int i = 1; i <= n; i++) printf(" "), _print(x[i]); printf("\n");}
template <typename T> void _Debugln_Array(int n, const T *x) {printf("\n"); for (int i = 1; i <= n; i++) _print(x[i]), printf("\n");}
// End of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp


// Included from C:\Users\ianli\Desktop\CP\template\DS\DSU\Undoable_DSU.cpp
// 0-based
struct Undoable_DSU {
	vector<pair<int, int>> opers;
	int *p;
	int size; 

	Undoable_DSU() {p = nullptr; size = 0;}

	void init(int n) {
		size = n;
		delete [] p; p = new int[size];
		memset(p, -1, sizeof(int) * size);
		opers.clear();
		return ;
	}

	int Find(int n) {
		if (p[n] < 0) return n;
		else {
			opers.push_back(make_pair(n, p[n]));
			return p[n] = Find(p[n]);
		}
	}

	inline int union_size(int n) const {return -p[n];}
	inline bool same(int l, int r) {return Find(l) == Find(r);}

	bool Merge(int l, int r) {
		l = Find(l), r = Find(r);
		if (l != r) {
			if (p[l] > p[r]) swap(l, r);
			opers.push_back(make_pair(l, p[l]));
			opers.push_back(make_pair(r, p[r]));
			p[l] += p[r];
			p[r] = l;
			return true;
		}
		else return false;
	}

	inline int cur_time() const {return int(opers.size());}
	void Undo_to_time(int t) {
		int _cur_time = cur_time();
		while (_cur_time-- > t) p[opers[_cur_time].F] = opers[_cur_time].S;
		opers.resize(t);
		return ;
	}
};
// End of C:\Users\ianli\Desktop\CP\template\DS\DSU\Undoable_DSU.cpp


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
// End of test.cpp

