// Merged by FileMerger.exe
// --- Start of C:\Users\ianli\Desktop\CP\template\Applications\Minifier\test.cpp --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.h --- 

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define MTP make_tuple
#define Debug(...) ;
#define DebugArray(n,x) ;
#define DebugArray0(n,x) ;
#define DebugArrayLn(n,x) ;
#define DebugArray0Ln(n,x) ;
#define NL ;
typedef unsigned int ui;
typedef long long int ll;
typedef unsigned long long int ull;

template <int i> class isZero { public: static constexpr bool value = false; };
template <> class isZero<0> { public: static constexpr bool value = true; };

class falseType { public: static constexpr bool value = false; };
class trueType { public: static constexpr bool value = true; };

template <bool b = false> class boolType : public falseType {};
template <> class boolType<true> : public trueType {};
// --- End of C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.cpp --- 

constexpr int kN = int(1E5 + 10);
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

// --- Start of C:\Users\ianli\Desktop\CP\template\Various\FastIO\Input\Input.h --- 

class Input {
	public:
		Input();
		Input(FILE*  _file);
		Input(string path);

		template <typename T> void R (T& n);
		template <typename T> void RP(T& n);
		template <typename T> void RD(T& n);
		void RS(string& s);

		template <typename T, typename... Targs> void R (T& n, Targs&... Fargs);
		template <typename T, typename... Targs> void RP(T& n, Targs&... Fargs);
		template <typename T, typename... Targs> void RD(T& n, Targs&... Fargs);
		template <typename... Targs> void RS(string& s, Targs&... Fargs);

		template <typename... Targs> void RL  (int n, Targs*... Fargs);
		template <typename... Targs> void RL0 (int n, Targs*... Fargs);
		template <typename... Targs> void RLP (int n, Targs*... Fargs);
		template <typename... Targs> void RLP0(int n, Targs*... Fargs);
		template <typename... Targs> void RLD (int n, Targs*... Fargs);
		template <typename... Targs> void RLD0(int n, Targs*... Fargs);
		template <typename... Targs> void RLS (int n, Targs*... Fargs);
		template <typename... Targs> void RLS0(int n, Targs*... Fargs);

	private:
		static constexpr int bufferSize = 1 << 16;

		FILE* file;
		char buffer[bufferSize];
		int pointer;

		void read();
		char getRawChar();
		static bool isDigit(char c);

		template <typename T> void RLi(int i, T* a);
		template <typename T, typename... Targs> void RLi(int i, T* a, Targs*... Fargs);

		template <typename T> void RLPi(int i, T* a);
		template <typename T, typename... Targs> void RLPi(int i, T* a, Targs*... Fargs);

		template <typename T> void RLDi(int i, T* a);
		template <typename T, typename... Targs> void RLDi(int i, T* a, Targs*... Fargs);

		void RLSi(int i, string* a);
		template <typename... Targs> void RLSi(int i, string* a, Targs*... Fargs);
};

// --- Start of C:\Users\ianli\Desktop\CP\template\Various\FastIO\Input\Input.ipp --- 
Input::Input() : file(stdin) { read(); }
Input::Input(FILE*  _file) : file(_file) { read(); }
Input::Input(string path) : file(fopen(path.c_str(), "r")) { read(); }

