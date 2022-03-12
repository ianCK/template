template <typename T> class Polynomial {
	private:
		vector<T> val;

		void pull();

	public:
		Polynomial();
		Polynomial(T c);
		template <typename... Targs> Polynomial(T c, Targs... targs); 
		Polynomial(vector<T> _val);

		int size() const;
		int degree() const;
		T lead() const;

		void resize(int n);
		void clear();

		T& operator [] (int idx);
		const T& operator [] (int idx) const;
		Polynomial operator + (const Polynomial& rhs) const;
		Polynomial operator - (const Polynomial& rhs) const;
		Polynomial operator * (const T& scaler) const;
		Polynomial operator / (const T& scaler) const;
		Polynomial operator * (const Polynomial& rhs) const;
		Polynomial operator << (int x) const;
		Polynomial operator >> (int x) const;

		// evaluate
		T operator () (const T& x) const;
		// multi-point evaluate
		vector<T> operator () (const vector<T>& vec) const;

		Polynomial operator += (const Polynomial& rhs);
		Polynomial operator -= (const Polynomial& rhs);
		Polynomial operator *= (const T& scaler);
		Polynomial operator /= (const T& scaler);
		Polynomial operator *= (const Polynomial& rhs);
		Polynomial operator <<= (int x);
		Polynomial operator >>= (int x);

		// mod x^n
		Polynomial trim(int n) const;
		Polynomial derivative() const;
		Polynomial integral() const;
		Polynomial inverse(int n) const;
		Polynomial log(int n) const;
		Polynomial exp(int n) const;
		Polynomial pow(int k, int n) const;
};

// --- private --- 

template <typename T> void Polynomial<T>::pull() {
	while (int(val.size()) > 1 and val.back() == 0) val.pop_back();
	return ;
}

// --- public ---

template <typename T> Polynomial<T>::Polynomial() {}
template <typename T> Polynomial<T>::Polynomial(T c) {val.push_back(c);}
template <typename T> template <typename... Targs> Polynomial<T>::Polynomial(T c, Targs... targs) {val = make_vector<T, Targs...>(c, targs...);}
template <typename T> Polynomial<T>::Polynomial(vector<T> _val) : val(_val) {}

template <typename T> int Polynomial<T>::size() const {return int(val.size());}
template <typename T> int Polynomial<T>::degree() const {return int(val.size()) - 1;}
template <typename T> T Polynomial<T>::lead() const {return val.back();}

template <typename T> void Polynomial<T>::resize(int n) {return val.resize(n);}
template <typename T> void Polynomial<T>::clear() {return val.clear();}

template <typename T> T& Polynomial<T>::operator [] (int idx) {return val[idx];}
template <typename T> const T& Polynomial<T>::operator [] (int idx) const {return val[idx];}
template <typename T> Polynomial<T> Polynomial<T>::operator + (const Polynomial<T>& rhs) const {
	int lsz = size(), rsz = rhs.size();
	int sz = max(lsz, rsz);

	Polynomial<T> ans(val);
	ans.resize(sz);

#pragma unroll
	for (int i = 0; i < rsz; i++) ans[i] += rhs[i];

	ans.pull();

	return ans;
}

template <typename T> Polynomial<T> Polynomial<T>::operator - (const Polynomial<T>& rhs) const {
	int lsz = size(), rsz = rhs.size();
	int sz = max(lsz, rsz);

	Polynomial<T> ans(val);
	ans.resize(sz);

#pragma unroll
	for (int i = 0; i < rsz; i++) ans[i] -= rhs[i];

	ans.pull();

	return ans;
}

template <typename T> Polynomial<T> Polynomial<T>::operator * (const T& scaler) const {
	int sz = size();

	Polynomial<T> ans(val);

#pragma unroll
	for (int i = 0; i < sz; i++) ans[i] *= scaler;

	return ans;
}

template <typename T> Polynomial<T> Polynomial<T>::operator / (const T& scaler) const {
	int sz = size();

	Polynomial<T> ans(val);

#pragma unroll
	for (int i = 0; i < sz; i++) ans[i] /= scaler;

	return ans;
}

template <typename T> Polynomial<T> Polynomial<T>::operator * (const Polynomial<T>& rhs) const {
	int ldeg = degree(), rdeg = rhs.degree();
	int sz = ldeg + rdeg + 1;

	Polynomial<T> ans;
	ans.resize(sz);

#pragma unroll
	for (int i = 0; i < sz; i++) ans[i] = 0;

#pragma unroll
	for (int i = 0; i <= ldeg; i++) {
#pragma unroll
		for (int j = 0; j <= rdeg; j++) ans[i + j] += val[i] * rhs[j];
	}

	return ans;
}

template <typename T> Polynomial<T> Polynomial<T>::operator << (int x) const {
	int sz = size() + 1;

	Polynomial<T> ans;
	ans.resize(sz);

	ans[0] = 0;
#pragma unroll
	for (int i = 1; i < sz; i++) ans[i] = val[i - 1];

	return ans;
}

template <typename T> Polynomial<T> Polynomial<T>::operator >> (int x) const {
	int sz = size() - 1;

	Polynomial<T> ans;
	ans.resize(sz);

#pragma unroll
	for (int i = 0; i < sz; i++) ans[i] = val[i + 1];

	return ans;
}

// evaluate
template <typename T> T Polynomial<T>::operator () (const T& x) const {
	int sz = size();

	T ans = 0;
#pragma unroll
	for (int i = sz - 1; i >= 0; i--) ans = ans * x + val[i];

	return ans;
}

// multi-point evaluate
// template <typename T> vector<T> Polynomial::operator () (const vector<T>& vec) const;

template <typename T> Polynomial<T> Polynomial<T>::operator += (const Polynomial<T>& rhs) {return *this = *this + rhs;}
template <typename T> Polynomial<T> Polynomial<T>::operator -= (const Polynomial<T>& rhs) {return *this = *this - rhs;}
template <typename T> Polynomial<T> Polynomial<T>::operator *= (const T& scaler) {return *this = *this * scaler;}
template <typename T> Polynomial<T> Polynomial<T>::operator /= (const T& scaler) {return *this = *this * scaler;}
template <typename T> Polynomial<T> Polynomial<T>::operator *= (const Polynomial<T>& rhs) {return *this = *this * rhs;}
template <typename T> Polynomial<T> Polynomial<T>::operator <<= (int x) {return *this = *this << x;}
template <typename T> Polynomial<T> Polynomial<T>::operator >>= (int x) {return *this = *this >> x;}

template <typename T> Polynomial<T> Polynomial<T>::trim(int n) const {
	Polynomial<T> ans(val);
	ans.resize(n);
	return ans;
}

template <typename T> Polynomial<T> Polynomial<T>::derivative() const {
	int sz = size() - 1;

	Polynomial<T> ans;
	ans.resize(sz);

	for (int i = 0; i < sz; i++) ans[i] = val[i + 1] * (i + 1);
	
	return ans;
}

template <typename T> Polynomial<T> Polynomial<T>::integral() const {
	int sz = size() + 1;

	Polynomial<T> ans;
	ans.resize(sz);

	ans[0] = 0;
	for (int i = 1; i < sz; i++) ans[i] = val[i - 1] / i;

	return ans;
}

//template <typename T> Polynomial<T> Polynomial<T>::inverse(int n) const;
//template <typename T> Polynomial<T> Polynomial<T>::log(int n) const;
//template <typename T> Polynomial<T> Polynomial<T>::exp(int n) const;
//template <typename T> Polynomial<T> Polynomial<T>::pow(int k, int n) const;

// --- old ---

/*
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
	 */
