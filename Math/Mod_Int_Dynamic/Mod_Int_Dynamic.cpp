template <typename T> T Pow(T a, long long int b) {
	T ans(1);
	while (b) {
		if (b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

struct Mod_Int {
	static int kMod;
	long long int val;
	Mod_Int() {val = 0;}
	template <typename T> Mod_Int(T x) {val = x;}

	static void set_kMod(int x) {kMod = x;}
	static int Mod() {return kMod;}

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
	Mod_Int operator * (const Mod_Int &x) const {return Mod_Int(val * x.val % kMod);}
	Mod_Int operator / (const Mod_Int &x) const {return *this * x.inv();}
	Mod_Int operator ^ (const Mod_Int &x) const {return Pow(*this, x.val);}
	Mod_Int operator << (const int &x) const {return Mod_Int((val << x) % kMod);}

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

	bool operator == (const Mod_Int &x) const {return val == x.val;}
	bool operator != (const Mod_Int &x) const {return val != x.val;}
};
int Mod_Int::kMod = 0;

using Mint = Mod_Int;

namespace Factorial {
	Mint *f, *inf;
	void Pre_Factorial(const int &sz) {
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

namespace No_Inf_Factorial {
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
