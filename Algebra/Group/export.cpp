// Merged by FileMerger.exe
// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Group\test.cpp --- 
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
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\UsefulFunctions\UsefulFunctions.h --- 

// template <typename T, typename... Targs> vector<T> make_vector(Targs... targs);

template <typename T> void sort(vector<T> &v);
template <typename T> void sort_r(vector<T> &v);

void sort(string &s);
void sort_r(string &s);

template <typename T> void reverse(vector<T> &v);
void reverse(string &s);

template <typename T> void Merge(const vector<T> &a, const vector<T> &b, vector<T> &c);
template <typename T> void Concatanate(const vector<T> &a, const vector<T> &b, vector<T> &c);
template <typename T> void Append(vector<T> &lhs, const vector<T>& rhs);
template <typename T> void Erase(vector<T> &vec, const T& x);
template <typename T> void Discrete(vector<T> &v);
template <typename T> int Discrete_Id(const vector<T> &v, const T& x);

template <typename T> using PQ = priority_queue<T>;
template <typename T> using PQ_R = priority_queue<T, vector<T>, greater<T>>;

template <typename T> T ABS(T n);
template <typename T> __attribute__((target("bmi"))) T gcd(T a, T b);
template <typename T> T lcm(const T& a, const T& b);
template <typename T, typename... Targs> T gcd(const T& a, T b, T c, Targs... args);
template <typename T, typename... Targs> T lcm(const T& a, T b, T c, Targs... args);
template <typename T, typename... Targs> T min(const T& a, T b, T c, Targs... args);
template <typename T, typename... Targs> T max(const T& a, T b, T c, Targs... args);
template <typename T, typename... Targs> void chmin(T &a, const T& b, const Targs&... args);
template <typename T, typename... Targs> void chmax(T &a, const T& b, const Targs&... args);
template <typename T> T SQ(T x);

// 2 ~ n
vector<int> Primes(int n);

template <typename T> vector<T> factors(T n);
int mex(const vector<int>& vec);
template <typename T> vector<T> factorize(T n);

// --- Start of C:\Users\ianli\Desktop\CP\template\Various\UsefulFunctions\UsefulFunctions.ipp --- 
template <typename T> void sort(vector<T> &v) { return sort(v.begin(), v.end()); }
template <typename T> void sort_r(vector<T> &v) { return sort(v.begin(), v.end(), greater<T>()); }

void sort(string &s) { return sort(s.begin(), s.end()); }
void sort_r(string &s) { return sort(s.begin(), s.end(), greater<char>()); }

template <typename T> void reverse(vector<T> &v) { return reverse(v.begin(), v.end()); }
void reverse(string &s) { return reverse(s.begin(), s.end()); }

