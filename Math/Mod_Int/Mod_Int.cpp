template <int kMod> struct Mod_Int;
template <int kMod, typename T> constexpr Mod_Int<kMod> Pow(Mod_Int<kMod> a, T b) {
	Mod_Int<kMod> ans = 1;
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
	constexpr Mod_Int() : val(0) {}
	template <typename T> constexpr Mod_Int(const T &x) : val(x) {}

	constexpr Mod_Int inv() const {return Pow(*this, kMod - 2);} 

	constexpr Mod_Int operator -() const {
		if (val) return Mod_Int(kMod - val);
		else return Mod_Int(0);
	}

	constexpr Mod_Int operator + (const Mod_Int &x) const {
		Mod_Int ans(val + x.val);
		if (ans.val >= kMod) ans.val -= kMod;
		return ans;
	}
	constexpr Mod_Int operator - (const Mod_Int &x) const {
		Mod_Int ans(val - x.val);
		if (ans.val < 0) ans.val += kMod;
		return ans;
	}
	constexpr Mod_Int operator * (const Mod_Int &x) const {return Mod_Int(uint64_t(val) * x.val % kMod);}
	constexpr Mod_Int operator / (const Mod_Int &x) const {return *this * x.inv();}

	constexpr Mod_Int operator += (const Mod_Int &x) {return *this = *this + x;}
	constexpr Mod_Int operator -= (const Mod_Int &x) {return *this = *this - x;}
	constexpr Mod_Int operator *= (const Mod_Int &x) {return *this = *this * x;}
	constexpr Mod_Int operator /= (const Mod_Int &x) {return *this = *this / x;}

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

	constexpr bool operator < (const Mod_Int &x) const {return val < x.val;}
	constexpr bool operator > (const Mod_Int &x) const {return val > x.val;}
	constexpr bool operator <= (const Mod_Int &x) const {return val <= x.val;}
	constexpr bool operator >= (const Mod_Int &x) const {return val >= x.val;}
	constexpr bool operator == (const Mod_Int &x) const {return val == x.val;}
	constexpr bool operator != (const Mod_Int &x) const {return val != x.val;}

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

/*
template <int kN> struct Factorial {
	Mint val[kN];

	constexpr Factorial() : val() {
		val[0] = val[1] = 1;
		for (int i = 2; i < kN; i++) val[i] = val[i - 1] * i;
	}

	constexpr Mint operator [] (int x) const {return val[x];}
};

template <int kN> struct Factorial_Inv {
	Mint val[kN];
	
	constexpr Factorial_Inv(Mint m) : val() {
		val[0] = val[1] = 1;
		val[kN] = m.inv();
		for (int i = kN - 1; i > 2; i--) val[i - 1] = val[i] * i;
	}

	constexpr Mint operator [] (int x) const {return val[x];}
};

#if defined(Pre_Factorial)
	constexpr Factorial<Pre_Factorial> f;
	constexpr Factorial_Inv<Pre_Factorial> inf(f[Pre_Factorial - 1]);
	inline Mint C(int n, int m) {return f[n] * inf[m] * inf[n - m];}
	inline Mint Catalan(int n) {return f[n << 1] * inf[n + 1] * inf[n];}
	inline Mint Catalan(int a, int b) {return C(a + b, b) - C(a + b, b - 1);}
#elif defined(Pre_Factorial_No_Inf)
	constexpr Factorial<Pre_Factorial_No_Inf> f;
	inline Mint C(int n, int m) {return f[n] / f[m] / f[n - m];}
	inline Mint Catalan(int n) {return f[n << 1] / f[n + 1] / f[n];}
	inline Mint Catalan(int a, int b) {return C(a + b, b) - C(a + b, b - 1);}
#endif

template <int kN> struct Inverse {
	Mint val[kN + 1];

#if defined(Pre_Factorial) and Pre_Inverse <= Pre_Factorial
	constexpr Inverse() : val() {
		for (int i = 1; i <= kN; i++) val[i] = f[i - 1] * inf[i];
	}
#else
	constexpr Inverse() : val() {
		val[0] = val[1] = 1;
		for (int i = 2; i <= kN; i++) val[i] = val[i - 1] * i;
		val[kN] = val[kN].inv();

		for (int i = kN; i >= 1; i--) {
			Mint tmp = val[i - 1] * val[i];
			val[i - 1] = val[i] * i;
			val[i] = tmp;
		}
	}
#endif

	constexpr Mint operator [] (int x) const {return val[x];}
};

#if defined(Pre_Inverse)
constexpr Inverse<Pre_Inverse> inv;
#endif
*/