template <typename T> void Input::R (T& n) {
	static_assert(is_integral<T>::value, "R requires an integral type");
	char c;
	bool neg = false;
	while (!isDigit(c = getRawChar())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isDigit(c = getRawChar())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> void Input::RP(T& n) {
	static_assert(is_integral<T>::value, "RP requires an integral type");
	char c;
	while (!isDigit(c = getRawChar())) ;
	n = int(c - '0');
	while (isDigit(c = getRawChar())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> void Input::RD(T& n) {
	static_assert(is_integral<T>::value, "RD requires an integral type");
	char c;
	while (!isDigit(c = getRawChar())) ;
	n = int(c - '0');
	return ;
}

void Input::RS(string& s) {
	s.clear();
	char c = getRawChar();
	while (c == ' ' or c == '\n') c = getRawChar();
	while (c != ' ' and c != '\n') {
		s += c;
		c = getRawChar();
	}
	return ;
}

template <typename T, typename... Targs> void Input::R (T& n, Targs&... Fargs) { R(n); return R(Fargs...); }
template <typename T, typename... Targs> void Input::RP(T& n, Targs&... Fargs) { RP(n); return RP(Fargs...); }
template <typename T, typename... Targs> void Input::RD(T& n, Targs&... Fargs) { RD(n); return RD(Fargs...); }
template <typename... Targs> void Input::RS(string& s, Targs&... Fargs) { RS(s); return RS(Fargs...); }
template <typename... Targs> void Input::RL  (int n, Targs*... Fargs) { for (int i = 1; i <= n; i++) RLi(i, Fargs...); }
template <typename... Targs> void Input::RL0 (int n, Targs*... Fargs) { for (int i = 0; i < n; i++)  RLi(i, Fargs...); }
template <typename... Targs> void Input::RLP (int n, Targs*... Fargs) { for (int i = 1; i <= n; i++) RLPi(i, Fargs...); }
template <typename... Targs> void Input::RLP0(int n, Targs*... Fargs) { for (int i = 0; i < n; i++)  RLPi(i, Fargs...); }
template <typename... Targs> void Input::RLD (int n, Targs*... Fargs) { for (int i = 1; i <= n; i++) RLDi(i, Fargs...); }
template <typename... Targs> void Input::RLD0(int n, Targs*... Fargs) { for (int i = 0; i < n; i++)  RLDi(i, Fargs...); }
template <typename... Targs> void Input::RLS (int n, Targs*... Fargs) { for (int i = 1; i <= n; i++) RLSi(i, Fargs...); }
template <typename... Targs> void Input::RLS0(int n, Targs*... Fargs) { for (int i = 0; i < n; i++)  RLSi(i, Fargs...); }

// --- private ---

void Input::read() { fread(buffer, 1, bufferSize, file); pointer = 0; return ; }

char Input::getRawChar() {
	if (pointer == bufferSize) read();
	return buffer[pointer++];
}

bool Input::isDigit(char c) { return '0' <= c and c <= '9'; }

template <typename T> void Input::RLi(int i, T* a) { return R(a[i]); }
template <typename T, typename... Targs> void Input::RLi(int i, T* a, Targs*... Fargs) { R(a[i]); return RLi(i, Fargs...); }

template <typename T> void Input::RLPi(int i, T* a) { return RP(a[i]); }
template <typename T, typename... Targs> void Input::RLPi(int i, T* a, Targs*... Fargs) { RP(a[i]); return RLPi(i, Fargs...); }

template <typename T> void Input::RLDi(int i, T* a) { return RD(a[i]); }
template <typename T, typename... Targs> void Input::RLDi(int i, T* a, Targs*... Fargs) { RD(a[i]); return RLDi(i, Fargs...); }

void Input::RLSi(int i, string* a) { return RS(a[i]); }
template <typename... Targs> void Input::RLSi(int i, string* a, Targs*... Fargs) { RS(a[i]); return RSi(i, Fargs...); }
// --- End of C:\Users\ianli\Desktop\CP\template\Various\FastIO\Input\Input.ipp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\FastIO\Input\Input.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\FastIO\Input\Input.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\FastIO\Input\Input.cpp --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\FastIO\Output\Output.h --- 

class Output {
	public:
		Output();
		Output(FILE*  _file);
		Output(string path);
		~Output();

		template <typename T> void W (const T& n);
		template <typename T, typename... Targs> void W(const T& n, const Targs&... Fargs);
		template <typename T> void WP(const T& n);
		template <typename T> void WD(const T& n);
		void WC(char c);
		void WS(const string& s);
		void WS(const char* s);
		void WSpace();
		void WLine();

		void flush();

	private:
		static constexpr int bufferSize = 1 << 16;

		FILE* file;
		char buffer[bufferSize];
		int pointer;
};

// --- Start of C:\Users\ianli\Desktop\CP\template\Various\FastIO\Output\Output.ipp --- 
Output::Output() : file(stdout), pointer(0) {}
Output::Output(FILE*  _file) : file(_file), pointer(0) {}
Output::Output(string path) : file(fopen(path.c_str(), "w")), pointer(0) {}
Output::~Output() { flush(); }

template <> void Output::W<char>(const char& n) { return WC(n); }

template <> void Output::W<float>(const float& n) { 
	static char buffer[50];
	sprintf(buffer, "%f", n);
	return WS(buffer); 
}

template <> void Output::W<double>(const double& n) {
	static char buffer[50];
	sprintf(buffer, "%lf", n);
	return WS(buffer); 
}

template <> void Output::W<long double>(const long double& n) {
	static char buffer[50];
	sprintf(buffer, "%Lf", n);
	return WS(buffer); 
}

template <typename T> void Output::W (const T& n) {
	if (n < 0) {
		WC('-');
		WP(-n);
	}
	else WP(n);
	return ;
}

template <typename T, typename... Targs> void Output::W(const T& n, const Targs&... Fargs) { W(n); return W(Fargs...); }

template <typename T> void Output::WP(const T& n) {
	if (n == 0) return WC('0');

	T tmp(n);
	static char buffer[40];
	int pointer = 0;

	while (tmp) {
		buffer[pointer++] = char(tmp % 10 + '0');
		tmp /= 10;
	}

	for (int i = pointer - 1; i >= 0; i--) WC(buffer[i]); 
	return ;
}

template <typename T> void Output::WD(const T& n) { return WC(char(n + '0')); }

void Output::WC(char c) {
	if (pointer == bufferSize) flush();
	buffer[pointer++] = c;
	return ;
}

void Output::WS(const string& s) { for (char c : s) WC(c); return ; }
void Output::WS(const char* s) { int i = 0; while (s[i]) WC(s[i++]); return ; }
void Output::WSpace() { return WC(' '); }
void Output::WLine() { return WC('\n'); }

// --- private ---

void Output::flush() { fwrite(buffer, 1, pointer, file); pointer = 0; return ; }
// --- End of C:\Users\ianli\Desktop\CP\template\Various\FastIO\Output\Output.ipp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\FastIO\Output\Output.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\FastIO\Output\Output.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\FastIO\Output\Output.cpp --- 

// R -> Read
// D -> digit (no check for neg, only one digit)
// P -> positive (no check for neg)
// S -> string
// L -> loop
// W -> write

class FastIO {
	public:
		FastIO();
		FastIO(FILE*  inputFile, FILE*  outputFile);
		FastIO(string inputPath, FILE*  outputFile);
		FastIO(FILE*  inputFile, string outputPath);
		FastIO(string inputPath, string outputPath);

		// --- Input ---

		template <typename T> void R (T& n);
		template <typename T> void RP(T& n);
		template <typename T> void RD(T& n);
		void RS(string& s);

		template <typename T, typename... Targs> void R (T& n, Targs&... Fargs);
		template <typename T, typename... Targs> void RP(T& n, Targs&... Fargs);
		template <typename T, typename... Targs> void RD(T& n, Targs&... Fargs);
		template <typename... Targs> void RS(string& s, Targs&... Fargs);

		template <typename... Targs> void RL  (int n, Targs*... Fargs);
		template <typename... Targs> void RL0 (int n, Targs*... Fargs);
		template <typename... Targs> void RLP (int n, Targs*... Fargs);
		template <typename... Targs> void RLP0(int n, Targs*... Fargs);
		template <typename... Targs> void RLD (int n, Targs*... Fargs);
		template <typename... Targs> void RLD0(int n, Targs*... Fargs);
		template <typename... Targs> void RLS (int n, Targs*... Fargs);
		template <typename... Targs> void RLS0(int n, Targs*... Fargs);

		// --- Output ---

		template <typename T> void W (const T& n);
		template <typename T, typename... Targs> void W(const T& n, const Targs&... Fargs);
		template <typename T> void WP(const T& n);
		template <typename T> void WD(const T& n);
		void WC(char c);
		void WS(const string& s);
		void WS(const char* s);
		void WSpace();
		void WLine();

	private:
		Input input;
		Output output;
};

// --- Start of C:\Users\ianli\Desktop\CP\template\Various\FastIO\FastIO.ipp --- 
FastIO::FastIO() : input(stdin), output(stdout) {}
FastIO::FastIO(FILE*  inputFile, FILE*  outputFile) : input(inputFile), output(outputFile) {}
FastIO::FastIO(string inputPath, FILE*  outputFile) : input(inputPath), output(outputFile) {}
FastIO::FastIO(FILE*  inputFile, string outputPath) : input(inputFile), output(outputPath) {}
FastIO::FastIO(string inputPath, string outputPath) : input(inputPath), output(outputPath) {}

// --- Input ---

template <typename T> void FastIO::R (T& n) { return input.R(n); }
template <typename T> void FastIO::RP(T& n) { return input.RP(n); }
template <typename T> void FastIO::RD(T& n) { return input.RD(n); }
void FastIO::RS(string& s) {return input.RS(s); }

template <typename T, typename... Targs> void FastIO::R (T& n, Targs&... Fargs) { return input.R(n, Fargs...); }
template <typename T, typename... Targs> void FastIO::RP(T& n, Targs&... Fargs) { return input.RP(n, Fargs...); }
template <typename T, typename... Targs> void FastIO::RD(T& n, Targs&... Fargs) { return input.RD(n, Fargs...); }
template <typename... Targs> void FastIO::RS(string& s, Targs&... Fargs) { return input.RS(s, Fargs...); }

template <typename... Targs> void FastIO::RL  (int n, Targs*... Fargs) { return input.RL(n, Fargs...); }
template <typename... Targs> void FastIO::RL0 (int n, Targs*... Fargs) { return input.RL0(n, Fargs...); }
template <typename... Targs> void FastIO::RLP (int n, Targs*... Fargs) { return input.RLP(n, Fargs...); }
template <typename... Targs> void FastIO::RLP0(int n, Targs*... Fargs) { return input.RLP0(n, Fargs...); }
template <typename... Targs> void FastIO::RLD (int n, Targs*... Fargs) { return input.RLD(n, Fargs...); }
template <typename... Targs> void FastIO::RLD0(int n, Targs*... Fargs) { return input.RLD0(n, Fargs...); }
template <typename... Targs> void FastIO::RLS (int n, Targs*... Fargs) { return input.RLS(n, Fargs...); }
template <typename... Targs> void FastIO::RLS0(int n, Targs*... Fargs) { return input.RLS0(n, Fargs...); }

// --- Output ---

template <typename T> void FastIO::W (const T& n) { return output.W(n); }
template <typename T, typename... Targs> void FastIO::W(const T& n, const Targs&... Fargs) { return output.W(n, Fargs...); }
template <typename T> void FastIO::WP(const T& n) { return output.WP(n); }
template <typename T> void FastIO::WD(const T& n) { return output.WD(n); }
void FastIO::WC(char c) { return output.WC(c); }
void FastIO::WS(const string& s) { return output.WS(s); }
void FastIO::WS(const char* s) { return output.WS(s); }
void FastIO::WSpace() { return output.WSpace(); }
void FastIO::WLine() { return output.WLine(); }
// --- End of C:\Users\ianli\Desktop\CP\template\Various\FastIO\FastIO.ipp --- 
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

#ifndef ONLINE_JUDGE
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.h --- 


#undef Debug
#undef DebugArray
#undef DebugArray0
#undef DebugArrayLn
#undef DebugArray0Ln
#undef NL

class Debugger {
	public:
		Debugger();
		Debugger(FILE* file);
		Debugger(string path);

		template <typename T> void W (const T& n);
		template <typename T, typename... Targs> void W(const T& n, const Targs&... Fargs);
		template <typename T> void WP(const T& n);
		template <typename T> void WD(const T& n);
		void WC(char c);
		void WS(const string& s);
		void WSpace();
		void WLine();

		void flush();

		template <typename T> void print(const T& n);
		void print(const char* n);
		template <typename T1, typename T2> void print(const pair<T1, T2>& n);
		template <typename... Targs> void print(const tuple<Targs...>& n);
		template <size_t N> void print(const bitset<N>& bs);
		template <typename T> void print(const vector<T>& vec);
		template <typename T> void print(const stack<T>& st);
		template <typename T> void print(const queue<T>& qu);
		template <typename T> void print(const deque<T>& dq);
		template <typename T1, typename T2, typename T3> void print(const priority_queue<T1, T2, T3>& pq);
		template <typename T> void print(const set<T>& se);
		template <typename T1, typename T2> void print(const map<T1, T2>& ma);

		template <typename T, typename... Targs> void print(const T& n, const Targs&... Fargs);
		template <typename T> void printArray(int n, T* x);
		template <typename T> void printArray0(int n, T* x);
		template <typename T> void printArrayLn(int n, T* x);
		template <typename T> void printArray0Ln(int n, T* x);

	private:
		Output output;

		template <typename T> void printp(const T& n, falseType ft);
		template <typename T> void printp(const T& n, trueType tt);
		template <int i, typename... Targs> void printi(const tuple<Targs...>& n); 
		template <int... Is, typename... Targs> void print(const tuple<Targs...>& n, integer_sequence<int, Is...>); // inner

} debug;

#define Debug(...) {debug.WS("("+string(#__VA_ARGS__)+") = ");debug.print(__VA_ARGS__);debug.WLine();debug.flush();}
#define DebugArray(n,x) {debug.WS(#x);debug.WS(" :");debug.printArray(n,x);debug.flush();}
#define DebugArray0(n,x) {debug.WS(#x);debug.WS(" :");debug.printArray0(n,x);debug.flush();}
#define DebugArrayLn(n,x) {debug.WS(#x);debug.WS(" :\n");debug.printArrayLn(n,x);debug.flush();}
#define DebugArray0Ln(n,x) {debug.WS(#x);debug.WS(" :\n");debug.printArray0Ln(n,x);debug.flush();}
#define NL {debug.WLine();debug.flush();}

// --- Start of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.ipp --- 
Debugger::Debugger() : output(stderr) {}
Debugger::Debugger(FILE* file) : output(file) {}
Debugger::Debugger(string path) : output(path) {}

template <typename T> void Debugger::W (const T& n) { return output.W(n); }
template <typename T, typename... Targs> void Debugger::W(const T& n, const Targs&... Fargs) { return output.W(n, Fargs...); }
template <typename T> void Debugger::WP(const T& n) { return output.WP(n); }
template <typename T> void Debugger::WD(const T& n) { return output.WD(n); }
void Debugger::WC(char c) { return output.WC(c); }
void Debugger::WS(const string& s) { return output.WS(s); }
void Debugger::WSpace() { return output.WSpace(); }
void Debugger::WLine() { return output.WLine(); }

void Debugger::flush() { return output.flush(); }

template <> void Debugger::print<short>(const short& n) { return W(n); }
template <> void Debugger::print<unsigned short>(const unsigned short& n) { return WP(n); }

template <> void Debugger::print<int>(const int& n) { return W(n); }
template <> void Debugger::print<unsigned int>(const unsigned int& n) { return WP(n); }

template <> void Debugger::print<long>(const long& n) { return W(n); }
template <> void Debugger::print<unsigned long>(const unsigned long& n) { return WP(n); }

template <> void Debugger::print<long long int>(const long long int& n) { return W(n); }
template <> void Debugger::print<unsigned long long int>(const unsigned long long int& n) { return WP(n); }

#ifdef __SIZEOF_INT128__
template <> void Debugger::print<__int128>(const __int128& n) { return W(n); }
template <> void Debugger::print<unsigned __int128>(const unsigned __int128& n) { return WP(n); }
#endif

template <> void Debugger::print<bool>(const bool& n) { return (n ? WS("true") : WS("false")); }

template <> void Debugger::print<char>(const char& n) { return WC(n); }
template <> void Debugger::print<unsigned char>(const unsigned char& n) { return WP(n); }

template <> void Debugger::print<float>(const float& n) { return W(n); }
template <> void Debugger::print<double>(const double& n) { return W(n); }
template <> void Debugger::print<long double>(const long double& n) { return W(n); }

void Debugger::print(const char* n) { return WS(n); }
template <> void Debugger::print<string>(const string& n) { return WS(n); }

template <typename T1, typename T2> void Debugger::print(const pair<T1, T2>& n) {
	WC('('); print(n.first); WS(", "); print(n.second); WC(')');
	return ;
}

template <typename... Targs> void Debugger::print(const tuple<Targs...>& n) {
	WC('('); print(n, make_integer_sequence<int, sizeof...(Targs)>()); WC(')');
	return ;
}

template <size_t N> void Debugger::print(const bitset<N>& bs) {
	for (size_t i = 0; i < N; i++) {
		if (bs.test(i)) WC('1');
		else WC('0');
	}
	return ;
}

template <typename T> void Debugger::print(const vector<T>& vec) {
	WC('[');
	if (vec.empty()) WS("empty");
	else {
		int sz = int(vec.size());
		print(vec[0]); for (int i = 1; i < sz; i++) { WS(", "); print(vec[i]); }
	}
	WC(']');
	return ;
}

template <typename T> void Debugger::print(const stack<T>& st) {
	stack<T> tmp(st);
	WC('{');
	if (tmp.empty()) WS("empty");
	else {
		print(tmp.top()); tmp.pop();
		while (!tmp.empty()) { WS(", "); print(tmp.top()); tmp.pop(); }
	}
	WC('}');
	return ;
}

template <typename T> void Debugger::print(const queue<T>& qu) {
	queue<T> tmp(qu);
	WC('{');
	if (tmp.empty()) WS("empty");
	else {
		print(tmp.front()); tmp.pop();
		while (!tmp.empty()) { WS(", "); print(tmp.front()); tmp.pop(); }
	}
	WC('}');
	return ;
}

template <typename T> void Debugger::print(const deque<T>& dq) {
	WC('{');
	if (dq.empty()) WS("empty");
	else {
		int sz = int(dq.size());
		print(dq[0]); for (int i = 1; i < sz; i++) { WS(", "); print(dq[i]); }
	}
	WC('}');
	return ;
}

template <typename T1, typename T2, typename T3> void Debugger::print(const priority_queue<T1, T2, T3>& pq) {
	priority_queue<T1, T2, T3> tmp(pq);
	WC('{');
	if (tmp.empty()) WS("empty");
	else {
		print(tmp.top()); tmp.pop();
		while (!tmp.empty()) { WS(", "); print(tmp.top()); tmp.pop(); }
	}
	WC('}');
	return ;
}

template <typename T> void Debugger::print(const set<T>& se) {
	WC('{');
	if (se.empty()) WS("empty");
	else {
		bool first = true;
		for (const T& i : se) {
			if (first) first = false;
			else WS(", ");
			print(i);
		}
	}
	WC('}');
	return ;
}

template <typename T1, typename T2> void Debugger::print(const map<T1, T2>& ma) {
	WC('{');
	if (ma.empty()) WS("empty");
	else {
		bool first = true;
		for (const pair<const T1, T2>& i : ma) {
			if (first) first = false;
			else WS(", ");
			print(i);
		}
	}
	WC('}');
	return ;
}

template <typename T> void Debugger::print(const T& n) {
	n.out(output);
	return ;
}

template <typename T, typename... Targs> void Debugger::print(const T& n, const Targs&... Fargs) { print(n); WC(','); WSpace(); return print(Fargs...); }
template <typename T> void Debugger::printArray(int n, T* x) {
	for (int i = 1; i <= n; i++) {
		WSpace();
		print(x[i]);
	}

	WLine();
	return ;
}

template <typename T> void Debugger::printArray0(int n, T* x) {
	for (int i = 0; i < n; i++) {
		WSpace();
		print(x[i]);
	}

	WLine();
	return ;
}

template <typename T> void Debugger::printArrayLn(int n, T* x) {
	for (int i = 1; i <= n; i++) {
		print(x[i]);
		WLine();
	}

	return ;
}

template <typename T> void Debugger::printArray0Ln(int n, T* x) {
	for (int i = 0; i < n; i++) {
		print(x[i]);
		WLine();
	}

	return ;
}

// --- private ---

template <typename T> void Debugger::printp(const T& n, falseType ft) {
	WS(", "); print(n);
	return ;
}
template <typename T> void Debugger::printp(const T& n, trueType tt) {
	print(n);
	return ;
}

template <int i, typename... Targs> void Debugger::printi(const tuple<Targs...>& n) {
	return printp(get<i>(n), boolType<isZero<i>::value>());
}

template <int... Is, typename... Targs> void Debugger::print(const tuple<Targs...>& n, integer_sequence<int, Is...> seq) {
	[[maybe_unused]] auto l = { (printi<Is>(n), 0)... };
	return ;
}
// --- End of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.ipp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp --- 
#endif

// using Mint = Mod_Int<kMod>;

int main() {
	FastIO IO;

}
// --- End of C:\Users\ianli\Desktop\CP\template\Applications\Minifier\test.cpp --- 