template <typename T> void Merge(const vector<T> &a, const vector<T> &b, vector<T> &c) {
	if (c.size() < a.size() + b.size()) c.resize(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	return ;
}

template <typename T> void Concatanate(const vector<T> &a, const vector<T> &b, vector<T> &c) {
	int a_size = int(a.size()), b_size = int(b.size());
	c.resize(a_size + b_size);
	for (int i = 0; i < a_size; i++) c[i] = a[i];
	for (int i = 0; i < b_size; i++) c[i + a_size] = b[i];
	return ;
}

template <typename T> void Append(vector<T> &lhs, const vector<T>& rhs) {
	int lsz = int(lhs.size()), rsz = int(rhs.size());
	lhs.reserve(lsz + rsz);
	for (int i = 0; i < rsz; i++) lhs.push_back(rhs[i]);
	return ;
}

template <typename T> void Erase(vector<T> &vec, const T& x) {
	int sz = int(vec.size());
	for (int i = 0; i < sz; i++) if (vec[i] == x) {
		swap(vec[i], vec.back());
		vec.pop_back();
		break;
	}
	return ;
}

template <typename T> void Discrete(vector<T> &v) { sort(v); v.resize(unique(v.begin(), v.end()) - v.begin()); return ; }
template <typename T> int Discrete_Id(const vector<T> &v, const T& x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }

template <typename T> T ABS(T n) { return n >= 0 ? n : -n; }
template <typename T> __attribute__((target("bmi"))) T gcd(T a, T b) {
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
template <typename T> T lcm(const T& a, const T& b) { return a * (b / gcd(a, b)); }
template <typename T, typename... Targs> T gcd(const T& a, const T& b, const T& c, const Targs&... args) { return gcd(a, gcd(b, c, args...)); }
template <typename T, typename... Targs> T lcm(const T& a, const T& b, const T& c, const Targs&... args) { return lcm(a, lcm(b, c, args...)); }
template <typename T, typename... Targs> T min(const T& a, const T& b, const T& c, const Targs&... args) { return min(a, min(b, c, args...)); }
template <typename T, typename... Targs> T max(const T& a, const T& b, const T& c, const Targs&... args) { return max(a, max(b, c, args...)); }
template <typename T, typename... Targs> void chmin(T &a, const T& b, const Targs&... args) { a = min(a, b, args...); return ; }
template <typename T, typename... Targs> void chmax(T &a, const T& b, const Targs&... args) { a = max(a, b, args...); return ; }
template <typename T> T SQ(T x) { return x * x; }

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
// --- End of C:\Users\ianli\Desktop\CP\template\Various\UsefulFunctions\UsefulFunctions.ipp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\UsefulFunctions\UsefulFunctions.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\UsefulFunctions\UsefulFunctions.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\UsefulFunctions\UsefulFunctions.cpp --- 

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
	return ((printi<Is>(n)), ...);
}
// --- End of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.ipp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp --- 
#endif

// using Mint = Mod_Int<kMod>;

// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Operations\Operations.h --- 

// --- unary ---
template <typename T> constexpr T MINUS(const T& x);
template <typename T> constexpr T NOT(const T& x);

// --- binary ---
template <typename T> constexpr T ADD(const T& lhs, const T& rhs);
template <typename T> constexpr T SUB(const T& lhs, const T& rhs);
template <typename T> constexpr T MUL(const T& lhs, const T& rhs);
template <typename T> constexpr T DIV(const T& lhs, const T& rhs);

template <typename T> constexpr T  OR(const T& lhs, const T& rhs);
template <typename T> constexpr T AND(const T& lhs, const T& rhs);
template <typename T> constexpr T XOR(const T& lhs, const T& rhs);

template <typename T> constexpr T MAX(const T& lhs, const T& rhs);
template <typename T> constexpr T MIN(const T& lhs, const T& rhs);

// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Operations\Operations.ipp --- 
// --- unary ---
template <typename T> constexpr T MINUS(const T& x) { return -x; }
template <typename T> constexpr T NOT(const T& x) { return ~x; }

// --- binary ---
template <typename T> constexpr T ADD(const T& lhs, const T& rhs) { return lhs + rhs; }
template <typename T> constexpr T SUB(const T& lhs, const T& rhs) { return lhs - rhs; }
template <typename T> constexpr T MUL(const T& lhs, const T& rhs) { return lhs * rhs; }
template <typename T> constexpr T DIV(const T& lhs, const T& rhs) { return lhs / rhs; }

template <typename T> constexpr T  OR(const T& lhs, const T& rhs) { return lhs | rhs; }
template <typename T> constexpr T AND(const T& lhs, const T& rhs) { return lhs & rhs; }
template <typename T> constexpr T XOR(const T& lhs, const T& rhs) { return lhs ^ rhs; }

template <typename T> constexpr T MAX(const T& lhs, const T& rhs) { return lhs >= rhs ? lhs : rhs; }
template <typename T> constexpr T MIN(const T& lhs, const T& rhs) { return lhs <= rhs ? lhs : rhs; }
// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Operations\Operations.ipp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Operations\Operations.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Operations\Operations.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Operations\Operations.cpp --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Group\Group.h --- 

// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Monoid\Monoid.h --- 

// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Subgroup\Subgroup.h --- 


template <typename T, T (*op)(const T&, const T&)> class Subgroup {
	public:
		constexpr Subgroup();
		constexpr Subgroup(const T& _val);

		template <typename oT> constexpr Subgroup(const oT& _val);

		constexpr Subgroup operator * (const Subgroup<T, op>& o) const;
		constexpr const Subgroup& operator *= (const Subgroup<T, op>& o);

		operator T() const;
		const T& value() const;

		void out(Output& output) const;

	protected:
		T val;
};

// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Subgroup\Subgroup.ipp --- 
template <typename T, T (*op)(const T&, const T&)> constexpr Subgroup<T, op>::Subgroup() : val() {}
template <typename T, T (*op)(const T&, const T&)> constexpr Subgroup<T, op>::Subgroup(const T& _val) : val(_val) {}

template <typename T, T (*op)(const T&, const T&)> template <typename oT> constexpr Subgroup<T, op>::Subgroup(const oT& _val) : val(_val) {}

template <typename T, T (*op)(const T&, const T&)> constexpr Subgroup<T, op> Subgroup<T, op>::operator * (const Subgroup<T, op>& o) const { return op(val, o.value()); }
template <typename T, T (*op)(const T&, const T&)> constexpr const Subgroup<T, op>& Subgroup<T, op>::operator *= (const Subgroup<T, op>& o) { val = op(val, o.value()); return *this; }

template <typename T, T (*op)(const T&, const T&)> Subgroup<T, op>::operator T() const { return val; }
template <typename T, T (*op)(const T&, const T&)> const T& Subgroup<T, op>::value() const { return val; }

template <typename T, T (*op)(const T&, const T&)> void Subgroup<T, op>::out(Output& output) const { output.W(val); }
// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Subgroup\Subgroup.ipp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Subgroup\Subgroup.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Subgroup\Subgroup.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Subgroup\Subgroup.cpp --- 

template <typename T, T (*op)(const T&, const T&), T E> class Monoid : public Subgroup<T, op> {
	using Subgroup<T, op>::Subgroup;

	public:
		static constexpr T identity = E;

		static_assert(op(identity, identity) == identity, "E * E != E");

		constexpr Monoid();
};

// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Monoid\Monoid.ipp --- 
template <typename T, T (*op)(const T&, const T&), T E> constexpr Monoid<T, op, E>::Monoid() : Subgroup<T, op>::val(identity) {}
// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Monoid\Monoid.ipp --- 

// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Monoid\Monoid.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Monoid\Monoid.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Monoid\Monoid.cpp --- 

template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> class Group : public Monoid<T, op, E> {
	using Monoid<T, op, E>::Monoid;

	public:

		static_assert(inv(Monoid<T, op, E>::identity) == Monoid<T, op, E>::identity, "E^-1 != E");

		constexpr Group operator / (const Group<T, op, E, inv>& o) const;
		constexpr const Group& operator /= (const Group<T, op, E, inv>& o);

		T inverse() const;
};

// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Group\Group.ipp --- 
template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> constexpr Group<T, op, E, inv> Group<T, op, E, inv>::operator / (const Group<T, op, E, inv>& o) const { return op(Monoid<T, op, E>::val, o.inverse()); }
template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> constexpr const Group<T, op, E, inv>& Group<T, op, E, inv>::operator /= (const Group<T, op, E, inv>& o) { Monoid<T, op, E>::val = op(Monoid<T, op, E>::val, o.inverse()); return *this; }

template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> T Group<T, op, E, inv>::inverse() const { return inv(Monoid<T, op, E>::val); }
// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Group\Group.ipp --- 


// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Group\Group.h --- 
// --- Start of C:\Users\ianli\Desktop\CP\template\Algebra\Group\Group.cpp --- 
// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Group\Group.cpp --- 

struct md {
	double val;

	constexpr md(double _val) : val(_val) {}
	md operator * (const md& o) const { return md(val * o.val); }
	md operator / (const md& o) const { return md(val / o.val); }

	void out(Output& output) const { return output.W(val); }
};

md rev(const md& x) { return md(1.0 / x.val); }
constexpr double rev(const double& x) { return 1 / x; }

int main() {
	FastIO IO;

	Group<int, ADD, 0, MINUS> a(3), b(5);

	Debug(a, b, a * b, a / b);

	// This is only valid in C++20
	// Group<double, MUL, double(1), rev> c(3), d(5);
	// Debug(c, d, c * d, c / d);

}
// --- End of C:\Users\ianli\Desktop\CP\template\Algebra\Group\test.cpp --- 
