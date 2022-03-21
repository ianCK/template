// Merged by FileMerger.exe
// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\ARC137D.cpp --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.h --- 

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define MTP make_tuple
#ifdef ONLINE_JUDGE
	#define Debug(...) ;
	#define Debug_Array(n,x) ;
	#define Debugln_Array(n,x) ;
	#define NL ;
#else
	#define Debug(...) {printf("(%s) = ",(#__VA_ARGS__)),_print(__VA_ARGS__),printf("\n");}
	#define Debug_Array(n,x) {printf("%s :",(#x));for(int i=1;i<=n;i++)printf(" "),_print(x[i]);printf("\n");}
	#define Debugln_Array(n,x) {for(int i=1;i<=n;i++){printf("%s",(#x));printf("[%d] = ", i);_print(x[i]);printf("\n");}}
	#define NL {printf("\n");}
#endif

typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long int ull;
// --- End of C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.cpp --- 

constexpr int kN = 1 << 20;
// constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;
// constexpr int dx[4] = {0, 0, 1, -1};
// constexpr int dy[4] = {1, -1, 0, 0};
// constexpr int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
// constexpr int dy[8] = {1, -1, 1, -1, -1, 1, 0, 0};

// --- Start of C:\Users\ianli\Desktop\CP\template\Various\FastIO\FastIO.h --- 

// R -> Read
// D -> digit (no check for neg, only one digit)
// P -> positive (no check for neg)
// S -> string
// L -> loop
// W -> write

class FastIO {
	private:
		static constexpr int bufferSize = 1 << 16;
		static constexpr int bufferMod = bufferSize - 1; // (use & to mod)

		FILE *input, *output;

		char inputBuffer[bufferSize];
		char outputBuffer[bufferSize];

		int inputPointer;
		int outputPointer;

		char getRawChar() {
			if (inputPointer == bufferSize) {
				fread(inputBuffer, 1, bufferSize, input);
				inputPointer = 0;
			}
			return inputBuffer[inputPointer++];
		}

		static bool isDigit(char c) {return '0' <= c and c <= '9';}

		void outputAll() {
			fwrite(outputBuffer, 1, bufferSize, output);
			return ;
		}
		void outputRemain() {
			fwrite(outputBuffer, 1, outputPointer, output);
			return ;
		}

		template <typename T> void RLi(int i, T *a) {return R(a[i]);}
		template <typename T, typename... Targs> void RLi(int i, T *a, Targs*... Fargs) {R(a[i]); return RLi(i, Fargs...);}

		template <typename T> void RLPi(int i, T *a) {return RP(a[i]);}
		template <typename T, typename... Targs> void RLPi(int i, T *a, Targs*... Fargs) {RP(a[i]); return RLPi(i, Fargs...);}

		template <typename T> void RLDi(int i, T *a) {return RD(a[i]);}
		template <typename T, typename... Targs> void RLDi(int i, T *a, Targs*... Fargs) {RD(a[i]); return RLDi(i, Fargs...);}

		void RLSi(int i, string *a) {return RS(a[i]);}
		template <typename... Targs> void RLSi(int i, string *a, Targs*... Fargs) {RS(a[i]); return RLSi(i, Fargs...);}

		void WC(char c) {
			if (outputPointer == bufferSize) {
				outputAll();
				outputPointer = 0;
			}
			outputBuffer[outputPointer++] = c;
			return ;
		}

	public:
		FastIO() : input(stdin), output(stdout), inputPointer(0), outputPointer(0) {
			fread(inputBuffer, 1, bufferSize, input);
		}
		FastIO(string inputPath, string outputPath) : 
			input(fopen(inputPath.c_str(), "r")), 
			output(fopen(outputPath.c_str(), "w")),
			inputPointer(0),
			outputPointer(0) {
				fread(inputBuffer, 1, bufferSize, input);
			}

		~FastIO() {
			outputRemain();
			fclose(input);
			fclose(output);
		}

