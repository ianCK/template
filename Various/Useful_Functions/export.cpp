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
typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(1E5 + 10);
// constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;


// Included from C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO_short.cpp
#define SIV static inline void
#define ID isdigit
#define W while
#define TT template <typename T>
#define TTX template <typename T, typename ...Ta>
#define TX template <typename ...Ta>

bool Fast_IO_activated = false;
bool IOS_activated = false;
static inline char Z_G() {
	static bool pre = Fast_IO_activated = true;
	static char buf[1 << 16], *p = buf, *end = buf;
	if (p == end) {
		if ((end = buf + fread(buf, 1, 1 << 16, stdin)) == buf) return '\0';
		p = buf;
	}
	return *p++;
}

TT SIV Read_P(T &n) {
	char c;
	W (!ID(c = Z_G())) ;
	n = int(c - '0');
	W (ID(c = Z_G())) n = n * 10 + int(c - '0');
}

TT SIV Read(T &n) {
	char c;
	bool neg = false;
	W (!ID(c = Z_G())) if (c == '-') neg = true;
	n = int(c - '0');
	W (ID(c = Z_G())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
}

TT SIV Read_Digit(T &n) {
	char c;
	W (!ID(c = Z_G())) ;
	n = int(c - '0');
}

SIV Read_String(string &s) {
	char c = Z_G();
	W (c == ' ' or c == '\n') c = Z_G();
	W (c != ' ' and c != '\n') {
		s += c;
		c = Z_G();
	}
}

TTX SIV Read(T &n, Ta&... Fa) {Read(n); Read(Fa...);}
TTX SIV Read_Digit(T &n, Ta&... Fa) {Read_Digit(n); Read_Digit(Fa...);}
TTX SIV Read_P(T &n, Ta&... Fa) {Read_P(n); Read_P(Fa...);}
TX SIV Read_String(string &s, Ta&... Fa) {Read_String(s); Read_String(Fa...);}

TT SIV Read_Loop_i(int i, T *a) {Read(a[i]);}
TTX SIV Read_Loop_i(int i, T *a, Ta*... Fa) {Read(a[i]); Read_Loop_i(i, Fa...);}
TX SIV Read_Loop(int n, Ta*... Fa) {for (int i = 1; i <= n; i++) Read_Loop_i(i, Fa...);}

TT SIV Read_Loop_Digit_i(int i, T *a) {Read_Digit(a[i]);}
TTX SIV Read_Loop_Digit_i(int i, T *a, Ta*... Fa) {Read_Digit(a[i]); Read_Loop_Digit_i(i, Fa...);}
TX SIV Read_Loop_Digit(int n, Ta*... Fa) {for (int i = 1; i <= n; i++) Read_Loop_Digit_i(i, Fa...);}

TT SIV Read_Loop_P_i(int i, T *a) {Read_P(a[i]);}
TTX SIV Read_Loop_P_i(int i, T *a, Ta*... Fa) {Read_P(a[i]); Read_Loop_P_i(i, Fa...);}
TX SIV Read_Loop_P(int n, Ta*... Fa) {for (int i = 1; i <= n; i++) Read_Loop_P_i(i, Fa...);}

SIV Read_Loop_String_i(int i, string *a) {Read_String(a[i]);}
TX SIV Read_Loop_String_i(int i, string *a, Ta*... Fa) {Read_String(a[i]); Read_Loop_String_i(i, Fa...);}
TX SIV Read_Loop_String(int n, Ta*... Fa) {for (int i = 1; i <= n; i++) Read_Loop_String_i(i, Fa...);}

template <int mul, typename T> SIV Read(T &n) {
	char c;
	bool neg = false;
	W (!ID(c = Z_G())) if (c == '-') neg = true;
	n = int(c - '0');
	W (ID(c = Z_G())) n = n * 10 + int(c - '0');

	int cnt = 0;

	if (c == '.') {
		W (ID(c = Z_G())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	W (cnt++ < mul) n = n * 10;

	if (neg) n = -n;
}

template <int mul, typename T> SIV Read_P(T &n) {
	char c;
	W (!ID(c = Z_G())) ;

	n = int(c - '0');
	W (ID(c = Z_G())) n = n * 10 + int(c - '0');

	int cnt = 0;

	if (c == '.') {
		W (ID(c = Z_G())) {
			n = n * 10 + int(c - '0');
			cnt++;
		}
	}

	W (cnt++ < mul) n = n * 10;
}

template <int mul, typename T, typename... Ta> SIV Read(T &n, Ta&... Fa) {Read<mul>(n); Read<mul>(Fa...);}
template <int mul, typename T, typename... Ta> SIV Read_P(T &n, Ta&... Fa) {Read_P<mul>(n); Read_P<mul>(Fa...);}

void IOS() {
	IOS_activated = true;
	ios::sync_with_stdio(false); cin.tie(0);
}
void Freopen(const char *in, const char *out) {freopen(in, "r", stdin); freopen(out, "w", stdout);} 

TT void Print(T x) {
	if (x < 0) {
		printf("-");
		x = -x;
	}
	if (x == 0) printf("0");
	else {
		static int val[100];
		int idx = -1;
		W (x) {
			val[++idx] = x % 10;
			x /= 10;
		}
		W (idx >= 0) printf("%d", val[idx--]);
	}
} 
#undef SIV
#undef ID
#undef W
#undef TT
#undef TTX
#undef TX
// End of C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO_short.cpp

// Included from C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions_short.cpp
#define IV inline void
#define TT template <typename T>
#define TTX template <typename T, typename... Ta>
#define V vector
#define RT return
TT IV sort(V<T> &v) {sort(v.begin(), v.end());}
TT IV sort_r(V<T> &v) {sort(v.begin(), v.end(), greater<T>());}
IV sort(string &s) {sort(s.begin(), s.end());}
IV sort_r(string &s) {sort(s.begin(), s.end(), greater<char>());}

TT IV reverse(V<T> &v) {reverse(v.begin(), v.end());}
IV reverse(string &s) {reverse(s.begin(), s.end());}

TT IV Merge(V<T> &a, V<T> &b, V<T> &c) {
	if (c.size() < a.size() + b.size()) c.resize(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
}
TT IV Concatanate(V<T> &a, V<T> &b, V<T> &c) {
	int a_size = int(a.size()), b_size = int(b.size());
	c.resize(a_size + b_size);
	for (int i = 0; i < a_size; i++) c[i] = a[i];
	for (int i = 0; i < b_size; i++) c[i + a_size] = b[i];
}

TT IV Discrete(V<T> &v) {sort(v); v.resize(unique(v.begin(), v.end()) - v.begin());}
TT inline int Discrete_Id(V<T> &v, T x) {return lower_bound(v.begin(), v.end(), x) - v.begin();}

TT using PQ = priority_queue<T>;
TT using PQ_R = priority_queue<T, V<T>, greater<T>>;

TT inline T ABS(T n) {RT n >= 0 ? n : -n;}
TT __attribute__((target("bmi"))) inline T gcd(T a, T b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (a == 0 || b == 0) RT a + b;
	int n = __builtin_ctzll(a);
	int m = __builtin_ctzll(b);
	a >>= n;
	b >>= m;
	while (a != b) {
		int m = __builtin_ctzll(a - b);
		bool f = a > b;
		T c = f ? a : b;
		b = f ? b : a;
		a = (c - b) >> m;
	}
	RT a << min(n, m);
}
TT inline T lcm(T a, T b) {RT a * (b / gcd(a, b));}
TTX inline T gcd(T a, T b, T c, Ta... ar) {RT gcd(a, gcd(b, c, ar...));}
TTX inline T lcm(T a, T b, T c, Ta... ar) {RT lcm(a, lcm(b, c, ar...));}
TTX inline T min(T a, T b, T c, Ta... ar) {RT min(a, min(b, c, ar...));}
TTX inline T max(T a, T b, T c, Ta... ar) {RT max(a, max(b, c, ar...));}
TTX IV chmin(T &a, T b, Ta... ar) {a = min(a, b, ar...);}
TTX IV chmax(T &a, T b, Ta... ar) {a = max(a, b, ar...);}

V<int> Primes(int n) {
	if (n == 1) RT {};
	V<int> primes;
	V<bool> isPrime(n + 1, true);

	primes.reserve(n / __lg(n));

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) primes.push_back(i);
		for (int j : primes) {
			if (i * j > n) break;
			isPrime[i * j] = false;
			if (i % j == 0) break;
		}
	}
	RT primes;
}

TT V<T> factors(T x) {
	V<T> ans;
	for (T i = 1; i * i <= x; i++) if (x % i == 0) ans.push_back(i);

	int id = int(ans.size()) - 1;
	if (ans[id] * ans[id] == x) id--;
	for (int i = id; i >= 0; i--) ans.push_back(x / ans[i]);

	RT ans;
}

int mex(V<int> vec) {
	int n = int(vec.size());
	V<bool> have(n, false);
	for (int i : vec) if (i < n) have[i] = true;
	for (int i = 0; i < n; i++) if (!have[i]) RT i;
	RT n;
}

TT T SQ(T x) {RT x * x;}
TT T Mdist(pair<T, T> lhs, pair<T, T> rhs) {RT ABS(lhs.first - rhs.first) + ABS(lhs.second - rhs.second);}
TT T Dist2(pair<T, T> lhs, pair<T, T> rhs) {RT SQ(lhs.F - rhs.F) + SQ(lhs.S - rhs.S);}
TT T LUBound(T LB, T val, T UB) {RT min(max(LB, val), UB);}

template <typename T, typename Comp> T Binary_Search(T L, T R, Comp f) {
	while (R - L > 1) {
		T mid = (L + R) >> 1;
		if (f(mid)) L = mid;
		else R = mid;
	}
	RT L;
}

template <typename Comp> double Binary_Search(double L, double R, Comp f, int n = 30) {
	for (int i = 1; i <= n; i++) {
		double mid = (L + R) / 2;
		if (f(mid)) L = mid;
		else R = mid;
	}
	RT L;
}

TT T nearest(set<T> &se, T val) {
	static constexpr T kInf = numeric_limits<T>::max() / 2 - 10;

	if (se.empty()) RT kInf;
	else if (val <= *se.begin()) RT *se.begin() - val;
	else if (val >= *prev(se.end())) RT val - *prev(se.end());
	else {
		auto u = se.lower_bound(val);
		auto v = prev(u);
		RT min(*u - val, val - *v);
	}
}

namespace MR32 {
	using ull = unsigned long long int;
	using uint = unsigned int;
	ull PowMod(ull a, ull b, ull kMod) {
		ull ans = 1;
		for (; b; b >>= 1, a = a * a % kMod) if (b & 1) ans = ans * a % kMod;
		RT ans;
	}

	bool IsPrime(uint x) {
		static constexpr bool low[8] = {false, false, true, true, false, true, false, true};
		static constexpr uint as = 3, a[3] = {2, 7, 61};
		if (x < 8) RT low[x];

		uint t = x - 1;
		int r = 0;
		while ((t & 1) == 0) {
			t >>= 1;
			r++;
		}
		for (uint i = 0; i < as; i++) if (a[i] <= x - 2) {
			bool ok = false;
			ull tt = PowMod(a[i], t, x);
			if (tt == 1) continue;
			for (int j = 0; j < r; j++, tt = tt * tt % x) if (tt == x - 1) {
				ok = true;
				break;
			}
			if (!ok) RT false;
		}
		RT true;
	}
}

#ifdef __SIZEOF_INT128__
namespace MR64 {
	using uint128 = unsigned __int128;
	using ull = unsigned long long int;
	using uint = unsigned int;
	uint128 PowMod(uint128 a, uint128 b, uint128 kMod) {
		uint128 ans = 1;
		for (; b; b >>= 1, a = a * a % kMod) if (b & 1) ans = ans * a % kMod;
		RT ans;
	}

	bool IsPrime(ull x) {
		static constexpr bool low[8] = {false, false, true, true, false, true, false, true};
		static constexpr uint as = 7, a[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
		if (x < 8) RT low[x];
		ull t = x - 1;
		int r = 0;
		while ((t & 1) == 0) {
			t >>= 1;
			r++;
		}
		for (uint i = 0; i < as; i++) if (a[i] <= x - 2) {
			bool ok = false;
			uint128 tt = PowMod(a[i], t, x);
			if (tt == 1) continue;
			for (int j = 0; j < r; j++, tt = tt * tt % x) if (tt == x - 1) {
				ok = true;
				break;
			}
			if (!ok) RT false;
		}
		RT true;
	}
}
#endif

bool IsPrime(unsigned long long int x) {
#ifdef __SIZEOF_INT128__
	if ((x >> 32) == 0) RT MR32::IsPrime(x);
	else RT MR64::IsPrime(x);
#endif
	RT MR32::IsPrime(x);
}

#ifdef __SIZEOF_INT128__
uint64_t PollardRho(uint64_t x) {
	static mt19937 rng;
	if (!(x & 1)) RT 2;
	if (IsPrime(x)) RT x;
  int64_t a = rng() % (x - 2) + 2, b = a;
  uint64_t c = rng() % (x - 1) + 1, d = 1;
  while (d == 1) {
    a = (__int128(a) * a + c) % x;
    b = (__int128(b) * b + c) % x;
    b = (__int128(b) * b + c) % x;
    d = __gcd(uint64_t(abs(a - b)), x);
    if (d == x) RT PollardRho(x);
  }
  RT d;
}
#endif

TT V<T> factorize(T x) {
	if (x <= 1) RT {};
	T p = PollardRho(x);
	if (p == x) RT {x};
	V<T> ans, lhs = factorize(p), rhs = factorize(x / p);
	Merge(lhs, rhs, ans);
	RT ans;
}

TT V<pair<T, int>> Compress(V<T> vec) {
	if (vec.empty()) RT {};

	V<pair<T, int>> ans;
	int cnt = 1, sz = int(vec.size());
	T lst = vec[0];
	for (int i = 1; i < sz; i++) {
		if (lst != vec[i]) {
			ans.push_back(make_pair(lst, cnt));
			lst = vec[i];
			cnt = 1;
		}
		else cnt++;
	}
	ans.push_back(make_pair(lst, cnt));
	RT ans;
}
#undef IV
#undef TT
#undef TTX
#undef V
#undef RT
// End of C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions_short.cpp

int main() {

}
// End of test.cpp
