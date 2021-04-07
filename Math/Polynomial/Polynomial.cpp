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

constexpr int kMod = 998244353;
#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Math\Mod_Int\Mod_Int.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Math\NTT\Butterfly.cpp"

struct Polynomial {
	vector<Mint> val;
	
	void pull() {
		while (!val.empty() && val.back() == 0) val.pop_back();
		return ;
	}

	Polynomial() {}
	Polynomial(vector<Mint> v) {val = v; reverse(val.begin(), val.end()); pull();}

	int degree() const {return int(val.size()) - 1;}
	Mint lead() const {return val.back();}

	Mint& operator [] (int idx) {return val[idx];}

	Polynomial operator + (Polynomial B) const {
		Polynomial ans;
		int n = degree(), m = B.degree();

		ans.val = val;
		ans.val.resize(max(n, m) + 1);

		for (int i = 0; i <= m; i++) ans[i] += B[i];

		ans.pull();
		return ans;
	}

	Polynomial operator - (Polynomial B) const {
		Polynomial ans;
		int n = degree(), m = B.degree();

		ans.val = val;
		ans.val.resize(max(n, m) + 1);

		for (int i = 0; i <= m; i++) ans[i] -= B[i];

		ans.pull();
		return ans;
	}

	Polynomial operator * (Mint x) const {
		Polynomial ans;
		int n = degree();

		ans.val = val;
		for (int i = 0; i <= n; i++) ans[i] *= x;
		
		ans.pull();
		return ans;
	}

	Polynomial operator / (Mint x) const {
		Polynomial ans;
		int n = degree();

		ans.val = val;
		for (int i = 0; i <= n; i++) ans[i] /= x;

		ans.pull();
		return ans;
	}

	Polynomial operator << (int x) const {
		Polynomial ans;
		int n = degree();

		ans.val.resize(n + x + 1);
		for (int i = 0; i <= n; i++) ans[i + x] = val[i];

		return ans;
	}
	Polynomial operator >> (int x) const {
		Polynomial ans;
		int n = degree();

		if (x > n) {
			ans.val.push_back(0);
			return ans;
		}

		ans.val.resize(n + 1 - x);
		for (int i = x; i <= n; i++) ans[i - x] = val[i];

		return ans;
	}

	static Polynomial Naive_Convolution(Polynomial A, Polynomial B) {
		Polynomial ans;
		int n = A.degree(), m = B.degree();
		
		ans.val.resize(n + m + 1);
		for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) ans[i + j] += A[i] * B[j];

		ans.pull();
		return ans;
	}

	static Polynomial NTT_Convolution(Polynomial A, Polynomial B) {
		Polynomial ans;
		int n = A.degree(), m = B.degree();

		int sz = NTT_size(n + m);

		Mint *tA = new Mint[sz], *tB = new Mint[sz];
		for (int i = 0; i <= n; i++) tA[i] = A[i];
		for (int i = 0; i <= m; i++) tB[i] = B[i];
		memset(tA + n + 1, 0, sizeof(Mint) * (sz - n - 1));
		memset(tB + m + 1, 0, sizeof(Mint) * (sz - m - 1));

		NTT(tA, sz);
		NTT(tB, sz);
		for (int i = 0; i < sz; i++) tA[i] *= tB[i];
		NTT_Inv(tA, sz);

		ans.val.resize(n + m + 1);
		for (int i = 0; i <= n + m; i++) ans[i] = tA[i];

		ans.pull();
		return ans;
	}

	Polynomial operator * (Polynomial B) const {
		int n = degree(), m = B.degree();
		if (min(n, m) <= 60) return Naive_Convolution(*this, B);
		else return NTT_Convolution(*this, B);
	}

	Mint operator ()(Mint x) const {}

	Polynomial operator += (Polynomial B) {return *this = *this + B;}
	Polynomial operator -= (Polynomial B) {return *this = *this - B;}
	Polynomial operator *= (Mint B) {return *this = *this * B;}
	Polynomial operator /= (Mint B) {return *this = *this / B;}
	Polynomial operator <<= (int x) {return *this = *this << x;}
	Polynomial operator >>= (int x) {return *this = *this >> x;}
	Polynomial operator *= (Polynomial B) {return *this = *this * B;}

	Polynomial deriv() const {
		Polynomial ans;

		ans.pull();
		return ans;
	}
	Polynomial integr() const {
	}
	Polynomial inv(int n) const {
	}
	Polynomial log(int n) const {
	}
	Polynomial exp(int n) const {
	}
	Polynomial pow(int k, int n) const {
	}

	vector<Mint> eval(vector<Mint> x) const {
	}

	static Polynomial inter(vector<Mint> x, vector<Mint> y) {
	}


	void out() const {printf("val :"); for (Mint i : val) printf(" "), i.out(); printf("\n");}
};

using Poly = Polynomial;

constexpr int kN = NTT_size((1 << 20) - 2);
int a[kN], b[kN];

int main() {
	int n, m; RP(n, m);
	RLP(n, a); RLP(m, b);
	
	Poly A, B;
	vector<Mint> vA(n), vB(m);

	for (int i = 1; i <= n; i++) vA[i - 1] = a[i];
	for (int i = 1; i <= m; i++) vB[i - 1] = b[i];

	A.val = vA;
	B.val = vB;
	A *= B;

	printf("%d", A[0]); for (int i = 1; i <= n + m - 2; i++) printf(" %d", A[i]); printf("\n");
}