		template <typename T> void R (T& n) {
			static_assert(is_integral<T>::value, "R requires an integral type");
			char c;
			bool neg = false;
			while (!isDigit(c = getRawChar())) if (c == '-') neg = true;
			n = int(c - '0');
			while (isDigit(c = getRawChar())) n = n * 10 + int(c - '0');
			if (neg) n = -n;
			return ;
		}
		template <typename T> void RP(T& n) {
			static_assert(is_integral<T>::value, "RP requires an integral type");
			char c;
			while (!isDigit(c = getRawChar()));
			n = int(c - '0');
			while (isDigit(c = getRawChar())) n = n * 10 + int(c - '0');
			return ;
		}
		template <typename T> void RD(T& n) {
			static_assert(is_integral<T>::value, "RD requires an integral type");
			char c;
			while (!isDigit(c = getRawChar())) ;
			n = int(c - '0');
			return ;
		}
		void RS(string& s) {
			// Can optimize?
			s.clear();
			char c = getRawChar();
			while (c == ' ' or c == '\n') c = getRawChar();
			while (c != ' ' and c != '\n') {
				s += c;
				c = getRawChar();
			}
			return ;
		}

		template <typename T, typename... Targs> void R (T &n, Targs&... Fargs) {R (n); return R (Fargs...);}
		template <typename T, typename... Targs> void RD(T &n, Targs&... Fargs) {RD(n); return RD(Fargs...);}
		template <typename T, typename... Targs> void RP(T &n, Targs&... Fargs) {RP(n); return RP(Fargs...);}
		template <typename... Targs> void RS(string &s, Targs&... Fargs) {RS(s); return RS(Fargs...);}

		template <typename... Targs> void RL(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) RLi(i, Fargs...);}
		template <typename... Targs> void RL0(int n, Targs*... Fargs) {for (int i = 0; i < n; i++) RLi(i, Fargs...);}

		template <typename... Targs> void RLP(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) RLPi(i, Fargs...);}
		template <typename... Targs> void RLP0(int n, Targs*... Fargs) {for (int i = 0; i < n; i++) RLPi(i, Fargs...);}

		template <typename... Targs> void RLD(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) RLDi(i, Fargs...);}
		template <typename... Targs> void RLD0(int n, Targs*... Fargs) {for (int i = 0; i < n; i++) RLDi(i, Fargs...);}

		template <typename... Targs> void RLS(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) RLSi(i, Fargs...);}
		template <typename... Targs> void RLS0(int n, Targs*... Fargs) {for (int i = 0; i < n; i++) RLSi(i, Fargs...);}

		// --- Write ---

		template <typename T> void W(const T& n) {
			static_assert(is_integral<T>::value, "W requires an integral type");
			if (n < 0) WC('-');
			return WP(-n);
		}
		template <typename T> void WP(const T& n) {
			static_assert(is_integral<T>::value, "WP requires an integral type");

			if (n == 0) return WC('0');

			T tmp = n;

			static char buffer[40];

			int pointer = 0;
			while (tmp) {
				buffer[pointer++] = char(tmp % 10 + '0');
				tmp /= 10;
			}

			for (int i = pointer - 1; i >= 0; i--) WC(buffer[i]);

			return ;
		}
		template <typename T> void WD(const T& n) {
			static_assert(is_integral<T>::value, "WD requires an integral type");
			return WC(char(n + '0'));
		}
		void WS(const string& s) {for (char c : s) WC(c); return ;}
		void WSpace() {return WC(' ');}
		void WLine() {return WC('\n');}
};
// --- End of C:\Users\ianli\Desktop\CP\template\Various\FastIO\FastIO.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\FastIO\FastIO.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\FastIO\FastIO.cpp --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp --- 
template <typename T, typename T1> void make_vector_inner(vector<T>& vec, T1 c) {return vec.push_back(T(c));}
template <typename T, typename T1, typename... Targs> void make_vector_inner(vector<T> &vec, T1 c, Targs... targs) {
	vec.push_back(T(c));
	return make_vector_inner(vec, targs...);
}
template <typename T, typename... Targs> vector<T> make_vector(Targs... targs) {
	vector<T> vec;
	make_vector_inner(vec, targs...);
	return vec;
}

