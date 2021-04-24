// Exported by Exporter.exe

// Included from Matrix_Rectangle.cpp
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
template <typename T> __attribute__((target("bmi"))) inline T gcd(T a, T b) {
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

template <typename T> inline int Digit_Sum(T a) {
	int ans = 0;
	while (a) {
		ans += a % 10;
		a /= 10;
	}
	return ans;
}
template <typename T> inline int Num_Length(T a) {
	if (a == 0) return 1;
	int ans = 0;
	while (a /= 10) ans++;
	return ans;
}
// End of C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp

// Included from C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp
void _print(int x) {printf("%d", x);}
void _print(long long int x) {printf("%lld", x);}
void _print(double x) {printf("%lf", x);}
template <typename T> void _print(T x) {return x.out();}
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

// Included from C:\Users\ianli\Desktop\CP\template\Math\Mod_Int\Mod_Int.cpp
template <typename T1, typename T2> T1 Pow(T1 a, T2 b) {
	T1 ans(1);
	while (b) {
		if (b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

template <int kMod> struct Mod_Int {
	static constexpr int Mod() {return kMod;}

	int val;
	Mod_Int() : val(0) {}
	template <typename T> constexpr Mod_Int(const T &x) {val = x;}

	Mod_Int inv() const {return Pow(*this, kMod - 2);} 

	Mod_Int operator + (const Mod_Int &x) const {
		Mod_Int ans(val + x.val);
		if (ans.val >= kMod) ans.val -= kMod;
		return ans;
	}
	Mod_Int operator - (const Mod_Int &x) const {
		Mod_Int ans(val - x.val);
		if (ans.val < 0) ans.val += kMod;
		return ans;
	}
	Mod_Int operator * (const Mod_Int &x) const {return Mod_Int(1LL * val * x.val % kMod);}
	Mod_Int operator / (const Mod_Int &x) const {return *this * x.inv();}
	Mod_Int operator ^ (const Mod_Int &x) const {return Pow(*this, x.val);}
	Mod_Int operator << (const int &x) const {return ((1LL * val) << x) % kMod;}

	Mod_Int operator += (const Mod_Int &x) {return *this = *this + x;}
	Mod_Int operator -= (const Mod_Int &x) {return *this = *this - x;}
	Mod_Int operator *= (const Mod_Int &x) {return *this = *this * x;}
	Mod_Int operator /= (const Mod_Int &x) {return *this = *this / x;}
	Mod_Int operator ^= (const Mod_Int &x) {return *this = Pow(*this, x.val);}
	Mod_Int operator <<= (const int &x) {return *this = *this << x;}

	Mod_Int operator ++(int) {
		val++;
		if (val >= kMod) val -= kMod;
		return *this;
	}
	Mod_Int operator --(int) {
		val--;
		if (val < 0) val += kMod;
		return *this;
	}

	bool operator < (const Mod_Int &x) const {return val < x.val;}
	bool operator > (const Mod_Int &x) const {return val > x.val;}
	bool operator <= (const Mod_Int &x) const {return val <= x.val;}
	bool operator >= (const Mod_Int &x) const {return val >= x.val;}
	bool operator == (const Mod_Int &x) const {return val == x.val;}
	bool operator != (const Mod_Int &x) const {return val != x.val;}

	void out() const {printf("%d", val);}
};

using Mint = Mod_Int<kMod>;

namespace Factorial {
	Mint *f, *inf;
	bool preprocessed_factorial;
	void Pre_Factorial(const int &sz) {
		if (preprocessed_factorial) return ;
		preprocessed_factorial = true;
		f = new Mint[sz + 1];
		inf = new Mint[sz + 1];
		f[0] = f[1] = inf[0] = inf[1] = 1;
		for (int i = 2; i <= sz; i++) f[i] = f[i - 1] * i;
		inf[sz] = f[sz].inv();
		for (int i = sz; i > 2; i--) inf[i - 1] = inf[i] * i;
		return ;
	}
	inline Mint P(const int &n, const int &m) {return f[n] * inf[m];}
	inline Mint C(const int &n, const int &m) {return f[n] * inf[m] * inf[n - m];}
	inline Mint H(const int &n, const int &m) {return f[n + m - 1] * inf[m] * inf[n - 1];}
	inline Mint Catalan(const int &n) {return f[n << 1] * inf[n] * inf[n + 1];}
}

namespace Factorial_No_Inf {
	Mint *f;
	void Pre_Factorial(const int &sz) {
		f = new Mint[sz + 1];
		f[0] = f[1] = 1;
		for (int i = 2; i <= sz; i++) f[i] = f[i - 1] * i;
		return ;
	}
	inline Mint P(const int &n, const int &m) {return f[n] / f[m];}
	inline Mint C(const int &n, const int &m) {return f[n] / (f[m] * f[n - m]);}
	inline Mint H(const int &n, const int &m) {return f[n + m - 1] / (f[m] * f[n - 1]);}
	inline Mint Catalan(const int &n) {return f[n << 1] / (f[n] * f[n + 1]);}
}

namespace Inverse {
	using namespace Factorial;
	Mint *inv;
	void Pre_Inverse(const int &sz) {
		inv = new Mint[sz + 1];
		inv[1] = 1;
		Pre_Factorial(sz);
		for (int i = 1; i <= sz; i++) inv[i] = f[i - 1] * inf[i];
		return ;
	}
};
// End of C:\Users\ianli\Desktop\CP\template\Math\Mod_Int\Mod_Int.cpp

// Included from C:\Users\ianli\Desktop\CP\template\Math\Matrix\Matrix_Rectangle.cpp
namespace Matrix_Inner {
	template <typename T> T ABS(T x) {return x >= 0 ? x : -x;}
	bool IsZero(double x) {
		static constexpr double kEps = 1E-10;
		return ABS(x) <= kEps;
	}
	template <typename T> bool IsZero(T x) {return x == 0;}
}

template <typename T> class Matrix {
	private:
		T **_val;
		int _n, _m;

	public:
		Matrix() : _val(nullptr), _n(0), _m(0) {}
		Matrix(int n, int m) : _n(n), _m(m), _val(new T* [n]) {
			for (int i = 0; i < _n; i++) {
				_val[i] = new T [_m];
				memset(_val[i], 0, sizeof(T) * _m);
			}
		}
		Matrix(const Matrix &rhs) : _n(rhs.row_size()), _m(rhs.col_size()), _val(rhs._val) {}

		void clear() {
			for (int i = 0; i < _n; i++) delete [] _val[i];
			delete [] _val;
			_val = nullptr;
			_n = _m = 0;
			return ;
		}

		void resize(int n, int m) {
			clear();
			_n = n, _m = m;
			_val = new T* [_n];
			for (int i = 0; i < _n; i++) {
				_val[i] = new T [_m];
				memset(_val[i], 0, sizeof(T) * _m);
			}
			return ;
		}
		int row_size() const {return _n;}
		int col_size() const {return _m;}

		void copy(const Matrix &x) {
			clear();
			_n = x.row_size(), _m = x.col_size();
			_val = new T* [_n];
			for (int i = 0; i < _n; i++) {
				_val[i] = new T [_m];
				memcpy(_val[i], x[i], sizeof(T) * _m);
			}
			return ;
		}

		T* operator [](int x) {return _val[x];}
		const T* operator [](int x) const {return _val[x];}

		Matrix operator + (const Matrix &x) const {
			Matrix ans(_n, _m);
			for (int i = 0; i < _n; i++) for (int j = 0; j < _m; j++) ans[i][j] = _val[i][j] + x[i][j];
			return ans;
		}
		Matrix operator - (const Matrix &x) const {
			Matrix ans(_n, _m);
			for (int i = 0; i < _n; i++) for (int j = 0; j < _m; j++) ans[i][j] = _val[i][j] - x[i][j];
			return ans;
		}
		Matrix operator * (const T &x) const {
			Matrix ans(_n, _m);
			for (int i = 0; i < _n; i++) for (int j = 0; j < _m; j++) ans[i][j] = _val[i][j] * x;
			return ans;
		} 
		Matrix operator * (const Matrix &x) const {
			static constexpr int kCacheSize = 8 * 1024 * 1024 * sizeof(bool);
			static constexpr int kT = (1 << (__lg(kCacheSize) >> 1)) / sizeof(T);
			assert(_m == x._n);
			int n = _n, m = _m, p = x._m;
			Matrix ans(n, p);
			for (int I = 0; I < n; I += kT) for (int J = 0; J < p; J += kT) for (int K = 0; K < m; K += kT) {
				int limi = min(I + kT, n), limj = min(J + kT, p), limk = min(K + kT, m);
				for (int i = I; i < limi; i++) for (int j = J; j < limj; j++) {
					T sum = 0;
					for (int k = K; k < limk; k++) sum += _val[i][k] * x[k][j];
					ans[i][j] += sum;
				}
			}
			return ans;
		} 
		Matrix operator / (const T &x) const {
			Matrix ans(_n, _m);
			for (int i = 0; i < _n; i++) for (int j = 0; j < _m; j++) ans[i][j] = _val[i][j] / x;
			return ans;
		}
		Matrix operator += (const Matrix &x) {return *this = *this + x;} 
		Matrix operator -= (const Matrix &x) {return *this = *this - x;} 
		Matrix operator *= (const T &x) {return *this = *this * x;} 
		Matrix operator *= (const Matrix &x) {return *this = *this * x;} 
		Matrix operator /= (const T &x) {return *this = *this / x;} 

		T det() const {
			assert(_n == _m);

			Matrix tmp;
			tmp.copy(*this);
			bool flip = false;

			for (int i = 0; i < _n; i++) {
				if (Matrix_Inner::IsZero(tmp[i][i])) {
					int id = -1;
					for (int j = i + 1; j < _n; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
						id = j;
						break;
					}
					if (id == -1) return 0;
					for (int j = i; j < _n; j++) swap(tmp[i][j], tmp[id][j]);
					flip = !flip;
				}

				for (int j = i + 1; j < _n; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
					T freq(tmp[j][i] / tmp[i][i]);
					for (int k = i; k < _n; k++) tmp[j][k] -= freq * tmp[i][k];
				}
			}

			T ans = (flip ? -1 : 1);
			for (int i = 0; i < _n; i++) ans *= tmp[i][i];
			tmp.clear();
			return (ans + 0 - 0);
		}

		T det_piviting() const {
			// !!! not finished
			Matrix tmp;
			tmp.copy(*this);
			bool flip = false;

			for (int i = 0; i < _n; i++) {
				if (Matrix_Inner::IsZero(tmp[i][i])) {
					int id = -1;
					for (int j = i + 1; j < _n; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
						id = j;
						break;
					}
					if (id == -1) return 0;
					for (int j = i; j < _n; j++) swap(tmp[i][j], tmp[id][j]);
					flip = !flip;
				}

				for (int j = i + 1; j < _n; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
					T freq(tmp[j][i] / tmp[i][i]);
					for (int k = i; k < _n; k++) tmp[j][k] -= freq * tmp[i][k];
				}
			}

			T ans = (flip ? -1 : 1);
			for (int i = 0; i < _n; i++) ans *= tmp[i][i];
			tmp.clear();
			return ans;
		}

		void out() const {
			for (int i = 0; i < _n; i++, printf("\n")) for (int j = 0; j < _m; j++) printf("%5d", _val[i][j]);
			return ;
		}
};

template <typename T1, typename T2> Matrix<T1> Pow(Matrix<T1> A, T2 b) {
	assert(A.row_size() == A.col_size());
	int n = A.row_size();
	Matrix<T1> ans(n, n);
	for (int i = 0; i < n; i++) ans[i][i] = 1;
	for (; b; b >>= 1, A *= A) if (b & 1) ans *= A;
	return ans;
}

// End of C:\Users\ianli\Desktop\CP\template\Math\Matrix\Matrix_Rectangle.cpp

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

	A.resize(cur, cur);

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
// End of Matrix_Rectangle.cpp
