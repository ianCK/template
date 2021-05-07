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
		Polynomial ans = *this;
		int n = degree(), m = B.degree();

		ans.val.resize(max(n, m) + 1);

		for (int i = 0; i <= m; i++) ans[i] += B[i];

		ans.pull();
		return ans;
	}

	Polynomial operator - (Polynomial B) const {
		Polynomial ans = *this;
		int n = degree(), m = B.degree();

		ans.val.resize(max(n, m) + 1);

		for (int i = 0; i <= m; i++) ans[i] -= B[i];

		ans.pull();
		return ans;
	}

	Polynomial operator * (Mint x) const {
		Polynomial ans = *this;
		int n = degree();

		for (int i = 0; i <= n; i++) ans[i] *= x;
		
		ans.pull();
		return ans;
	}

	Polynomial operator / (Mint x) const {
		Polynomial ans = *this;
		int n = degree();

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

	Polynomial operator % (int n) const {
		int deg = degree();
		if (deg <= n) return *this;

		Polynomial ans = *this;
		ans.val.resize(deg);

		ans.pull();
		return ans;
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
		Polynomial ans = *this >> 1;
		
		int n = ans.degree();
		for (int i = 0; i <= n; i++) ans[i] *= i + 1;

		ans.pull();
		return ans;
	}
	Polynomial integr() const {
		using namespace Inverse;
		Polynomial ans = *this << 1;

		int n = ans.degree();
		for (int i = 1; i <= n; i++) ans[i] *= inv[i];

		ans.pull();
		return ans;
	}
	Polynomial Inv(int n) const {
		Polynomial ans({val[0].inv()});
		int cur_len = 1;

		while (cur_len <= n) {
			cur_len <<= 1;
			ans = (ans * (Polynomial({2}) - ((*this % cur_len) * ans % cur_len))) % cur_len;
		}

		return ans % (n + 1);
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