template <typename T> inline void sort(vector<T> &v) {return sort(v.begin(), v.end());}
template <typename T> inline void sort_r(vector<T> &v) {return sort(v.begin(), v.end(), greater<T>());}
inline void sort(string &s) {return sort(s.begin(), s.end());}
inline void sort_r(string &s) {return sort(s.begin(), s.end(), greater<char>());}

template <typename T> inline void reverse(vector<T> &v) {return reverse(v.begin(), v.end());}
inline void reverse(string &s) {return reverse(s.begin(), s.end());}

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
template <typename T> inline void Append(vector<T> &lhs, vector<T> rhs) {
	int lsz = int(lhs.size()), rsz = int(rhs.size());
	lhs.reserve(lsz + rsz);
	for (int i = 0; i < rsz; i++) lhs.push_back(rhs[i]);
	return ;
}

template <typename T> inline void Erase(vector<T> &vec, T x) {
	int sz = int(vec.size());
	for (int i = 0; i < sz; i++) if (vec[i] == x) {
		swap(vec[i], vec.back());
		vec.pop_back();
		break;
	}
	return ;
}

template <typename T> inline void Discrete(vector<T> &v) {sort(v); v.resize(unique(v.begin(), v.end()) - v.begin()); return ;}
template <typename T> inline int Discrete_Id(vector<T> &v, T x) {return lower_bound(v.begin(), v.end(), x) - v.begin();}

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
template <typename T> inline T lcm(T a, T b) {return a * (b / gcd(a, b));}
template <typename T, typename... Targs> inline T gcd(T a, T b, T c, Targs... args) {return gcd(a, gcd(b, c, args...));}
template <typename T, typename... Targs> inline T lcm(T a, T b, T c, Targs... args) {return lcm(a, lcm(b, c, args...));}
template <typename T, typename... Targs> inline T min(T a, T b, T c, Targs... args) {return min(a, min(b, c, args...));}
template <typename T, typename... Targs> inline T max(T a, T b, T c, Targs... args) {return max(a, max(b, c, args...));}
template <typename T, typename... Targs> inline void chmin(T &a, T b, Targs... args) {a = min(a, b, args...); return ;}
template <typename T, typename... Targs> inline void chmax(T &a, T b, Targs... args) {a = max(a, b, args...); return ;}

