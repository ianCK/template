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
	constexpr Mod_Int operator * (const Mod_Int &x) const {return Mod_Int(1LL * val * x.val % kMod);}
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

template <int kN> struct Factorial {
	Mint val[kN + 1];

	constexpr Factorial() : val() {
		val[0] = val[1] = 1;
		for (int i = 2; i <= kN; i++) val[i] = val[i - 1] * i;
	}

	constexpr Mint operator [] (int x) const {return val[x];}
};

template <int kN> struct Factorial_Inv {
	Mint val[kN + 1];
	
	constexpr Factorial_Inv(const Factorial<kN> &f) : val() {
		val[0] = val[1] = 1;
		val[kN] = f[kN].inv();
		for (int i = kN; i > 2; i--) val[i - 1] = val[i] * i;
	}

	constexpr Mint operator [] (int x) const {return val[x];}
};

template <int kN> struct Factorial_C {
	const Factorial<kN> &f;
	const Factorial_Inv<kN> &inf;
	constexpr Factorial_C(const Factorial<kN> &_f, const Factorial_Inv<kN> &_inf) : f(_f), inf(_inf) {}
	constexpr Mint operator () (int n, int m) const {return f[n] * inf[m] * inf[n - m];}
};

template <int kN> struct Factorial_Catalan {
	const Factorial<kN> &f;
	const Factorial_Inv<kN> &inf;
	constexpr Factorial_Catalan(const Factorial<kN> &_f, const Factorial_Inv<kN> &_inf) : f(_f), inf(_inf) {}
	constexpr Mint operator () (int n) const {return f[n << 1] * inf[n] * inf[n + 1];}
};

template <int kN> struct Factorial_No_Inf_C {
	const Factorial<kN> &f;
	constexpr Factorial_No_Inf_C(const Factorial<kN> &_f) : f(_f) {}
	constexpr Mint operator () (int n, int m) const {return f[n] / f[m] / f[n - m];}
};

template <int kN> struct Factorial_No_Inf_Catalan {
	const Factorial<kN> &f;
	constexpr Factorial_No_Inf_Catalan(const Factorial<kN> &_f) : f(_f) {}
	constexpr Mint operator () (int n) const {return f[n << 1] / f[n] / f[n + 1];}
};

#if defined(Pre_Factorial)
	constexpr Factorial<Pre_Factorial> f;
	constexpr Factorial_Inv<Pre_Factorial> inf(f);
	constexpr Factorial_C<Pre_Factorial> C(f, inf);
	constexpr Factorial_Catalan<Pre_Factorial> Catalan(f, inf);
#elif defined(Pre_Factorial_No_Inf)
	constexpr Factorial<Pre_Factorial_No_Inf> f;
	constexpr Factorial_No_Inf_C<Pre_Factorial_No_Inf> C(f);
	constexpr Factorial_No_Inf_Catalan<Pre_Factorial_No_Inf> Catalan(f);
#endif

/*
#define Pre_Factorial(kN) \
	constexpr Factorial<kN> f; \
	constexpr Factorial_Inv<kN> inf(f); \
	constexpr Factorial_C<kN> C(f, inf); \
	constexpr Factorial_Catalan<kN> Catalan(f, inf);

#define Pre_Factorial_No_Inf(kN) \
	constexpr Factorial<kN> f; \
	constexpr Factorial_No_Inf_C<kN> C(f); \
	constexpr Factorial_No_Inf_Catalan<kN> Catalan(f);
*/
