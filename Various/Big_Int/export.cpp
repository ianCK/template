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
	#define Debug(...) ;
	#define Debug_Array(n,x) ;
	#define NL ;
#else
	#define Debug(...) {printf("(%s) = ", (#__VA_ARGS__)), _print(__VA_ARGS__), printf("\n");}
	#define Debug_Array(n,x) {for (int i = 1; i <= n; i++) {printf("%s", (#x)); printf("[%d] = ", i); _print(x[i]); printf("\n");}}
	#define NL {printf("\n");}
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


// Included from C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp
bool Fast_IO_activated = false;
bool IOS_activated = false;
// --- Get ---
static inline char Get_Raw_Char() {
	static bool pre = Fast_IO_activated = true;
	static char buf[1 << 16], *p = buf, *end = buf;
	if (p == end) {
		if ((end = buf + fread(buf, 1, 1 << 16, stdin)) == buf) return '\0';
		p = buf;
	}
	return *p++;
}

// --- Read ---
template <typename T> static inline void Read_P(T &n) {
	static_assert(is_integral<T>::value, "Read_P requires an integral type");
	char c;
	while (!isdigit(c = Get_Raw_Char())) ;
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> static inline void Read(T &n) {
	static_assert(is_integral<T>::value, "Read requires an integral type");
	char c;
	bool neg = false;
	while (!isdigit(c = Get_Raw_Char())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isdigit(c = Get_Raw_Char())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> static inline void Read_Digit(T &n) {
	static_assert(is_integral<T>::value, "Read_Digit requires an integral type");
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
inline void IOS() {
	IOS_activated = true;
	ios::sync_with_stdio(false); cin.tie(0);
}
inline void Freopen(const char *in, const char *out) {freopen(in, "r", stdin); freopen(out, "w", stdout); return ;}

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
template <typename T> inline void Concatanate(vector<T> &a, vector<T> &b, vector<T> &c) {
	int a_size = int(a.size()), b_size = int(b.size());
	c.resize(a_size + b_size);
	for (int i = 0; i < a_size; i++) c[i] = a[i];
	for (int i = 0; i < b_size; i++) c[i + a_size] = b[i];
	return ;
}

template <typename T> inline void Discrete(vector<T> &v) {sort(v); v.resize(unique(v.begin(), v.end()) - v.begin()); return ;}

template <typename T> using PQ = priority_queue<T>;
template <typename T> using PQ_R = priority_queue<T, vector<T>, greater<T>>;

template <typename T> inline T ABS(T n) {return n >= 0 ? n : -n;}
template <typename T> __attribute__((target("bmi"))) inline T gcd(T a, T b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (a == 0 || b == 0) return a + b;
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
	return a << min(n, m);
}
template <typename T> inline T lcm(T a, T b) {return a * b / gcd(a, b);}
template <typename T, typename... Targs> inline T gcd(T a, T b, T c, Targs... args) {return gcd(a, gcd(b, c, args...));}
template <typename T, typename... Targs> inline T lcm(T a, T b, T c, Targs... args) {return lcm(a, lcm(b, c, args...));}
template <typename T, typename... Targs> inline T min(T a, T b, T c, Targs... args) {return min(a, min(b, c, args...));}
template <typename T, typename... Targs> inline T max(T a, T b, T c, Targs... args) {return max(a, max(b, c, args...));}
template <typename T, typename... Targs> inline void chmin(T &a, T b, Targs... args) {a = min(a, b, args...); return ;}
template <typename T, typename... Targs> inline void chmax(T &a, T b, Targs... args) {a = max(a, b, args...); return ;}

vector<int> Primes(int n) {
	if (n == 1) return {};
	// 2 ~ n
	vector<int> primes;
	vector<bool> isPrime(n + 1, true);

	primes.reserve(n / __lg(n));

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) primes.push_back(i);
		for (int j : primes) {
			if (i * j > n) break;
			isPrime[i * j] = false;
			if (i % j == 0) break;
		}
	}
	return primes;
}

vector<int> factors(int x) {
	vector<int> ans;
	for (int i = 1; i * i <= x; i++) if (x % i == 0) ans.PB(i);

	int id = int(ans.size()) - 1;
	if (ans[id] * ans[id] == x) id--;
	for (int i = id; i >= 0; i--) ans.PB(x / ans[i]);

	return ans;
}

int mex(vector<int> vec) {
	int n = int(vec.size());
	vector<bool> have(n, false);
	for (int i : vec) if (i < n) have[i] = true;
	for (int i = 0; i < n; i++) if (!have[i]) return i;
	return n;
}

template <typename T> T SQ(T x) {return x * x;}

template <typename T> T Mdist(pair<T, T> lhs, pair<T, T> rhs) {return ABS(lhs.first - rhs.first) + ABS(lhs.second - rhs.second);}
template <typename T> T Dist2(pair<T, T> lhs, pair<T, T> rhs) {
	return SQ(lhs.F - rhs.F) + SQ(lhs.S - rhs.S);
}

template <typename T> T LUBound(T LB, T val, T UB) {return min(max(LB, val), UB);}

template <typename T, typename Comp> T Binary_Search(T L, T R, Comp f) {
	// L good R bad
	static_assert(is_integral<T>::value, "Binary_Search requires an integral type");
	while (R - L > 1) {
		T mid = (L + R) >> 1;
		if (f(mid)) L = mid;
		else R = mid;
	}
	return L;
}

template <typename Comp> double Binary_Search(double L, double R, Comp f, int n = 30) {
	for (int i = 1; i <= n; i++) {
		double mid = (L + R) / 2;
		if (f(mid)) L = mid;
		else R = mid;
	}
	return L;
}
// End of C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp

// Included from C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp
template <typename T> void _print(vector<T> v) ;
void _print(bool x) {printf("%d", x ? 1 : 0);}
void _print(char x) {printf("%c", x);}
void _print(short x) {printf("%hd", x);}
void _print(unsigned short x) {printf("%hu", x);}
void _print(int x) {printf("%d", x);}
void _print(unsigned int x) {printf("%u", x);}
void _print(long long int x) {printf("%lld", x);}
void _print(unsigned long long int x) {printf("%llu", x);}
void _print(float x) {printf("%f", x);}
void _print(double x) {printf("%lf", x);}
void _print(long double x) {printf("%Lf", x);}
template <typename T1, typename T2> void _print(pair<T1, T2> x) {printf("("); _print(x.first); printf(", "); _print(x.second); printf(")");}
template <typename T1, typename T2, typename T3> void _print(tuple<T1, T2, T3> x) {printf("("); _print(get<0>(x)); printf(", "); _print(get<1>(x)); printf(", "); _print(get<2>(x)); printf(")");}
template <typename T> void _print(vector<T> v) {
	if (v.empty()) printf(" empty");
	else {
		bool first = true;
		for (T i : v) {
			if (first) first = false;
			else printf(" ");
			_print(i);
		}
	}
}
template <typename T> void _print(set<T> s) {
	if (s.empty()) printf(" empty");
	else {
		bool first = true;
		for (T i : s) {
			if (first) first = false;
			else printf(" ");
			_print(i);
		}
	}
}
template <typename T> void _print(stack<T> s) {
	if (s.empty()) printf(" empty");
	else {
		_print(s.top()); s.pop();
		while (!s.empty()) {printf(" "); _print(s.top()); s.pop();}
	}
}
template <typename T> void _print(queue<T> q) {
	if (q.empty()) printf(" empty");
	else {
		_print(q.front()); q.pop();
		while (!q.empty()) {printf(" "); _print(q.front()); q.pop();}
	}
}
template <typename T> void _print(deque<T> dq) {
	if (dq.empty()) printf(" empty");
	else {
		_print(dq.front()); dq.pop_front();
		while (!dq.empty()) {printf(" "); _print(dq.front()); dq.pop_front();}
	}
}
template <typename T1, typename T2, typename T3> void _print(priority_queue<T1, T2, T3> pq) {
	if (pq.empty()) printf(" empty");
	else {
		_print(pq.top()); pq.pop();
		while (!pq.empty()) {printf(" "); _print(pq.top()); pq.pop();}
	}
}
template <int size> void _print(bitset<size> bs) {
	for (int i = 0; i < size; i++) printf("%d", bs[i] ? 1 : 0);
}
template <typename T1, typename T2> void _print(map<T1, T2> m) {
	if (m.empty()) printf(" empty");
	else {
		bool first = true;
		for (pair<T1, T2> i : m) {
			if (first) first = false;
			else printf(" ");
			_print(i);
		}
	}
}

template <typename T> void _print(T x) {return x.out();}
template <typename T, typename... Targs> void _print(T x, Targs... Fargs) {_print(x); printf(", "); _print(Fargs...);}
// End of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp

// Included from C:\Users\ianli\Desktop\CP\template\Various\Big_Int\Big_Int.cpp
struct Big_Int {
	private:
		static constexpr int kLen = 9;
		static constexpr int kMod = 1'000'000'000;
		bool _positive;
		vector<int> _val;

	public:
		Big_Int () {
			_positive = true;
			_val.push_back(0);
		}
		Big_Int(string s) {
			int diff;
			if (s[0] == '-') {
				_positive = false;
				diff = 1;
			}
			else {
				_positive = true;
				diff = 0;
			}

			int sz = int(s.size());
			int val_sz = (sz - diff + 8) / 9;

			_val.reserve(val_sz);

			int cur_id = sz - 1;

			while (cur_id - kLen + 1 >= diff) {
				cur_id -= kLen;
				_val.push_back(stoi(s.substr(cur_id + 1, kLen)));
			}

			if (cur_id >= diff) _val.push_back(stoi(s.substr(diff, cur_id - diff + 1)));
		}
		Big_Int (const Big_Int &x) {
			_positive = x._positive;
			_val = x._val;
		}

		Big_Int operator -() const {
			Big_Int ans(*this);
			ans._positive = !ans._positive;
			return ans;
		}
		Big_Int operator + (const Big_Int &x) const {
			Big_Int ans;
			int lhs_sz = int(_val.size()), rhs_sz = int(x._val.size());
			int lim = max(lhs_sz, rhs_sz) + 1;
			ans._val.resize(lim);

			if (_positive == x._positive) {
				ans._positive = _positive;
				for (int i = 0; i < lhs_sz; i++) ans._val[i] += _val[i];
				for (int i = 0; i < rhs_sz; i++) ans._val[i] += x._val[i];
				for (int i = 0, k = 0; i < lim; i++) {
					ans._val[i] += k;
					if (ans._val[i] >= kMod) {
						ans._val[i] -= kMod;
						k = 1;
					}
					else k = 0;
				}
			}
			else {
				ans._positive = _positive;
				for (int i = 0; i < lhs_sz; i++) ans._val[i] += _val[i];
				for (int i = 0; i < rhs_sz; i++) ans._val[i] -= x._val[i];
				int k = 0;
				for (int i = 0; i < lim; i++) {
					ans._val[i] += k;
					if (ans._val[i] < 0) {
						ans._val[i] += kMod;
						k = -1;
					}
					else if (ans._val[i] >= kMod) {
						ans._val[i] -= kMod;
						k = 1;
					}
					else k = 0;
				}

				// k = 0 or -1 
				if (k < 0) {
					ans._positive = !ans._positive;
					k = 0;
					for (int i = 0; i < lim; i++) {
						ans._val[i] = -ans._val[i] + k;
						if (ans._val[i] < 0) {
							ans._val[i] += kMod;
							k = -1;
						}
						else if (ans._val[i] >= kMod) {
							ans._val[i] -= kMod;
							k = 1;
						}
						else k = 0;
					}
				}
			}

			while (int(ans._val.size()) > 1 && ans._val.back() == 0) ans._val.pop_back();
			if (ans._val.back() == 0) ans._positive = true;
			return ans;
		}
		Big_Int operator - (const Big_Int &x) const {return *this + (-x);}

		Big_Int operator * (const Big_Int &x) const {
			Big_Int ans;
			int lhs_sz = int(_val.size()), rhs_sz = int(x._val.size());
			int lim = lhs_sz + rhs_sz + 2;
			ans._val.resize(lim);
			ans._positive = !(_positive ^ x._positive);

			for (int i = 0; i < lhs_sz; i++) for (int j = 0; j < rhs_sz; j++) {
				long long int tmp = 1LL * _val[i] * x._val[j] + ans._val[i + j];
				ans._val[i + j] = tmp % kMod;
				ans._val[i + j + 1] += tmp / kMod;
				if (ans._val[i + j + 1] >= kMod) {
					ans._val[i + j + 1] -= kMod;
					ans._val[i + j + 2]++;
				}
			}

			for (int i = 0, k = 0; i < lim; i++) {
				ans._val[i] += k;
				if (ans._val[i] >= kMod) {
					ans._val[i] -= kMod;
					k = 1;
				}
				else k = 0;
			}

			while (int(ans._val.size()) > 1 && ans._val.back() == 0) ans._val.pop_back();
			if (ans._val.back() == 0) ans._positive = true;
			return ans;
		}
		Big_Int operator / (const Big_Int &x) const {return Big_Int();}
		Big_Int operator % (const Big_Int &x) const {return Big_Int();}
		Big_Int operator += (const Big_Int &x) {return *this = *this + x;}
		Big_Int operator -= (const Big_Int &x) {return *this = *this - x;}
		Big_Int operator *= (const Big_Int &x) {return *this = *this * x;}
		Big_Int operator /= (const Big_Int &x) {return *this = *this / x;}
		Big_Int operator %= (const Big_Int &x) {return *this = *this % x;}
		Big_Int operator ++(int) {return Big_Int();}
		Big_Int operator --(int) {return Big_Int();}

		bool operator < (const Big_Int &x) const {
			if (_positive != x._positive) return x._positive; // equivilant with !_positive
			else {
				int lhs_sz = int(_val.size()), rhs_sz = int(x._val.size());
				if (_positive) {
					if (lhs_sz != rhs_sz) return lhs_sz < rhs_sz;
					for (int i = lhs_sz - 1; i >= 0; i--) if (_val[i] != x._val[i]) return _val[i] < x._val[i];
				}
				else {
					if (lhs_sz != rhs_sz) return lhs_sz > rhs_sz;
					for (int i = lhs_sz - 1; i >= 0; i--) if (_val[i] != x._val[i]) return _val[i] > x._val[i];
				}
				return false;
			}
		}
		bool operator <= (const Big_Int &x) const {
			if (_positive != x._positive) return x._positive; // equivilant with !_positive
			else {
				int lhs_sz = int(_val.size()), rhs_sz = int(x._val.size());
				if (_positive) {
					if (lhs_sz != rhs_sz) return lhs_sz < rhs_sz;
					for (int i = lhs_sz - 1; i >= 0; i--) if (_val[i] != x._val[i]) return _val[i] < x._val[i];
				}
				else {
					if (lhs_sz != rhs_sz) return lhs_sz > rhs_sz;
					for (int i = lhs_sz - 1; i >= 0; i--) if (_val[i] != x._val[i]) return _val[i] > x._val[i];
				}
				return true;
			}
		}
		bool operator > (const Big_Int &x) const {return !(*this <= x);}
		bool operator >= (const Big_Int &x) const {return !(*this < x);}
		bool operator == (const Big_Int &x) const {return _positive == x._positive && _val == x._val;}
		bool operator != (const Big_Int &x) const {return !(*this == x);}

		void in() {
			if (Fast_IO_activated) {
				char c;
				while (!isdigit(c = Get_Raw_Char()) && c != '-') ;
				string s(1, c);
				while (isdigit(c = Get_Raw_Char())) s += c;
				*this = Big_Int(s);
			}
			else {
				string s; cin >> s;
				*this = Big_Int(s);
			}
			return ;
		}
		void out() {
			int sz = int(_val.size());

			if (!_positive) printf("-");
			printf("%s", to_string(_val[sz - 1]).c_str());
			for (int i = sz - 2; i >= 0; i--) {
				string tmp = to_string(_val[i]);
				int tmp_sz = int(tmp.size());
				for (int j = tmp_sz; j < kLen; j++) printf("0");
				printf("%s", tmp.c_str());
			}
			return ;
		}
};
// End of C:\Users\ianli\Desktop\CP\template\Various\Big_Int\Big_Int.cpp

int main() {
	Big_Int a, b;
	a.in();
	b.in();

	(a + b).out();
	printf("\n");
}
// End of test.cpp