vector<int> Primes(int n) {
	if (n <= 1) return {};
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

template <typename T> vector<T> factors(T x) {
	// maybe use factorize would be faster?
	vector<T> ans;
	for (T i = 1; i * i <= x; i++) if (x % i == 0) ans.push_back(i);

	int id = int(ans.size()) - 1;
	if (ans[id] * ans[id] == x) id--;
	for (int i = id; i >= 0; i--) ans.push_back(x / ans[i]);

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

// Euclidean distance
template <typename T> T Dist2(pair<T, T> lhs, pair<T, T> rhs) {return SQ(lhs.F - rhs.F) + SQ(lhs.S - rhs.S);}
template <typename T> T Dist2(T x1, T y1, T x2, T y2) {return SQ(x1 - x2) + SQ(y1 - y2);}

// Manhattan distance
template <typename T> T Mdist(pair<T, T> lhs, pair<T, T> rhs) {return ABS(lhs.first - rhs.first) + ABS(lhs.second - rhs.second);}
template <typename T> T Mdist(T x1, T y1, T x2, T y2) {return ABS(x1 - x2) + ABS(y1 - y2);}

template <typename T> bool Adj(pair<T, T> lhs, pair<T, T> rhs) {return Mdist(lhs, rhs) == 1;}

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

template <typename Comp> double Binary_Search(double L, double R, Comp f, int loop = 30) {
	for (int i = 1; i <= loop; i++) {
		double mid = (L + R) / 2;
		if (f(mid)) L = mid;
		else R = mid;
	}
	return L;
}

template <typename T> T nearest_dist(set<T> &se, T val) {
	static constexpr T kInf = numeric_limits<T>::max() / 2 - 10;

	if (se.empty()) return kInf;
	else if (val <= *se.begin()) return *se.begin() - val;
	else if (val >= *prev(se.end())) return val - *prev(se.end());
	else {
		auto u = se.lower_bound(val);
		auto v = prev(u);
		return min(*u - val, val - *v);
	}
}

template <typename T> T nearest_elem(set<T> &se, T val) {
	static constexpr T kInf = numeric_limits<T>::max() / 2 - 10;

	if (se.empty()) return kInf;
	else if (val <= *se.begin()) return *se.begin();
	else if (val >= *prev(se.end())) return *prev(se.end());
	else {
		auto u = se.lower_bound(val);
		auto v = prev(u);

		if (*u - val > val - *v) return *v;
		else return *u;
	}
}

namespace MR32 {
	using ull = unsigned long long int;
	using uint = unsigned int;
	ull PowMod(ull a, ull b, ull kMod) {
		ull ans = 1;
		for (; b; b >>= 1, a = a * a % kMod) if (b & 1) ans = ans * a % kMod;
		return ans;
	}

	bool IsPrime(uint x) {
		static constexpr bool low[8] = {false, false, true, true, false, true, false, true};
		static constexpr uint as = 3, a[3] = {2, 7, 61};
		if (x < 8) return low[x];

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
			if (!ok) return false;
		}
		return true;
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
		return ans;
	}

	bool IsPrime(ull x) {
		static constexpr bool low[8] = {false, false, true, true, false, true, false, true};
		static constexpr uint as = 7, a[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
		if (x < 8) return low[x];
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
			if (!ok) return false;
		}
		return true;
	}
}
#endif

bool IsPrime(unsigned long long int x) {
#ifdef __SIZEOF_INT128__
	if ((x >> 32) == 0) return MR32::IsPrime(x);
	else return MR64::IsPrime(x);
#endif
	return MR32::IsPrime(x);
}

#ifdef __SIZEOF_INT128__
uint64_t PollardRho(uint64_t x) {
	static mt19937 rng;
	if (!(x & 1)) return 2;
	if (IsPrime(x)) return x;
  int64_t a = rng() % (x - 2) + 2, b = a;
  uint64_t c = rng() % (x - 1) + 1, d = 1;
  while (d == 1) {
    a = (__int128(a) * a + c) % x;
    b = (__int128(b) * b + c) % x;
    b = (__int128(b) * b + c) % x;
    d = gcd(uint64_t(abs(a - b)), x);
    if (d == x) return PollardRho(x);
  }
  return d;
}

template <typename T> vector<T> factorize(T x) {
	if (x <= 1) return vector<T>();
	T p = PollardRho(x);
	if (p == x) return vector<T>(1, x);
	vector<T> ans, lhs = factorize(p), rhs = factorize(x / p);
	Merge(lhs, rhs, ans);
	return ans;
}
#endif

// vec must be sorted
template <typename T> vector<pair<T, int>> Compress(vector<T> vec) {
	if (vec.empty()) return {};

	vector<pair<T, int>> ans;
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
	return ans;
}

template <typename T> int Divisors(T x) {
	vector<pair<T, int>> fac = Compress(factorize(x));

	int ans = 1;
	for (pair<T, int> i : fac) ans *= i.second + 1;

	return ans;
}

template <typename T> T phi(T x) {
	vector<pair<T, int>> fac = Compress(factorize(x));

	T ans = 1;
	for (pair<T, int> i : fac) {
		ans *= i.first - 1;
		for (int j = 1; j < i.second; j++) ans *= i.first;
	}

	return ans;
}

template <typename T> vector<pair<T, T>> BitDecomposition(T l, T r) {
	vector<pair<T, T>> lhs, rhs;
	while (l + (l & -l) - 1 <= r) {
		lhs.push_back(make_pair(l, l + (l & -l) - 1));
		l += (l & -l);
	}

	while (r - ((r + 1) & -(r + 1)) + 1 >= l) {
		rhs.push_back(make_pair(r - ((r + 1) & -(r + 1)) + 1, r));
		r -= (r + 1) & -(r + 1);
	}

	reverse(rhs);
	for (pair<ll, ll> i : rhs) lhs.push_back(i);
	return lhs;
}
// --- End of C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp --- 
template <typename T> void _print(vector<T> v) ;
void _print(bool x) {printf("%s", x ? "True" : "False");}
void _print(char x) {printf("%c", x);}
void _print(short x) {printf("%hd", x);}
void _print(unsigned short x) {printf("%hu", x);}
void _print(int x) {printf("%d", x);}
void _print(unsigned int x) {printf("%u", x);}
void _print(long int x) {printf("%ld", x);}
void _print(unsigned long int x) {printf("%lu", x);}
void _print(long long int x) {printf("%lld", x);}
void _print(unsigned long long int x) {printf("%llu", x);}
void _print(float x) {printf("%f", x);}
void _print(double x) {printf("%lf", x);}
void _print(long double x) {printf("%Lf", x);}
void _print(const char* c) {int n = strlen(c); for (int i = 0; i < n; i++) printf("%c", c[i]);}
void _print(string s) {for (char c : s) printf("%c", c);}
template <size_t _size> void _print(bitset<_size> bs) {for (int i = 0; i < _size; i++) printf("%d", bs[i] ? 1 : 0);}
#ifdef __SIZEOF_INT128__
void _print(__int128 x) {
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
void _print(unsigned __int128 x) {
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
#endif
template <typename T1, typename T2> void _print(pair<T1, T2> x) {printf("("); _print(x.first); printf(", "); _print(x.second); printf(")");}
template <typename T1, typename T2, typename T3> void _print(tuple<T1, T2, T3> x) {printf("("); _print(get<0>(x)); printf(", "); _print(get<1>(x)); printf(", "); _print(get<2>(x)); printf(")");}
template <typename T1, typename T2, typename T3, typename T4> void _print(tuple<T1, T2, T3, T4> x) {printf("("); _print(get<0>(x)); printf(", "); _print(get<1>(x)); printf(", "); _print(get<2>(x)); printf(", "); _print(get<3>(x)); printf(")");}
template <typename T1, typename T2, typename T3, typename T4, typename T5> void _print(tuple<T1, T2, T3, T4, T5> x) {printf("("); _print(get<0>(x)); printf(", "); _print(get<1>(x)); printf(", "); _print(get<2>(x)); printf(", "); _print(get<3>(x)); printf(", "); _print(get<4>(x)); printf(")");}
template <typename T> void _print(vector<T> v) {
	if (v.empty()) printf(" empty");
	else {
		bool first = true;
		for (T i : v) {
			if (first) first = false;
			else printf(", ");
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
			else printf(", ");
			_print(i);
		}
	}
}
template <typename T> void _print(stack<T> s) {
	if (s.empty()) printf(" empty");
	else {
		_print(s.top()); s.pop();
		while (!s.empty()) {printf(", "); _print(s.top()); s.pop();}
	}
}
template <typename T> void _print(queue<T> q) {
	if (q.empty()) printf(" empty");
	else {
		_print(q.front()); q.pop();
		while (!q.empty()) {printf(", "); _print(q.front()); q.pop();}
	}
}
template <typename T> void _print(deque<T> dq) {
	if (dq.empty()) printf(" empty");
	else {
		_print(dq.front()); dq.pop_front();
		while (!dq.empty()) {printf(", "); _print(dq.front()); dq.pop_front();}
	}
}
template <typename T1, typename T2, typename T3> void _print(priority_queue<T1, T2, T3> pq) {
	if (pq.empty()) printf(" empty");
	else {
		_print(pq.top()); pq.pop();
		while (!pq.empty()) {printf(", "); _print(pq.top()); pq.pop();}
	}
}
template <typename T1, typename T2> void _print(map<T1, T2> m) {
	if (m.empty()) printf(" empty");
	else {
		bool first = true;
		for (pair<T1, T2> i : m) {
			if (first) first = false;
			else printf(", ");
			_print(i);
		}
	}
}

template <typename T> void _print(T& x) {return x.out();}
template <typename T, typename... Targs> void _print(T x, Targs... Fargs) {_print(x); printf(", "); _print(Fargs...);}
// --- End of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp --- 

// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\All.h --- 

// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\Add.h --- 

// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\SOS.h --- 

template <typename T, T (*oper)(T, T)> void SOS(int tot, T* arr);

// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\SOS.ipp --- 

template <typename T, T (*oper)(T, T)> void SOS(int tot, T* arr) {
	int n = __lg(tot);
	for (int i = 1; i <= n; i++) {
		int w = tot >> i;
		for (int s = 0; s < w; s++) {
			int from = s << i;
			int to = (s + 1) << i;
			int half = 1 << (i - 1);

			for (int l = from, r = from | half; r < to; l++, r++) arr[r] = oper(arr[l], arr[r]);
		}
	}

	return ;
}
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\SOS.ipp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\SOS.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\SOS.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\SOS.cpp --- 

template <typename T> void SOSAdd(int tot, T* arr);

// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\Add.ipp --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\Operator\Operator.h --- 

template <typename T> T ADD(T lhs, T rhs);
template <typename T> T SUB(T lhs, T rhs);
template <typename T> T MUL(T lhs, T rhs);
template <typename T> T DIV(T lhs, T rhs);

template <typename T> T  OR(T lhs, T rhs);
template <typename T> T AND(T lhs, T rhs);
template <typename T> T XOR(T lhs, T rhs);

template <typename T> T MAX(T lhs, T rhs);
template <typename T> T MIN(T lhs, T rhs);

// --- Start of C:\Users\ianli\Desktop\CP\template\Various\Operator\Operator.ipp --- 
template <typename T> T ADD(T lhs, T rhs) { return lhs + rhs; }
template <typename T> T SUB(T lhs, T rhs) { return lhs - rhs; }
template <typename T> T MUL(T lhs, T rhs) { return lhs * rhs; }
template <typename T> T DIV(T lhs, T rhs) { return lhs / rhs; }

template <typename T> T  OR(T lhs, T rhs) { return lhs | rhs; }
template <typename T> T AND(T lhs, T rhs) { return lhs & rhs; }
template <typename T> T XOR(T lhs, T rhs) { return lhs ^ rhs; }

template <typename T> T MAX(T lhs, T rhs) { return lhs < rhs ? rhs : lhs; }
template <typename T> T MIN(T lhs, T rhs) { return lhs < rhs ? lhs : rhs; }
// --- End of C:\Users\ianli\Desktop\CP\template\Various\Operator\Operator.ipp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\Operator\Operator.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\Operator\Operator.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\Operator\Operator.cpp --- 

template <typename T> void SOSAdd(int tot, T* arr) { return SOS<T, ADD<T>>(tot, arr); }
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\Add.ipp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\Add.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\Add.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\Add.cpp --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\Xor.h --- 


template <typename T> void SOSXor(int tot, T* arr);

// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\Xor.ipp --- 

template <typename T> void SOSXor(int tot, T* arr) { return SOS<T, XOR<T>>(tot, arr); }

// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\Xor.ipp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\Xor.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\Xor.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\Xor.cpp --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\Mul.h --- 


template <typename T> void SOSMul(int tot, T* arr);

// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\Mul.ipp --- 

template <typename T> void SOSMul(int tot, T* arr) { return SOS<T, MUL<T>>(tot, arr); }
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\Mul.ipp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\Mul.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\Mul.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\Mul.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\All.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\DP\SOS\All.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\All.cpp --- 
// using Mint = Mod_Int<kMod>;

int a[kN];
int dp[kN];
int ans[kN];

int main() {
	FastIO IO;

	int n, m; IO.RP(n, m);
	IO.RLP(n, a);

	int tot = 1 << 20;

	for (int i = 0; i < n; i++) dp[i] = a[n - i];

	SOSXor(tot, dp);

	for (int i = 1; i <= m; i++) ans[i] = dp[tot - i];

	IO.WP(ans[1]);
	for (int i = 2; i <= m; i++) {
		IO.WSpace();
		IO.WP(ans[i]);
	}
	IO.WLine();
}
// --- End of C:\Users\ianli\Desktop\CP\template\DP\SOS\ARC137D.cpp --- 
